#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include "src/ft_printf.h"

int main()
{
	const double	RENT = 3453;
	const int		RENT1 = 34533475;
	int	hour = 20;
	int	min = 15;
	int	precision = 2;
	int sec = 54;

	ft_printf("%sred\n", RED);
	ft_printf("%sgreen\n", GREEN);
	ft_printf("%syellow\n", YELLOW);
	ft_printf("%sblue\n", BLUE);
	ft_printf("%smagenta\n", MAGENTA);
	ft_printf("%scyan\n", CYAN);
	ft_printf("%swhite\n", WHITE);
	ft_printf("%snormal\n", NORMAL);

/*	printf("Origin :\n# = %#o, no = %o\n", 3453, 3453);	
	ft_printf("Ft :\n# = %#o, no = %o\n", 3453, 3453);	
	printf("Origin :\n# = %#O, no = %O\n", 3453, 3453);
	ft_printf("Ft :\n# = %#O, no = %O\n", 3453, 3453);
	printf("Origin :\n# = %#x, no = %x\n", 3453, 3453);
	ft_printf("Ft :\n# = %#x, no = %x\n", 3453, 3453);
	printf("Origin :\n# = %#X, no = %X\n", 3453, 3453);
	ft_printf("Ft :\n# = %#X, no = %X\n", 3453, 3453);*/

	ft_printf("%'d\n", RENT1);

	printf("%1$d:%2$.*3$d:%4$.*3$d\n", hour, min, precision, sec);

	printf("%sOrigin	unprint: %s\n", BLUE, "\\0, \\a, \\b, \\f, \\n, \\r, \\t, \\v, \\\", \\\\");
	ft_printf("%sFt	unprint: %rs\n", YELLOW, "\a, \b, \f, \n, \0, \r, \t, \v, \", \\");
	printf("%sOrigin	unprint: %s\n", BLUE, "\\0");
	ft_printf("%sFt	unprint: %rs\n", YELLOW, "\0");

	printf("%sOrigin	unprint: %s\n", BLUE, "");
	ft_printf("%sFt	unprint: %s\n", YELLOW, "");

//	ft_printf("Ft 'b':  # = %#b, no = %b\n", RENT1, RENT1);	
	printf("%sOrigin	'f':  # = %#.10f, no = %.10f\n", RED, RENT, RENT);
	ft_printf("%sFt	'f':  # = %#.10f, no = %.10f\n", RED, RENT, RENT);	
	printf("%sOrigin	'F':  # = %#.10F, no = %.10F\n", GREEN, RENT, RENT);
	ft_printf("%sFt	'F':  # = %#.10F, no = %.10F\n", GREEN, RENT, RENT);
	printf("%sOrigin	'g':  # = %#.10g, no = %.10g\n", YELLOW, RENT, RENT);
	ft_printf("%sFt	'g':  # = %#.10g, no = %.10g\n", YELLOW, RENT, RENT);	
	printf("%sOrigin	'G':  # = %#.10G, no = %.10G\n", BLUE, RENT, RENT);
	ft_printf("%sFt	'G':  # = %#.10G, no = %.10G\n", BLUE, RENT, RENT);	
	printf("%sOrigin	'e':  # = %#e, no = %e\n", MAGENTA, RENT, RENT);
	ft_printf("%sFt	'e':  # = %#e, no = %e\n", MAGENTA, RENT, RENT);	
	printf("%sOrigin	'E':  # = %#E, no = %E\n", CYAN, RENT, RENT);
	ft_printf("%sFt	'E':  # = %#E, no = %E\n", CYAN, RENT, RENT);	
	printf("%sOrigin	'a':  # = %#a, no = %a\n", WHITE, RENT, RENT);
	ft_printf("%sFt	'a':  # = %#a, no = %a\n", WHITE, RENT, RENT);	
	printf("%sOrigin	'A':  # = %#A, no = %A\n", GREEN, RENT, RENT);
	ft_printf("%sFt	'A':  # = %#A, no = %A\n", GREEN, RENT, RENT);
	printf("%sOrigin	'x':  # = %#x, no = %x\n", YELLOW, RENT1, RENT1);
	ft_printf("%sFt	'x':  # = %#x, no = %x\n", YELLOW, RENT1, RENT1);
	printf("%sOrigin	'X':  # = %#X, no = %X\n", NORMAL, RENT1, RENT1);
	ft_printf("%sFt	'X':  # = %#X, no = %X\n", NORMAL, RENT1, RENT1);


/*	printf("*%e*\n", RENT);
	printf("*%4.2f*\n", RENT);
	printf("*%3.1f*\n", RENT);
	printf("*%10.3f*\n", RENT);
	printf("*%10.3E*\n", RENT);
	printf("*%+5.2f*\n", RENT);

	printf("%x %X %#x\n", 31, 31, 31);
	printf("**%d**% d% d **\n", 42, 42, -42);
	printf("**%5d**%5.3d**%05d**%05.3d**\n", 6, 6, 6, 6);
	printf("\n");

	printf ("%zu\n %zu\n", sizeof(int64_t), sizeof(intmax_t)); 
*/
	while (1) sleep(120);
	return 0;
}
