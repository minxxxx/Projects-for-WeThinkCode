

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "glm/gtx/string_cast.hpp"

# define WIN_WIDTHI 1000
/* # define WIN_RATIOF (4.f / 3.f) */

/*
** CALCULATED MACROES
*/
# define WIN_WIDTHF ((float)WIN_WIDTHI)
# define WIN_HEIGHTF (WIN_WIDTHF / WIN_RATIOF)
# define WIN_HEIGHTI ROUND_FTOI(WIN_HEIGHTF)

struct                  s_vectorj4
{
	float               j[4];
};
typedef union           u_matrix4
{
	float               raw[16];
	struct s_vectorj4   i[4];
}                       t_matrix4;

#include <stdio.h>

void            m4_print(t_matrix4 mat)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (i % 4 == 3)
			printf("% 5.5f,\n", mat.raw[i]);
		else
			printf("% 5.5f, ", mat.raw[i]);
		i++;
	}
	return ;
}

t_matrix4 ComputeFOVProjection(float fov, float aspect, float nearDist, float farDist)
{
	t_matrix4	result =
	{
		{1.f, 0.f, 0.f, 0.f, 0.f, 1.f, 0.f, 0.f,
		 0.f, 0.f, 1.f, 0.f, 0.f, 0.f, 0.f, 1.f}
	};
	//
	// General form of the Projection Matrix
	//
	// uh = Cot( fov/2 ) == 1/Tan(fov/2)
	// uw / uh = 1/aspect
	//
	//   uw         0       0       0
	//    0        uh       0       0
	//    0         0      f/(f-n)  1
	//    0         0    -fn/(f-n)  0
	//
	// Make result to be identity first

	// check for bad parameters to avoid divide by zero:
	// if found, assert and return an identity matrix.
	if ( fov <= 0 || aspect == 0 )
	{
		// Assert( fov > 0 && aspect != 0 );
		// return;
	}

	
	float frustumDepth = farDist - nearDist;
	float oneOverDepth = 1 / frustumDepth;

	result.i[1].j[1] = 1 / tan(0.5f * fov);
	result.i[0].j[0] = 1 * result.i[1].j[1] / aspect;
	
	result.i[2].j[2] = -farDist * oneOverDepth;
	result.i[2].j[3] = (-farDist * nearDist) * oneOverDepth * 2;
	result.i[3].j[2] = -1;
	result.i[3].j[3] = 0;
	return (result);
}

int							main(void)
{
	//perspective (T const &fovy, T const &aspect, T const &near, T const &far)
//(45.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);
	glm::mat4 projection;	
	// glm::mat4 perspective(45.f, WIN_RATIOF, 0.1f, 100.f);

# define FOV 45.f
# define WIN_RATIOF (16.f / 9.f)
# define NEAR 0.1f
# define FAR 100.0f
	
	projection = glm::perspective(FOV, WIN_RATIOF, 0.1f, 100.0f);
	

	glm::mat4 transposed = transpose(projection);
	
	// m4_print(*reinterpret_cast<t_matrix4*>(&projection));
	m4_print(*reinterpret_cast<t_matrix4*>(&transposed));
	std::cout << glm::to_string(projection) << std::endl;
	m4_print(ComputeFOVProjection(FOV, WIN_RATIOF, NEAR, FAR));

	return 0;
}

// void Comion( Matrix& result, float fov, float aspect, float nearDist, float farDist, bool leftHanded /* = true */ )
// {
// 	//
// 	// General form of the Projection Matrix
// 	//
// 	// uh = Cot( fov/2 ) == 1/Tan(fov/2)
// 	// uw / uh = 1/aspect
// 	//
// 	//   uw         0       0       0
// 	//    0        uh       0       0
// 	//    0         0      f/(f-n)  1
// 	//    0         0    -fn/(f-n)  0
// 	//
// 	// Make result to be identity first

// 	// check for bad parameters to avoid divide by zero:
// 	// if found, assert and return an identity matrix.
// 	if ( fov <= 0 || aspect == 0 )
// 	{
// 		Assert( fov > 0 && aspect != 0 );
// 		return;
// 	}

// 	float frustumDepth = farDist - nearDist;
// 	float oneOverDepth = 1 / frustumDepth;

// 	result[1][1] = 1 / tan(0.5f * fov);
// 	result[0][0] = (leftHanded ? 1 : -1 ) * result[1][1] / aspect;
// 	result[2][2] = farDist * oneOverDepth;
// 	result[3][2] = (-farDist * nearDist) * oneOverDepth;
// 	result[2][3] = 1;
// 	result[3][3] = 0;
// }
