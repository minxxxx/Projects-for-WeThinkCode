/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 10:32:03 by khansman          #+#    #+#             */
/*   Updated: 2016/11/27 10:55:49 by smahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

/*
** ----------\
** Includes   |
** ----------/
*/

# ifdef __APPLE__
#  include <OpenGL/gl.h>
#  include <GLUT/glut.h>
# else
#  include <GL/gl.h>
#  include <GL/glut.h>
# endif

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <libc.h>
# include <signal.h>
# include <errno.h>
# include <ctype.h>
# include <termios.h>
# include <term.h>

# include "../libft/includes/libft.h"

/*
** # include "../minilibx_macos/mlx.h"
** # include "../minilibx_macos/mlx_int.h"
** # include "../minilibx_macos/mlx_new_window.h"
** # include "../minilibx_macos/mlx_opengl.h"
*/

/*
** ----------\
** Defines    |
** ----------/
*/

/*
** Keys
*/
# define KEY_ESC   27

/*
** Objects
*/
# define TYPE_VERTEX  1
# define TYPE_TEXTURE 2
# define TYPE_NORMAL  3
# define TYPE_FACE    4
# define TYPE_GROUP   5
# define TYPE_OBJNAME 6
# define TYPE_MTL     7
# define TYPE_MTLFILE 8
# define TYPE_SMOOTH  9
# define TYPE_PSPACE 10

# define F_VERTEX     0b00000001
# define F_TEXTURE    0b00000010
# define F_NORMAL     0b00000100

/*
** Other
*/
# define BASE_STR2 char *base = "0123456789abcdef";

# define L_DIFF    {6.0, 0.0, 0.0, 1.0}
# define LIGHT_POS {1.0, 1.0, 1.0, 0.0}
# define REN_LARGE (face->w) ? ((face->u) ? GL_POLYGON : GL_QUADS)
# define REN_TYPE  (REN_LARGE : GL_TRIANGLES)

# define VER(X, Y)  g_vertecies[face->X - 1]->Y
# define VER2(X)    g_vertecies[face->X - 1]
# define P_VERTEX   "vertex" : (vertex->type == TYPE_NORMAL) ? "normal"
# define P_VERTEX2  "texture" : (vertex->type == TYPE_PSPACE) ? "param space"
# define S_F_P2     else store_f_piece2

/*
** ----------\
** Structures |
** ----------/
*/

typedef struct		s_keyhook
{
	float			zoom;
	float			ratio;
	char			wire;
	float			eyex;
	float			eyey;
	float			eyez;
	float			centerx;
	float			centery;
	float			centerz;
	float			up_x;
	float			up_y;
	float			up_z;
}					t_keyhook;

typedef struct		s_vertex
{
	char		type;
	float		x;
	float		y;
	float		z;
	float		w;
}					t_vertex;

typedef struct		s_centerpoint
{
	t_vertex	min;
	t_vertex	max;
	t_vertex	center;
}					t_centerpoint;

typedef struct		s_vertex2
{
	char			type;
	float			u;
	float			v;
	float			w;
}					t_vertex2;

typedef struct		s_camera
{
	float			eye_x;
	float			eye_y;
	float			eye_z;
	float			center_x;
	float			center_y;
	float			center_z;
	float			up_x;
	float			up_y;
	float			up_z;
}					t_camera;

typedef struct		s_face
{
	char	type;
	int		x;
	int		y;
	int		z;
	int		w;
	int		u;
	int		v;
	int		o;
	int		p;
	int		t_x;
	int		t_y;
	int		t_z;
	int		t_w;
	int		t_u;
	int		t_v;
	int		t_o;
	int		t_p;
	int		n_x;
	int		n_y;
	int		n_z;
	int		n_w;
	int		n_u;
	int		n_v;
	int		n_o;
	int		n_p;
	char	set;
}					t_face;

typedef struct		s_matrix
{
	unsigned int	x;
	unsigned int	y;
	int				**matrix;
}					t_matrix;

typedef struct		s_mat_mul
{
	unsigned int	c;
	unsigned int	d;
	unsigned int	k;
	int				sum;
	struct s_matrix	multiply;
}					t_mat_mul;

/*
** ----------\
** Global     |
** ----------/
*/

# ifdef MAIN_FILE

float				g_red = 0.0;
float				g_blue = 0.0;
float				g_green = 0.0;
float				g_angle = 0;
float				g_lx = 0.0f;
float				g_lz = -1.0f;
float				g_x = 0.0f;
float				g_z = 5.0f;
float				g_delta_angle = 0.0f;
float				g_delta_move = 0;
t_list				*g_lst = NULL;
t_vertex			**g_vertecies = NULL;
int					g_num_vertex = 0;
t_vertex			*g_normals = NULL;
char				*g_mtl_file = NULL;
t_centerpoint		g_centerpoint;
t_keyhook			g_keyhook;
t_camera			g_camera;
int					g_xorigin = -1;
int					g_yorigin = -1;
# else

extern float		g_red;
extern float		g_blue;
extern float		g_green;
extern float		g_angle;
extern float		g_lx;
extern float		g_lz;
extern float		g_x;
extern float		g_z;
extern float		g_delta_angle;
extern float		g_delta_move;
extern t_list		*g_lst;
extern t_vertex		**g_vertecies;
extern int			g_num_vertex;
extern t_vertex		*g_normals;
extern char			*g_mtl_file;
extern t_centerpoint	g_centerpoint;
extern t_keyhook	g_keyhook;
extern t_camera		g_camera;
extern int			g_xorigin;
extern int			g_yorigin;
# endif

/*
** ----------\s
** Prototypes |
** ----------/
*/

/*
** centerpoint.c
*/
void				centerpoint(void);
/*
** change_size.c
*/
void				change_size(int w, int h);
/*
** count_elements.c
*/
void				compute_pos(float g_delta_move);
void				compute_dir(float g_delta_angle);
int					count_elements(char type);
/*
** exit_prog.c
*/
void				exit_prog(void);
/*
** error_quit.c
*/
void				error_quit(char *message);
/*
** free_lst.c
*/
int					free_lst(t_list *list);
int					safe_free_lst(t_list **list);
int					safe_free(void **item);
/*
** ft_atof.c
*/
float				ft_atof(const char *str);
/*
** ft_print_memory.c
*/
void				print_hex(unsigned char num);
void				ft_print_memory(const void *addr, size_t size);
/*
** init_glut.c
*/
void				init_glut(int ac, char **av);
/*
** matrix_add.c
*/
t_matrix			matrix_add(t_matrix first, t_matrix second);
/*
** matrix_create.c
*/
t_matrix			matrix_create(unsigned int x, unsigned int y);
/*
** matrix_destroy.c
*/
int					matrix_destroy(t_matrix matrix);
t_matrix			matrix_clear(t_matrix matrix);
/*
** matrix_identity.c
*/
t_matrix			matrix_identity(unsigned int size);
/*
** matrix_multiply.c
*/
t_matrix			matrix_multiply(t_matrix first, t_matrix second);
/*
** matrix_sub.c
*/
t_matrix			matrix_sub(t_matrix first, t_matrix second);
/*
** matrix_transpose.c
*/
t_matrix			matrix_transpose(t_matrix source);
/*
** normalise.c
*/
t_vertex			normalise_point(t_vertex *p1, t_vertex *p2, t_vertex *p3);
/*
** print_list.c
*/
void				print_vetex(t_vertex *vertex);
void				print_face(t_face *face);
void				print_list_details(t_list *pos, unsigned int k);
void				print_list(t_list *list);
/*
** process_normal_keys.c
*/
void				process_normal_keys(unsigned char key, int x, int y);
/*
** process_special_keys.c
*/
void				process_special_keys(int key, int x, int y);
void				press_key(int key, int xx, int yy);
void				release_key(int key, int x, int y);
/*
** mousehook.c
*/
void				mouse_button(int button, int state, int x, int y);
void				mouse_move(int x, int y);
/*
** read_obj.c
*/
int					read_obj(int ac, char **av);
/*
** render_scene.c
*/
void				render_scene(void);
void				init_gl(void);
/*
** set_arrays.c
*/
void				set_vertix_arr(void);
/*
** set_colour.c
*/
int					set_colour(float r, float g, float b);
/*
** store_face.c
*/
void				store_face(char *line, t_list **pos);
/*
** store_obj.c
*/
void				store_struct(void const *struc, size_t size, t_list **pos);
void				store_vertex(char *line, t_list **pos);
void				store_normal(char *line, t_list **pos);
void				store_texture(char *line, t_list **pos);
void				store_pspace(char *line, t_list **pos);
/*
** term.c
*/
int					cursor_do(int to_print);
void				unexpected_error(int signo);
void				listener(void);
/*
** trim.c
*/
char				*trim_start(char *str);
void				trim_end(char *str);
int					trim_tabs(char *line);
void				trim_str(char *str);
/*
** vertex_create.c
*/
t_vertex			vertex_create(float x, float y, float z, float w);

/*
**                                /----------\                                **
** ----- ----- ----- ----- ----- |  The End   | ----- ----- ----- ----- ----- **
**                                \----------/                                **
*/
#endif
