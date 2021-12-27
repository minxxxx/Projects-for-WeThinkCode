// --s
// S
// --p
// --d
// D
// --i
// --o
// --O
// --u
// --U
// --x
// --X
// --c
// C
// --%%
// --%#x %#o %#X %#O

#include "../ft_printf/ft_printf.h"
#include <stdio.h>

int		main(void)
{
	// printf("Basic test:\n");
	printf("\tHello world!\n");
	ft_printf("\tHello World!\n");
	printf("\t\176\n");
	ft_printf("\t\176\n");
	printf("\t\\\n");
	ft_printf("\t\\\n");

	printf("Conversion tests:\n");

	//PERCENT
	printf("    Percent\n");
	printf("\t%%\n");
	ft_printf("\t%%\n");
	printf("\tPercent of %%\n");
	ft_printf("\tPercent of %%\n");
	printf("\tDo you want 50%% of my money?\n");
	ft_printf("\tDo you want 50%% of my money?\n");
	printf("\tYou can either take 0%% or 100%% nothing else!\n");
	ft_printf("\tYou can either take 0%% or 100%% nothing else!\n");

	//CHAR
	printf("    Char\n");
	printf("\t%c\n", 'A');
	ft_printf("\t%c\n", 'A');
	printf("\tChar 1 - %c Char 2 - %c\n", 'A',  'B');
	ft_printf("\tChar 1 - %c Char 2 - %c\n", 'A',  'B');

	// //STRING
	printf("    String\n");
	printf("\t%s\n", "Hello world!");
	ft_printf("\t%s\n", "Hello world!");
	printf("\tWord 1 - %s Word 2 - %s\n", "Hello",  " world!");
	ft_printf("\tWord 1 - %s Word 2 - %s\n", "Hello",  " world!");

	// //DOUBLE
	printf("    Double\n");
	printf("\t%d\n", 10);
	ft_printf("\t%d\n", 10);
	printf("\tNumber - %i\n", 2147483647);
	ft_printf("\tNumber - %i\n", 2147483647);
	// Print throws error with -2147483647 as being a long...
	printf("\tNumber - %d\n", -2147483647);
	ft_printf("\tNumber - %d\n", -2147483647);
	printf("\tNum 1 - %d Num 2 - %d\n", 20, -30);
	ft_printf("\tNum 1 - %d Num 2 - %d\n", 20, -30);

	// //INT
	printf("    Int\n");
	printf("\t%i\n", 10);
	ft_printf("\t%i\n", 10);
	printf("\tNumber - %i\n", 2147483647);
	ft_printf("\tNumber - %i\n", 2147483647);
	// Print throws error with -2147483647 as being a long...
	printf("\tNumber - %i\n", -2147483647);
	ft_printf("\tNumber - %i\n", -2147483647);
	printf("\tNum 1 - %i Num 2 - %i\n", 20, -30);
	ft_printf("\tNum 1 - %i Num 2 - %i\n", 20, -30);

	// OCTAL
	printf("    Octal\n");
	printf("\t%o\n", 10);
	ft_printf("\t%o\n", 10);
	printf("\tNumber - %o\n", 42);
	ft_printf("\tNumber - %o\n", 42);
	printf("\tNum 1 - %o Num 2 - %o\n", 20, 30);
	ft_printf("\tNum 1 - %o Num 2 - %o\n", 20, 30);
	printf("\tNeg - %o\n", -42);
	ft_printf("\tNeg - %o\n", -42);
	printf("    Capital Octal\n");
	printf("\t%O\n", 10);
	ft_printf("\t%O\n", 10);
	printf("\tNumber - %O\n", 42);
	ft_printf("\tNumber - %o\n", 42);
	printf("\tNum 1 - %O Num 2 - %O\n", 20, 30);
	ft_printf("\tNum 1 - %O Num 2 - %O\n", 20, 30);
	printf("\tNeg - %O\n", -42);
	ft_printf("\tNeg - %O\n", -42);
	printf("    # Flag Octal\n");
	printf("\t%#O\n", 10);
	ft_printf("\t%#O\n", 10);
	printf("\tNumber - %#O\n", 42);
	ft_printf("\tNumber - %#o\n", 42);
	printf("\tNum 1 - %#O Num 2 - %#O\n", 20, 30); //FAIL
	ft_printf("\tNum 1 - %#O Num 2 - %#O\n", 20, 30);
	printf("\tNeg - %#O\n", -1);
	ft_printf("\tNeg - %#O\n", -1);

	// HEX
	printf("    Hexidecimal\n");
	printf("\t%x\n", 10);
	ft_printf("\t%x\n", 10);
	printf("\tNumber - %x\n", 42);
	ft_printf("\tNumber - %x\n", 42);
	printf("\tNum 1 - %x Num 2 - %x\n", 20, 30);
	ft_printf("\tNum 1 - %x Num 2 - %x\n", 20, 30);
	printf("\tNeg - %x\n", -42);
	ft_printf("\tNeg - %x\n", -42);
	printf("    Capital Hexidecimal\n");
	printf("\t%X\n", 10);
	ft_printf("\t%X\n", 10);
	printf("\tNumber - %X\n", 42);
	ft_printf("\tNumber - %X\n", 42);
	printf("\tNum 1 - %X Num 2 - %X\n", 20, 30);
	ft_printf("\tNum 1 - %X Num 2 - %X\n", 20, 30);
	printf("\tNeg - %X\n", -42);
	ft_printf("\tNeg - %X\n", -42);
	printf("    # Flag Hex\n");
	printf("\t%#x\n", 10);
	ft_printf("\t%#x\n", 10);
	printf("\tNumber - %#X\n", 42);
	ft_printf("\tNumber - %#X\n", 42);
	printf("\tNum 1 - %#x Num 2 - %#X\n", 20, 30);
	ft_printf("\tNum 1 - %#x Num 2 - %#X\n", 20, 30);
	printf("\tNeg - %#x\n", -42);
	ft_printf("\tNeg - %#x\n", -42);

	//Unsigned decimal integer
	printf("    Unsigned decimal integer\n");
	printf("\t%u\n", -10);
	ft_printf("\t%u\n", -10);
	printf("\tNumber - %u\n", 214);
	ft_printf("\tNumber - %u\n", 214);
	printf("\tNum 1 - %u Num 2 - %u\n", 420, -420);
	ft_printf("\tNum 1 - %u Num 2 - %u\n", 420, -420);
	printf("\t%U\n", -42);
	ft_printf("\t%U\n", -42);
	printf("\tNumber - %U\n", 42);
	ft_printf("\tNumber - %U\n", 42);

	// Pointer character sequence
	printf("    Pointer character sequence\n");
	char 	*test = "Hello world!\n";
	printf("\t%p\n", "Hello world!\n");
	ft_printf("\t%p\n", "Hello world!\n");
	printf("\tPoint 1 - %p Point 2 - %p\n", "Hello", "World!");
	ft_printf("\tPoint 1 - %p Point 2 - %p\n", "Hello", "World!");
	printf("\tVariable - %p\n", test);
	ft_printf("\tVariable - %p\n", test);


	// //FLOAT
	printf("    Float\n");
	printf("\t%f\n", 3.14);
	ft_printf("\t%f\n", 3.14);
	printf("\tChar 1 - %f Char 2 - %f\n", 3.14,  4.14);
	ft_printf("\tChar 1 - %f Char 2 - %f\n", 3.14,  4.14);

	// printf("Test cases: \n");
	// wchar_t		c = 128;
	// ft_printf("%c\n", L'\302');
	// printf("%C\n", c);
	// ft_printf("%s\n", L"Hello!\n");
	// printf("%S\n", L"Hello!\n");
	printf("This is school %30d\n", 42);
	ft_printf("This is school %30d\n", 42);
	printf("This is school %30o\n", 42);
	ft_printf("This is school %30o\n", 42);

	// printf("Closing program...\n");
	return (0);
}