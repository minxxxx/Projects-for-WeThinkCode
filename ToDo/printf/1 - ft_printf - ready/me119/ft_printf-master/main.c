#include <stdio.h>
#include <stddef.h>
#include <locale.h>
#include "src/ft_printf.h"
#include <limits.h>
#include <errno.h>

int	main(void)
{
	char *ptr_c = ft_strnew(0);
	int ptr_i = 43;
	long ptr_l = 874748;
	int nmb = 0;
	setlocale(LC_CTYPE, "");
//Chars
	printf("Char options:\n");
	char a = ' ';
	printf("\tOrigin:\t|%-2c|(%3d)\t|%-2c|(%3d)\t|%-2c|(%3d)\n", a, a, a+5,a+5,a+10,a+10);
	fflush(stdout);
	ft_printf("\tFt:\t|%-2c|(%3d)\t|%-2c|(%3d)\t|%-2c|(%3d)\n", a, a,a+5,a+5,a+10,a+10);
	a += 15;
	printf("\tOrigin:\t|%-2c|(%3d)\t|%-2c|(%3d)\t|%-2c|(%3d)\n", a, a, a+5,a+5,a+10,a+10);
	fflush(stdout);
	ft_printf("\tFt:\t|%-2c|(%3d)\t|%-2c|(%3d)\t|%-2c|(%3d)\n", a, a,a+5,a+5,a+10,a+10);
	a += 15;
	printf("\tOrigin:\t|%-2.3c|(%3d)\t|%-2.5c|(%3d)\t|%-2.0c|(%3d)\n", a, a, a+5,a+5,a+10,a+10);
	fflush(stdout);
	ft_printf("\tFt:\t|%-2.3c|(%3d)\t|%-2.5c|(%3d)\t|%-2.0c|(%3d)\n", a, a,a+5,a+5,a+10,a+10);
	a += 15;
	printf("\tOrigin:\t|%+3c|(%3d)\t|%+3c|(%3d)\t|%+c|(%3d)\n", a, a, a+5, a+5, a+10, a+10);
	fflush(stdout);
	ft_printf("\tFt:\t|%+3c|(%3d)\t|%+3c|(%3d)\t|%+c|(%3d)\n", a, a, a+5, a+5, a+10, a+10);
	a += 15;
	printf("\tOrigin:\t|%3.4c|(%3d)\t|%+3.4c|(%3d)\t|%.4c|(%3d)\n", a, a, a+5, a+5, a+10, a+10);
	fflush(stdout);
	ft_printf("\tFt:\t|%3.4c|(%3d)\t|%+3.4c|(%3d)\t|%.4c|(%3d)\n", a, a, a+5, a+5, a+10, a+10);
	printf("\tOrigin:\t|%-3y|(%3y)\t|%3Z|(%3Z)\t|%Q|(%3Q)\n");
	fflush(stdout);
	ft_printf("\tFt:\t|%-3y|(%3y)\t|%3Z|(%3Z)\t|%Q|(%3Q)\n");
	printf("\tOrigin:\t|%-3c|\t|%3c|\t|%c|\t|%-03c|\t|%03c|\t|%.c|\t|%.5c|\t|%.C|\t|%.5C|\n", 0,0,0,0,0,0,0,0,0);
	fflush(stdout);
	ft_printf("\tFt:\t|%-3c|\t|%3c|\t|%c|\t|%-03c|\t|%03c|\t|%.c|\t|%.5c|\t|%.C|\t|%.5C|\n", 0,0,0,0,0,0,0,0,0);
	printf("Unprintable:\n\tOrigin:\t|%-3c|\t|%3c|\t|%c|\t|%03c|\t|%.c|\t|%.C|\t|%.5C|\n", 7,7,7,7,7,7,7,7);
	fflush(stdout);
	ft_printf("\tFt:\t|%-3c|\t|%3c|\t|%c|\t|%03c|\t|%.c|\t|%.C|\t|%.5C|\n", 7,7,7,7,7,7,7,7);
//Percent
	printf("\nPercent:\n");
	printf("\tOrigin:\t|%-6%|   |%6%|   |%6.2%|   |%-06%|   |%-06.3%|\n");
	fflush(stdout);
	ft_printf("\tFt:\t|%-6%|   |%6%|   |%6.2%|   |%-06%|   |%-06.3%|\n");
//Strings
	printf("\nString options:\n");fflush(stdout);
	ft_printf("\tFt:\t%s\t%s\n","Ft Sample string",ft_strdup("It is me in your ft???"));
	printf("\tOrigin:\t|%s|\n", NULL);
	ft_printf("\tFt:\t|%s|\n", NULL);
	printf("\tOrigin:\t|%s|\n", "ПрэвЭд!");
	ft_printf("\tFt:\t|%s|\n", "ПрэвЭд!");
	printf("\tOrigin:\t|%s|\n","ç±³");fflush(stdout);
	ft_printf("\tFt:\t|%s|\n","ç±³");
//Presicions for strings
	printf("\nString options(field width, presicion and justification):\n");fflush(stdout);
	const char A[] = "this is tEEEEst!";
	printf("\tOrigin: |%5.3s|\t\t|%3.5s|\t|%7s|\t|%7.3s|\n",A, A,A,NULL);fflush(stdout);
	ft_printf("\tFt:     |%5.3s|\t\t|%3.5s|\t|%7s|\t|%7.3s|\n", A, A,A,NULL);
	printf("\tOrigin: |%07.5s|\t|%02.5s|\t|%.10s|\t\t|%.5s|\n",A,A,A, "");fflush(stdout);
	ft_printf("\tFt:     |%07.5s|\t|%02.5s|\t|%.10s|\t\t|%.5s|\n",A,A,A, "");
	printf("\tOrigin: |%-7.5s|\t|%-2.5s|\t|%-.10s|\t\t|%-.5s|\n",A,A,A, "");fflush(stdout);
	ft_printf("\tFt:     |%-7.5s|\t|%-2.5s|\t|%-.10s|\t\t|%-.5s|\n",A,A,A, "");
	printf("\tOrigin: |%-07.5s|\t|%-02.5s|\t|%-020s|\t|%-0.5s|\n",A,A,A, "");fflush(stdout);
	ft_printf("\tFt:     |%-07.5s|\t|%-02.5s|\t|%-020s|\t|%-0.5s|\n",A,A,A, "");
//Wide string and chars
	printf("\nWide string options:\n");
	printf("\tOrigin:\t|%S|\t|%S|\t|%C|\t|%S|\n",L"Wide sample string..",L"米",L'米',L"");fflush(stdout);
	ft_printf("\tFt:\t|%S|\t|%S|\t|%C|\t|%S|\n",L"Wide sample string..",L"米",L'米',L"");
	printf("\tOrigin:\t|%S|  |%S|\t|%S|\n",L"বিড়াল এবং খাওয়া তিমি ঘুঘু", L"合気道",L"ድመቶች ሰዎች አልወደውም.");fflush(stdout);
	ft_printf("\tFt:\t|%S|  |%S|\t|%S|\n",L"বিড়াল এবং খাওয়া তিমি ঘুঘু", L"合気道",L"ድመቶች ሰዎች አልወደውም.");

//Presicions for wide strings	
	printf("\nWide string options(field width, presicion and justification):\n");fflush(stdout);
	const wchar_t B[] = L"私は北京ダックを愛し";
	printf("\tOrigin: |%5.3S|\t|%3.5S|\t|%7S|\t|%7.3S|\n",B, B,B,L"");fflush(stdout);
	ft_printf("\tFt:     |%5.3S|\t|%3.5S|\t|%7S|\t|%7.3S|\n", B, B,B,L"");
	printf("\tOrigin: |%.3S|\t|%2.5S|\t|%.10S|\t\t|%.5S|\n",B,B,B, L"");fflush(stdout);
	ft_printf("\tFt:     |%07.5S|\t|%2.5S|\t|%.10S|\t\t|%.5S|\n",B,B,B, L"");
	printf("\tOrigin: |%-7.5S|\t|%-2.5S|\t|%-.10S|\t\t|%-.5S|\n",B,B,B, L"");fflush(stdout);
	ft_printf("\tFt:     |%-7.5S|\t|%-2.5S|\t|%-.10S|\t\t|%-.5S|\n",B,B,B, L"");
	printf("\tOrigin: |%-07.5S|\t|%-02.5S|\t|%-020S|\t|%-0.5S|\n",B,B,B, L"");fflush(stdout);
	ft_printf("\tFt:     |%-07.5S|\t|%-02.5S|\t|%-020S|\t|%-0.5S|\n",B,B,B, L"");
//Pointers
	printf("\nPointer options(field width, presicioin and justification):\n");
	printf("\tOrigin:\t|%.0p|\t\t|%6p|\t\t|%6.p|\t|%10.6p|\n", NULL,NULL,NULL,NULL);
	fflush(stdout);
	ft_printf("\tFt:\t|%.0p|\t\t|%6p|\t\t|%6.p|\t|%10.6p|\n", NULL,NULL,NULL,NULL);
	printf("\tOrigin:\t|%12p||%17p|\t|%-22p|\n", ptr_c, &ptr_i, &ptr_l);
	fflush(stdout);
	ft_printf("\tFt:\t|%12p||%17p|\t|%-22p|\n", ptr_c, &ptr_i, &ptr_l);
	printf("\tOrigin:\t|%.0p||%6p|\t|%6.p||%.20p|\n", &ptr_l, &ptr_l, &ptr_l,&ptr_l);
	fflush(stdout);
	ft_printf("\tFt:\t|%.0p||%6p|\t|%6.p||%.20p|\n\n", &ptr_l, &ptr_l, &ptr_l,&ptr_l);
//Binary
	printf("Binary options:(ft_printf only)\n");
	ft_printf("\t|%10d| in binary is |%032b|\n", 0,0);
	ft_printf("\t|%10d| in binary is |%032b|\n", -1,-1);
	ft_printf("\t|%10d| in binary is |%032b|\n", 15,15);
	ft_printf("\t|%10d| in binary is |%032b|\n", 5487,5487);
	ft_printf("\t|%10d| in binary is |%032b|\n\n", INT_MAX,INT_MAX);
//Numbers
	printf("Number options(field width and justification):\n");
	// i
	printf(" |i|\tOrigin:\t|%12i|\t|%12i|\t|%12i|\n", INT_MIN, INT_MAX,0);fflush(stdout);
	ft_printf("\tFt:\t|%12i|\t|%12i|\t|%12i|\n", INT_MIN, INT_MAX, 0);
	printf("\tOrigin:\t|%012i|\t|%-12i|\t|%012i|\n",-42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%012i|\t|%-12i|\t|%012i|\n",-42,42,42);
	// d
	printf(" |d|\tOrigin:\t|%12d|\t|%12d|\t|%12d|\n", INT_MIN, INT_MAX,0);fflush(stdout);
	ft_printf("\tFt:\t|%12d|\t|%12d|\t|%12d|\n", INT_MIN, INT_MAX, 0);
	printf("\tOrigin:\t|%012d|\t|%-12d|\t|%012d|\n",-42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%012d|\t|%-12d|\t|%012d|\n",-42,42,42);
	// D
	printf(" |D|\tOrigin:\t|%12D|\t|%12D|\t|%12D|\n", INT_MIN, INT_MAX,0);fflush(stdout);
	ft_printf("\tFt:\t|%12D|\t|%12D|\t|%12D|\n", INT_MIN, INT_MAX, 0);
	printf("\tOrigin:\t|%012D|\t|%-12D|\t|%012D|\n",-42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%012D|\t|%-12D|\t|%012D|\n",-42,42,42);
	// u
	printf(" |u|\tOrigin:\t|%12u|\t|%12u|\t|%12u|\n", INT_MIN, INT_MAX,0);fflush(stdout);
	ft_printf("\tFt:\t|%12u|\t|%12u|\t|%12u|\n", INT_MIN, INT_MAX, 0);
	printf("\tOrigin:\t|%012u|\t|%-12u|\t|%012u|\n",-42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%012u|\t|%-12u|\t|%012u|\n",-42,42,42);
	// U
	printf(" |U|\tOrigin:\t|%12U|\t|%12U|\t|%12U|\n", INT_MIN, INT_MAX,0);fflush(stdout);
	ft_printf("\tFt:\t|%12U|\t|%12U|\t|%12U|\n", INT_MIN, INT_MAX, 0);
	printf("\tOrigin:\t|%012U|\t|%-12U|\t|%012U|\n",-42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%012U|\t|%-12U|\t|%012U|\n",-42,42,42);
	// o
	printf(" |o|\tOrigin:\t|%12o|\t|%12o|\t|%12o|\n", INT_MIN, INT_MAX,0);fflush(stdout);
	ft_printf("\tFt:\t|%12o|\t|%12o|\t|%12o|\n", INT_MIN, INT_MAX, 0);
	printf("\tOrigin:\t|%012o|\t|%-12o|\t|%012o|\n",-42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%012o|\t|%-12o|\t|%012o|\n",-42,42,42);
	// O
	printf(" |O|\tOrigin:\t|%12O|\t|%12O|\t|%12O|\n", INT_MIN, INT_MAX,0);fflush(stdout);
	ft_printf("\tFt:\t|%12O|\t|%12O|\t|%12O|\n", INT_MIN, INT_MAX, 0);
	printf("\tOrigin:\t|%012O|\t|%-12O|\t|%012O|\n",-42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%012O|\t|%-12O|\t|%012O|\n",-42,42,42);
	// x
	printf(" |x|\tOrigin:\t|%12x|\t|%12x|\t|%12x|\n", INT_MIN, INT_MAX,0);fflush(stdout);
	ft_printf("\tFt:\t|%12x|\t|%12x|\t|%12x|\n", INT_MIN, INT_MAX, 0);
	printf("\tOrigin:\t|%012x|\t|%-12x|\t|%012x|\n",-42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%012x|\t|%-12x|\t|%012x|\n",-42,42,42);
	// X
	printf(" |X|\tOrigin:\t|%12X|\t|%12X|\t|%12X|\n", INT_MIN, INT_MAX,0);fflush(stdout);
	ft_printf("\tFt:\t|%12X|\t|%12X|\t|%12X|\n", INT_MIN, INT_MAX, 0);
	printf("\tOrigin:\t|%012X|\t|%-12X|\t|%012X|\n",-42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%012X|\t|%-12X|\t|%012X|\n",-42,42,42);
//Presicions for numbers
	printf("\nNumber options(field width, presicion and -):\n");	
	// i
	nmb = 4235;
	printf(" |i|\tOrigin:\t|%1.1i|\t\t|%5.1i|\t\t|%5.3i|\t\t|%1.5i|\n",nmb, nmb, nmb, nmb);fflush(stdout);
	ft_printf("\tFt:\t|%1.1i|\t\t|%5.1i|\t\t|%5.3i|\t\t|%1.5i|\n",nmb, nmb, nmb, nmb);
	printf("\tOrigin:\t|%1.1i|\t\t|%5.1i|\t\t|%5.3i|\t\t|%1.5i|\n",-nmb, -nmb, -nmb, -nmb);fflush(stdout);
	ft_printf("\tFt:\t|%1.1i|\t\t|%5.1i|\t\t|%5.3i|\t\t|%1.5i|\n",-nmb, -nmb, -nmb, -nmb);
	printf("\tOrigin:\t|%3.5i|\t\t|%3.5i|\t|%07.5i|\t|%07.5i|\n",nmb, -nmb, nmb, -nmb);fflush(stdout);
	ft_printf("\tFt:\t|%3.5i|\t\t|%3.5i|\t|%07.5i|\t|%07.5i|\n",nmb, -nmb, nmb, -nmb);
	printf("\tOrigin:\t|%8.5i|\t|%8.5i|\t|%08i|\t|%08i|\n",nmb, -nmb, nmb, -nmb);fflush(stdout);
	ft_printf("\tFt:\t|%8.5i|\t|%8.5i|\t|%08i|\t|%08i|\n",nmb, -nmb, nmb, -nmb);
	printf("\tOrigin:\t|%-.10i|\t|%.-10i|\t|%-15.-10i|\t|%15.-10i|\n",42,42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%-.10i|\t|%.-10i|\t|%-15.-10i|\t|%15.-10i|\n",42,42,42,42);
	printf("\tOrigin:\t|%-12.8.5i|\t|%12.-8.5i|\t|%-12.-8.5i|\t|%-12.-8.-5i|\n",42,42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%-12.8.5i|\t|%12.-8.5i|\t|%-12.-8.5i|\t|%-12.-8.-5i|\n",42,42,42,42);
	printf("\tOrigin:\t|%7-.5i|\t|%-7-.5i|\t|%7.5-i|\t|%-7.-5-i|\n", 42,42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%7-.5i|\t|%-7-.5i|\t|%7.5-i|\t|%-7.-5-i|\n", 42,42,42,42);
	printf("\tOrigin:\t|%12.8.10.6i|\t|%20.8.-12.6i|\t|%20.8.12.-6i||%20.-5.12.3i|\t|%10.8.12.6-i|\n",42,42,42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%12.8.10.6i|\t|%20.8.-12.6i|\t|%20.8.12.-6i||%20.-5.12.3i|\t|%10.8.12.6-i|\n",42,42,42,42,42);
	printf("\tOrigin:\t|%.i %.0i %0.i %0.0i|\t\t|%i %.2i %2.i %2.2i|\n",0,0,0,0,0,0,0,0);fflush(stdout);
	ft_printf("\tFt:\t|%.i %.0i %0.i %0.0i|\t\t|%i %.2i %2.i %2.2i|\n",0,0,0,0,0,0,0,0);
	// d
	printf(" |d|\tOrigin:\t|%1.1d|\t\t|%5.1d|\t\t|%5.3d|\t\t|%1.5d|\n",nmb, nmb, nmb, nmb);fflush(stdout);
	ft_printf("\tFt:\t|%1.1d|\t\t|%5.1d|\t\t|%5.3d|\t\t|%1.5d|\n",nmb, nmb, nmb, nmb);
	printf("\tOrigin:\t|%1.1d|\t\t|%5.1d|\t\t|%5.3d|\t\t|%1.5d|\n",-nmb, -nmb, -nmb, -nmb);fflush(stdout);
	ft_printf("\tFt:\t|%1.1d|\t\t|%5.1d|\t\t|%5.3d|\t\t|%1.5d|\n",-nmb, -nmb, -nmb, -nmb);
	printf("\tOrigin:\t|%3.5d|\t\t|%3.5d|\t|%07.5d|\t|%07.5d|\n",nmb, -nmb, nmb, -nmb);fflush(stdout);
	ft_printf("\tFt:\t|%3.5d|\t\t|%3.5d|\t|%07.5d|\t|%07.5d|\n",nmb, -nmb, nmb, -nmb);
	printf("\tOrigin:\t|%8.5d|\t|%8.5d|\t|%08d|\t|%08d|\n",nmb, -nmb, nmb, -nmb);fflush(stdout);
	ft_printf("\tFt:\t|%8.5d|\t|%8.5d|\t|%08d|\t|%08d|\n",nmb, -nmb, nmb, -nmb);
	printf("\tOrigin:\t|%-.10d|\t|%.-10d|\t|%-15.-10d|\t|%15.-10d|\n",42,42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%-.10d|\t|%.-10d|\t|%-15.-10d|\t|%15.-10d|\n",42,42,42,42);
	printf("\tOrigin:\t|%-12.8.5d|\t|%12.-8.5d|\t|%-12.-8.5d|\t|%-12.-8.-5d|\n",42,42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%-12.8.5d|\t|%12.-8.5d|\t|%-12.-8.5d|\t|%-12.-8.-5d|\n",42,42,42,42);
	printf("\tOrigin:\t|%7-.5d|\t|%-7-.5d|\t|%7.5-d|\t|%-7.-5-d|\n", 42,42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%7-.5d|\t|%-7-.5d|\t|%7.5-d|\t|%-7.-5-d|\n", 42,42,42,42);
	printf("\tOrigin:\t|%12.8.10.6d|\t|%20.8.-12.6d|\t|%20.8.12.-6d||%20.-5.12.3d|\t|%10.8.12.6-d|\n",42,42,42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%12.8.10.6d|\t|%20.8.-12.6d|\t|%20.8.12.-6d||%20.-5.12.3d|\t|%10.8.12.6-d|\n",42,42,42,42,42);
	printf("\tOrigin:\t|%.d %.0d %0.d %0.0d|\t\t|%d %.2d %2.d %2.2d|\n",0,0,0,0,0,0,0,0);fflush(stdout);
	ft_printf("\tFt:\t|%.d %.0d %0.d %0.0d|\t\t|%d %.2d %2.d %2.2d|\n",0,0,0,0,0,0,0,0);
	// D
	printf(" |D|\tOrigin:\t|%1.1D|\t\t|%5.1D|\t\t|%5.3D|\t\t|%1.5D|\n",nmb, nmb, nmb, nmb);fflush(stdout);
	ft_printf("\tFt:\t|%1.1D|\t\t|%5.1D|\t\t|%5.3D|\t\t|%1.5D|\n",nmb, nmb, nmb, nmb);
	printf("\tOrigin:\t|%1.1D|\t|%5.1D|\t|%5.3D|\t|%1.5D|\n",-nmb, -nmb, -nmb, -nmb);fflush(stdout);
	ft_printf("\tFt:\t|%1.1D|\t|%5.1D|\t|%5.3D|\t|%1.5D|\n",-nmb, -nmb, -nmb, -nmb);
	printf("\tOrigin:\t|%3.5D|\t\t|%3.5D|\t|%07.5D|\t|%07.5D|\n",nmb, -nmb, nmb, -nmb);fflush(stdout);
	ft_printf("\tFt:\t|%3.5D|\t\t|%3.5D|\t|%07.5D|\t|%07.5D|\n",nmb, -nmb, nmb, -nmb);
	printf("\tOrigin:\t|%8.5D|\t|%8.5D|\t|%08D|\t|%08D|\n",nmb, -nmb, nmb, -nmb);fflush(stdout);
	ft_printf("\tFt:\t|%8.5D|\t|%8.5D|\t|%08D|\t|%08D|\n",nmb, -nmb, nmb, -nmb);
	printf("\tOrigin:\t|%-.10D|\t|%.-10D|\t|%-15.-10D|\t|%15.-10D|\n",42,42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%-.10D|\t|%.-10D|\t|%-15.-10D|\t|%15.-10D|\n",42,42,42,42);
	printf("\tOrigin:\t|%-12.8.5D|\t|%12.-8.5D|\t|%-12.-8.5D|\t|%-12.-8.-5D|\n",42,42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%-12.8.5D|\t|%12.-8.5D|\t|%-12.-8.5D|\t|%-12.-8.-5D|\n",42,42,42,42);
	printf("\tOrigin:\t|%7-.5D|\t|%-7-.5D|\t|%7.5-D|\t|%-7.-5-D|\n", 42,42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%7-.5D|\t|%-7-.5D|\t|%7.5-D|\t|%-7.-5-D|\n", 42,42,42,42);
	printf("\tOrigin:\t|%12.8.10.6D|\t|%20.8.-12.6D|\t|%20.8.12.-6D||%20.-5.12.3D|\t|%10.8.12.6-D|\n",42,42,42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%12.8.10.6D|\t|%20.8.-12.6D|\t|%20.8.12.-6D||%20.-5.12.3D|\t|%10.8.12.6-D|\n",42,42,42,42,42);
	printf("\tOrigin:\t|%.D %.0D %0.D %0.0D|\t\t|%D %.2D %2.D %2.2D|\n",0,0,0,0,0,0,0,0);fflush(stdout);
	ft_printf("\tFt:\t|%.D %.0D %0.D %0.0D|\t\t|%D %.2D %2.D %2.2D|\n",0,0,0,0,0,0,0,0);
	// u
	printf(" |u|\tOrigin:\t|%1.1u|\t\t|%5.1u|\t\t|%5.3u|\t\t|%1.5u|\n",nmb, nmb, nmb, nmb);fflush(stdout);
	ft_printf("\tFt:\t|%1.1u|\t\t|%5.1u|\t\t|%5.3u|\t\t|%1.5u|\n",nmb, nmb, nmb, nmb);
	printf("\tOrigin:\t|%1.1u|\t|%5.1u|\t|%5.3u|\t|%1.5u|\n",-nmb, -nmb, -nmb, -nmb);fflush(stdout);
	ft_printf("\tFt:\t|%1.1u|\t|%5.1u|\t|%5.3u|\t|%1.5u|\n",-nmb, -nmb, -nmb, -nmb);
	printf("\tOrigin:\t|%3.5u|\t\t|%3.5u|\t|%07.5u|\t|%07.5u|\n",nmb, -nmb, nmb, -nmb);fflush(stdout);
	ft_printf("\tFt:\t|%3.5u|\t\t|%3.5u|\t|%07.5u|\t|%07.5u|\n",nmb, -nmb, nmb, -nmb);
	printf("\tOrigin:\t|%8.5u|\t|%8.5u|\t|%08u|\t|%08u|\n",nmb, -nmb, nmb, -nmb);fflush(stdout);
	ft_printf("\tFt:\t|%8.5u|\t|%8.5u|\t|%08u|\t|%08u|\n",nmb, -nmb, nmb, -nmb);
	printf("\tOrigin:\t|%-.10u|\t|%.-10u|\t|%-15.-10u|\t|%15.-10u|\n",42,42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%-.10u|\t|%.-10u|\t|%-15.-10u|\t|%15.-10u|\n",42,42,42,42);
	printf("\tOrigin:\t|%-12.8.5u|\t|%12.-8.5u|\t|%-12.-8.5u|\t|%-12.-8.-5u|\n",42,42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%-12.8.5u|\t|%12.-8.5u|\t|%-12.-8.5u|\t|%-12.-8.-5u|\n",42,42,42,42);
	printf("\tOrigin:\t|%7-.5u|\t|%-7-.5u|\t|%7.5-u|\t|%-7.-5-u|\n", 42,42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%7-.5u|\t|%-7-.5u|\t|%7.5-u|\t|%-7.-5-u|\n", 42,42,42,42);
	printf("\tOrigin:\t|%12.8.10.6u|\t|%20.8.-12.6u|\t|%20.8.12.-6u||%20.-5.12.3u|\t|%10.8.12.6-u|\n",42,42,42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%12.8.10.6u|\t|%20.8.-12.6u|\t|%20.8.12.-6u||%20.-5.12.3u|\t|%10.8.12.6-u|\n",42,42,42,42,42);
	printf("\tOrigin:\t|%.u %.0u %0.u %0.0u|\t\t|%u %.2u %2.u %2.2u|\n",0,0,0,0,0,0,0,0);fflush(stdout);
	ft_printf("\tFt:\t|%.u %.0u %0.u %0.0u|\t\t|%u %.2u %2.u %2.2u|\n",0,0,0,0,0,0,0,0);
	// U
	printf(" |U|\tOrigin:\t|%1.1U|\t\t|%5.1U|\t\t|%5.3U|\t\t|%1.5U|\n",nmb, nmb, nmb, nmb);fflush(stdout);
	ft_printf("\tFt:\t|%1.1U|\t\t|%5.1U|\t\t|%5.3U|\t\t|%1.5U|\n",nmb, nmb, nmb, nmb);
	printf("\tOrigin:\t|%1.1U|\t|%5.1U|\t|%5.3U|\t|%1.5U|\n",-nmb, -nmb, -nmb, -nmb);fflush(stdout);
	ft_printf("\tFt:\t|%1.1U|\t|%5.1U|\t|%5.3U|\t|%1.5U|\n",-nmb, -nmb, -nmb, -nmb);
	printf("\tOrigin:\t|%3.5U|\t\t|%3.5U|\t|%07.5U|\t|%07.5U|\n",nmb, -nmb, nmb, -nmb);fflush(stdout);
	ft_printf("\tFt:\t|%3.5U|\t\t|%3.5U|\t|%07.5U|\t|%07.5U|\n",nmb, -nmb, nmb, -nmb);
	printf("\tOrigin:\t|%8.5U|\t|%8.5U|\t|%08U|\t|%08U|\n",nmb, -nmb, nmb, -nmb);fflush(stdout);
	ft_printf("\tFt:\t|%8.5U|\t|%8.5U|\t|%08U|\t|%08U|\n",nmb, -nmb, nmb, -nmb);
	printf("\tOrigin:\t|%-.10U|\t|%.-10U|\t|%-15.-10U|\t|%15.-10U|\n",42,42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%-.10U|\t|%.-10U|\t|%-15.-10U|\t|%15.-10U|\n",42,42,42,42);
	printf("\tOrigin:\t|%-12.8.5U|\t|%12.-8.5U|\t|%-12.-8.5U|\t|%-12.-8.-5U|\n",42,42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%-12.8.5U|\t|%12.-8.5U|\t|%-12.-8.5U|\t|%-12.-8.-5U|\n",42,42,42,42);
	printf("\tOrigin:\t|%7-.5U|\t|%-7-.5U|\t|%7.5-U|\t|%-7.-5-U|\n", 42,42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%7-.5U|\t|%-7-.5U|\t|%7.5-U|\t|%-7.-5-U|\n", 42,42,42,42);
	printf("\tOrigin:\t|%12.8.10.6U|\t|%20.8.-12.6U|\t|%20.8.12.-6U||%20.-5.12.3U|\t|%10.8.12.6-U|\n",42,42,42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%12.8.10.6U|\t|%20.8.-12.6U|\t|%20.8.12.-6U||%20.-5.12.3U|\t|%10.8.12.6-U|\n",42,42,42,42,42);
	printf("\tOrigin:\t|%.U %.0U %0.U %0.0U|\t\t|%U %.2U %2.U %2.2U|\n",0,0,0,0,0,0,0,0);fflush(stdout);
	ft_printf("\tFt:\t|%.U %.0U %0.U %0.0U|\t\t|%U %.2U %2.U %2.2U|\n",0,0,0,0,0,0,0,0);
	// o
	printf(" |o|\tOrigin:\t|%1.1o|\t\t|%5.1o|\t\t|%5.3o|\t\t|%1.5o|\n",nmb, nmb, nmb, nmb);fflush(stdout);
	ft_printf("\tFt:\t|%1.1o|\t\t|%5.1o|\t\t|%5.3o|\t\t|%1.5o|\n",nmb, nmb, nmb, nmb);
	printf("\tOrigin:\t|%1.1o|\t|%5.1o|\t|%5.3o|\t|%1.5o|\n",-nmb, -nmb, -nmb, -nmb);fflush(stdout);
	ft_printf("\tFt:\t|%1.1o|\t|%5.1o|\t|%5.3o|\t|%1.5o|\n",-nmb, -nmb, -nmb, -nmb);
	printf("\tOrigin:\t|%3.5o|\t\t|%3.5o|\t|%07.5o|\t|%07.5o|\n",nmb, -nmb, nmb, -nmb);fflush(stdout);
	ft_printf("\tFt:\t|%3.5o|\t\t|%3.5o|\t|%07.5o|\t|%07.5o|\n",nmb, -nmb, nmb, -nmb);
	printf("\tOrigin:\t|%8.5o|\t|%8.5o|\t|%08o|\t|%08o|\n",nmb, -nmb, nmb, -nmb);fflush(stdout);
	ft_printf("\tFt:\t|%8.5o|\t|%8.5o|\t|%08o|\t|%08o|\n",nmb, -nmb, nmb, -nmb);
	printf("\tOrigin:\t|%-.10o|\t|%.-10o|\t|%-15.-10o|\t|%15.-10o|\n",42,42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%-.10o|\t|%.-10o|\t|%-15.-10o|\t|%15.-10o|\n",42,42,42,42);
	printf("\tOrigin:\t|%-12.8.5o|\t|%12.-8.5o|\t|%-12.-8.5o|\t|%-12.-8.-5o|\n",42,42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%-12.8.5o|\t|%12.-8.5o|\t|%-12.-8.5o|\t|%-12.-8.-5o|\n",42,42,42,42);
	printf("\tOrigin:\t|%7-.5o|\t|%-7-.5o|\t|%7.5-o|\t|%-7.-5-o|\n", 42,42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%7-.5o|\t|%-7-.5o|\t|%7.5-o|\t|%-7.-5-o|\n", 42,42,42,42);
	printf("\tOrigin:\t|%12.8.10.6o|\t|%20.8.-12.6o|\t|%20.8.12.-6o||%20.-5.12.3o|\t|%10.8.12.6-o|\n",42,42,42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%12.8.10.6o|\t|%20.8.-12.6o|\t|%20.8.12.-6o||%20.-5.12.3o|\t|%10.8.12.6-o|\n",42,42,42,42,42);	
	printf("\tOrigin:\t|%.o %.0o %0.o %0.0o|\t\t|%o %.2o %2.o %2.2o|\n",0,0,0,0,0,0,0,0);fflush(stdout);
	ft_printf("\tFt:\t|%.o %.0o %0.o %0.0o|\t\t|%o %.2o %2.o %2.2o|\n",0,0,0,0,0,0,0,0);
	// O
	printf(" |O|\tOrigin:\t|%1.1O|\t\t|%5.1O|\t\t|%5.3O|\t\t|%1.5O|\n",nmb, nmb, nmb, nmb);fflush(stdout);
	ft_printf("\tFt:\t|%1.1O|\t\t|%5.1O|\t\t|%5.3O|\t\t|%1.5O|\n",nmb, nmb, nmb, nmb);
	printf("\tOrigin:\t|%1.1O|\t|%5.1O|\t|%5.3O|\t|%1.5O|\n",-nmb, -nmb, -nmb, -nmb);fflush(stdout);
	ft_printf("\tFt:\t|%1.1O|\t|%5.1O|\t|%5.3O|\t|%1.5O|\n",-nmb, -nmb, -nmb, -nmb);
	printf("\tOrigin:\t|%3.5O|\t\t|%3.5O|\t|%07.5O|\t|%07.5O|\n",nmb, -nmb, nmb, -nmb);fflush(stdout);
	ft_printf("\tFt:\t|%3.5O|\t\t|%3.5O|\t|%07.5O|\t|%07.5O|\n",nmb, -nmb, nmb, -nmb);
	printf("\tOrigin:\t|%8.5O|\t|%8.5O|\t|%08O|\t|%08O|\n",nmb, -nmb, nmb, -nmb);fflush(stdout);
	ft_printf("\tFt:\t|%8.5O|\t|%8.5O|\t|%08O|\t|%08O|\n",nmb, -nmb, nmb, -nmb);
	printf("\tOrigin:\t|%-.10O|\t|%.-10O|\t|%-15.-10O|\t|%15.-10O|\n",42,42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%-.10O|\t|%.-10O|\t|%-15.-10O|\t|%15.-10O|\n",42,42,42,42);
	printf("\tOrigin:\t|%-12.8.5O|\t|%12.-8.5O|\t|%-12.-8.5O|\t|%-12.-8.-5O|\n",42,42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%-12.8.5O|\t|%12.-8.5O|\t|%-12.-8.5O|\t|%-12.-8.-5O|\n",42,42,42,42);
	printf("\tOrigin:\t|%7-.5O|\t|%-7-.5O|\t|%7.5-O|\t|%-7.-5-O|\n", 42,42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%7-.5O|\t|%-7-.5O|\t|%7.5-O|\t|%-7.-5-O|\n", 42,42,42,42);
	printf("\tOrigin:\t|%12.8.10.6O|\t|%20.8.-12.6O|\t|%20.8.12.-6O||%20.-5.12.3O|\t|%10.8.12.6-O|\n",42,42,42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%12.8.10.6O|\t|%20.8.-12.6O|\t|%20.8.12.-6O||%20.-5.12.3O|\t|%10.8.12.6-O|\n",42,42,42,42,42);	
	printf("\tOrigin:\t|%.O %.0O %0.O %0.0O|\t\t|%O %.2O %2.O %2.2O|\n",0,0,0,0,0,0,0,0);fflush(stdout);
	ft_printf("\tFt:\t|%.O %.0O %0.O %0.0O|\t\t|%O %.2O %2.O %2.2O|\n",0,0,0,0,0,0,0,0);
	// x
	printf(" |x|\tOrigin:\t|%1.1x|\t\t|%5.1x|\t\t|%5.3x|\t\t|%1.5x|\n",nmb, nmb, nmb, nmb);fflush(stdout);
	ft_printf("\tFt:\t|%1.1x|\t\t|%5.1x|\t\t|%5.3x|\t\t|%1.5x|\n",nmb, nmb, nmb, nmb);
	printf("\tOrigin:\t|%1.1x|\t|%5.1x|\t|%5.3x|\t|%1.5x|\n",-nmb, -nmb, -nmb, -nmb);fflush(stdout);
	ft_printf("\tFt:\t|%1.1x|\t|%5.1x|\t|%5.3x|\t|%1.5x|\n",-nmb, -nmb, -nmb, -nmb);
	printf("\tOrigin:\t|%3.5x|\t\t|%3.5x|\t|%07.5x|\t|%07.5x|\n",nmb, -nmb, nmb, -nmb);fflush(stdout);
	ft_printf("\tFt:\t|%3.5x|\t\t|%3.5x|\t|%07.5x|\t|%07.5x|\n",nmb, -nmb, nmb, -nmb);
	printf("\tOrigin:\t|%8.5x|\t|%8.5x|\t|%08x|\t|%08x|\n",nmb, -nmb, nmb, -nmb);fflush(stdout);
	ft_printf("\tFt:\t|%8.5x|\t|%8.5x|\t|%08x|\t|%08x|\n",nmb, -nmb, nmb, -nmb);
	printf("\tOrigin:\t|%-.10x|\t|%.-10x|\t|%-15.-10x|\t|%15.-10x|\n",42,42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%-.10x|\t|%.-10x|\t|%-15.-10x|\t|%15.-10x|\n",42,42,42,42);
	printf("\tOrigin:\t|%-12.8.5x|\t|%12.-8.5x|\t|%-12.-8.5x|\t|%-12.-8.-5x|\n",42,42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%-12.8.5x|\t|%12.-8.5x|\t|%-12.-8.5x|\t|%-12.-8.-5x|\n",42,42,42,42);
	printf("\tOrigin:\t|%7-.5x|\t|%-7-.5x|\t|%7.5-x|\t|%-7.-5-x|\n", 42,42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%7-.5x|\t|%-7-.5x|\t|%7.5-x|\t|%-7.-5-x|\n", 42,42,42,42);
	printf("\tOrigin:\t|%12.8.10.6x|\t|%20.8.-12.6x|\t|%20.8.12.-6x||%20.-5.12.3x|\t|%10.8.12.6-x|\n",42,42,42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%12.8.10.6x|\t|%20.8.-12.6x|\t|%20.8.12.-6x||%20.-5.12.3x|\t|%10.8.12.6-x|\n",42,42,42,42,42);
	printf("\tOrigin:\t|%.x %.0x %0.x %0.0x|\t\t|%x %.2x %2.x %2.2x|\n",0,0,0,0,0,0,0,0);fflush(stdout);
	ft_printf("\tFt:\t|%.x %.0x %0.x %0.0x|\t\t|%x %.2x %2.x %2.2x|\n",0,0,0,0,0,0,0,0);
	// X
	printf(" |X|\tOrigin:\t|%1.1X|\t\t|%5.1X|\t\t|%5.3X|\t\t|%1.5X|\n",nmb, nmb, nmb, nmb);fflush(stdout);
	ft_printf("\tFt:\t|%1.1X|\t\t|%5.1X|\t\t|%5.3X|\t\t|%1.5X|\n",nmb, nmb, nmb, nmb);
	printf("\tOrigin:\t|%1.1X|\t|%5.1X|\t|%5.3X|\t|%1.5X|\n",-nmb, -nmb, -nmb, -nmb);fflush(stdout);
	ft_printf("\tFt:\t|%1.1X|\t|%5.1X|\t|%5.3X|\t|%1.5X|\n",-nmb, -nmb, -nmb, -nmb);
	printf("\tOrigin:\t|%3.5X|\t\t|%3.5X|\t|%07.5X|\t|%07.5X|\n",nmb, -nmb, nmb, -nmb);fflush(stdout);
	ft_printf("\tFt:\t|%3.5X|\t\t|%3.5X|\t|%07.5X|\t|%07.5X|\n",nmb, -nmb, nmb, -nmb);
	printf("\tOrigin:\t|%8.5X|\t|%8.5X|\t|%08X|\t|%08X|\n",nmb, -nmb, nmb, -nmb);fflush(stdout);
	ft_printf("\tFt:\t|%8.5X|\t|%8.5X|\t|%08X|\t|%08X|\n",nmb, -nmb, nmb, -nmb);
	printf("\tOrigin:\t|%-.10X|\t|%.-10X|\t|%-15.-10X|\t|%15.-10X|\n",42,42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%-.10X|\t|%.-10X|\t|%-15.-10X|\t|%15.-10X|\n",42,42,42,42);
	printf("\tOrigin:\t|%-12.8.5X|\t|%12.-8.5X|\t|%-12.-8.5X|\t|%-12.-8.-5X|\n",42,42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%-12.8.5X|\t|%12.-8.5X|\t|%-12.-8.5X|\t|%-12.-8.-5X|\n",42,42,42,42);
	printf("\tOrigin:\t|%7-.5X|\t|%-7-.5X|\t|%7.5-X|\t|%-7.-5-X|\n", 42,42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%7-.5X|\t|%-7-.5X|\t|%7.5-X|\t|%-7.-5-X|\n", 42,42,42,42);
	printf("\tOrigin:\t|%12.8.10.6X|\t|%20.8.-12.6X|\t|%20.8.12.-6X||%20.-5.12.3X|\t|%10.8.12.6-X|\n",42,42,42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%12.8.10.6X|\t|%20.8.-12.6X|\t|%20.8.12.-6X||%20.-5.12.3X|\t|%10.8.12.6-X|\n",42,42,42,42,42);
	printf("\tOrigin:\t|%.X %.0X %0.X %0.0X|\t\t|%X %.2X %2.X %2.2X|\n",0,0,0,0,0,0,0,0);fflush(stdout);
	ft_printf("\tFt:\t|%.X %.0X %0.X %0.0X|\t\t|%X %.2X %2.X %2.2X|\n",0,0,0,0,0,0,0,0);
//Flag + - 0 and space
	nmb = 42;
	printf("\nNumber options(field width, justification, +, space and 0):\n");	
	printf("  |i|\tOrigin:\t|%-11-0i|\t|%-0+11i|\t|%11+i|\t|%-11+i|\t|%0 i|\n",nmb,nmb,nmb,nmb,nmb);fflush(stdout);
	ft_printf("\tFt:\t|%-11-0i|\t|%-0+11i|\t|%11+i|\t|%-11+i|\t|%0 i|\n",nmb,nmb,nmb,nmb,nmb);
	nmb *= -1;
	printf("\tOrigin:\t|%-11-0i|\t|%-0+11i|\t|%11+i|\t|%-11+i|\t|%0 i|\n",nmb,nmb,nmb,nmb,nmb);fflush(stdout);
	ft_printf("\tFt:\t|%-11-0i|\t|%-0+11i|\t|%11+i|\t|%-11+i|\t|%0 i|\n",nmb,nmb,nmb,nmb,nmb);
	nmb *= -1;
	printf("  |d|\tOrigin:\t|%-11-0d|\t|%-0+11d|\t|%11+d|\t|%-11+d|\t|%0 d|\n",nmb,nmb,nmb,nmb,nmb);fflush(stdout);
	ft_printf("\tFt:\t|%-11-0d|\t|%-0+11d|\t|%11+d|\t|%-11+d|\t|%0 d|\n",nmb,nmb,nmb,nmb,nmb);
	nmb *= -1;
	printf("\tOrigin:\t|%-11-0d|\t|%-0+11d|\t|%11+d|\t|%-11+d|\t|%0 d|\n",nmb,nmb,nmb,nmb,nmb);fflush(stdout);
	ft_printf("\tFt:\t|%-11-0d|\t|%-0+11d|\t|%11+d|\t|%-11+d|\t|%0 d|\n",nmb,nmb,nmb,nmb,nmb);
	nmb *= -1;
	printf("  |D|\tOrigin:\t|%-11-0D|\t|%-0+11D|\t|%11+D|\t|%-11+D|\t|%0 D|\n",nmb,nmb,nmb,nmb,nmb);fflush(stdout);
	ft_printf("\tFt:\t|%-11-0D|\t|%-0+11D|\t|%11+D|\t|%-11+D|\t|%0 D|\n",nmb,nmb,nmb,nmb,nmb);
	nmb *= -1;
	printf("\tOrigin:\t|%-11-0D|\t|%-0+11D|\t|%11+D|\t|%-11+D|\t|%0 D|\n",nmb,nmb,nmb,nmb,nmb);fflush(stdout);
	ft_printf("\tFt:\t|%-11-0D|\t|%-0+11D|\t|%11+D|\t|%-11+D|\t|%0 D|\n",nmb,nmb,nmb,nmb,nmb);
	nmb *= -1;
	printf("  |u|\tOrigin:\t|%-11-0u|\t|%-0+11u|\t|%11+u|\t|%-11+u|\t|%0 u|\n",nmb,nmb,nmb,nmb,nmb);fflush(stdout);
	ft_printf("\tFt:\t|%-11-0u|\t|%-0+11u|\t|%11+u|\t|%-11+u|\t|%0 u|\n",nmb,nmb,nmb,nmb,nmb);
	nmb *= -1;
	printf("\tOrigin:\t|%-11-0u|\t|%-0+11u|\t|%11+u|\t|%-11+u|\t|%0 u|\n",nmb,nmb,nmb,nmb,nmb);fflush(stdout);
	ft_printf("\tFt:\t|%-11-0u|\t|%-0+11u|\t|%11+u|\t|%-11+u|\t|%0 u|\n",nmb,nmb,nmb,nmb,nmb);
	nmb *= -1;
	printf("  |U|\tOrigin:\t|%-11-0U|\t|%-0+11U|\t|%11+U|\t|%-11+U|\t|%0 U|\n",nmb,nmb,nmb,nmb,nmb);fflush(stdout);
	ft_printf("\tFt:\t|%-11-0U|\t|%-0+11U|\t|%11+U|\t|%-11+U|\t|%0 U|\n",nmb,nmb,nmb,nmb,nmb);
	nmb *= -1;
	printf("\tOrigin:\t|%-11-0U|\t|%-0+11U|\t|%11+U|\t|%-11+U|\t|%0 U|\n",nmb,nmb,nmb,nmb,nmb);fflush(stdout);
	ft_printf("\tFt:\t|%-11-0U|\t|%-0+11U|\t|%11+U|\t|%-11+U|\t|%0 U|\n",nmb,nmb,nmb,nmb,nmb);
	nmb *= -1;
	printf("  |o|\tOrigin:\t|%-11-0o|\t|%-0+11o|\t|%11+o|\t|%-11+o|\t|%0 o|\n",nmb,nmb,nmb,nmb,nmb);fflush(stdout);
	ft_printf("\tFt:\t|%-11-0o|\t|%-0+11o|\t|%11+o|\t|%-11+o|\t|%0 o|\n",nmb,nmb,nmb,nmb,nmb);
	nmb *= -1;
	printf("\tOrigin:\t|%-11-0o|\t|%-0+11o|\t|%11+o|\t|%-11+o|\t|%0 o|\n",nmb,nmb,nmb,nmb,nmb);fflush(stdout);
	ft_printf("\tFt:\t|%-11-0o|\t|%-0+11o|\t|%11+o|\t|%-11+o|\t|%0 o|\n",nmb,nmb,nmb,nmb,nmb);
	nmb *= -1;
	printf("  |O|\tOrigin:\t|%-11-0O|\t|%-0+11O|\t|%11+O|\t|%-11+O|\t|%0 O|\n",nmb,nmb,nmb,nmb,nmb);fflush(stdout);
	ft_printf("\tFt:\t|%-11-0O|\t|%-0+11O|\t|%11+O|\t|%-11+O|\t|%0 O|\n",nmb,nmb,nmb,nmb,nmb);
	nmb *= -1;
	printf("\tOrigin:\t|%-11-0O|\t|%-0+11O|\t|%11+O|\t|%-11+O|\t|%0 O|\n",nmb,nmb,nmb,nmb,nmb);fflush(stdout);
	ft_printf("\tFt:\t|%-11-0O|\t|%-0+11O|\t|%11+O|\t|%-11+O|\t|%0 O|\n",nmb,nmb,nmb,nmb,nmb);
	nmb *= -1;
	printf("  |x|\tOrigin:\t|%-11-0x|\t|%-0+11x|\t|%11+x|\t|%-11+x|\t|%0 x|\n",nmb,nmb,nmb,nmb,nmb);fflush(stdout);
	ft_printf("\tFt:\t|%-11-0x|\t|%-0+11x|\t|%11+x|\t|%-11+x|\t|%0 x|\n",nmb,nmb,nmb,nmb,nmb);
	nmb *= -1;
	printf("\tOrigin:\t|%-11-0x|\t|%-0+11x|\t|%11+x|\t|%-11+x|\t|%0 x|\n",nmb,nmb,nmb,nmb,nmb);fflush(stdout);
	ft_printf("\tFt:\t|%-11-0x|\t|%-0+11x|\t|%11+x|\t|%-11+x|\t|%0 x|\n",nmb,nmb,nmb,nmb,nmb);
	nmb *= -1;
	printf("  |X|\tOrigin:\t|%-11-0X|\t|%-0+11X|\t|%11+X|\t|%-11+X|\t|%0 X|\n",nmb,nmb,nmb,nmb,nmb);fflush(stdout);
	ft_printf("\tFt:\t|%-11-0X|\t|%-0+11X|\t|%11+X|\t|%-11+X|\t|%0 X|\n",nmb,nmb,nmb,nmb,nmb);
	nmb *= -1;
	printf("\tOrigin:\t|%-11-0X|\t|%-0+11X|\t|%11+X|\t|%-11+X|\t|%0 X|\n",nmb,nmb,nmb,nmb,nmb);fflush(stdout);
	ft_printf("\tFt:\t|%-11-0X|\t|%-0+11X|\t|%11+X|\t|%-11+X|\t|%0 X|\n",nmb,nmb,nmb,nmb,nmb);
//Flag # for X x and o and O and i
	printf("\nNumber options(field width, presicion, justification and #):\n");
	//o
	printf("  |o|\tOrigin:\t|%#6o|\t|%#-12o|\t|%#o|\t\t|%#09o|\t|%#02o|\n", 8400,8400,0,8400,8400);fflush(stdout);
	ft_printf("\tFt:\t|%#6o|\t|%#-12o|\t|%#o|\t\t|%#09o|\t|%#02o|\n", 8400,8400,0,8400,8400);
	printf("\tOrigin:\t|%#6.7o|\t|%#-12.7o|\t|%#.7o|\t|%#09.7o|\t|%#02.7o|\n", 8400,8400,0,8400,8400);fflush(stdout);
	ft_printf("\tFt:\t|%#6.7o|\t|%#-12.7o|\t|%#.7o|\t|%#09.7o|\t|%#02.7o|\n", 8400,8400,0,8400,8400);
	printf("\tOrigin:\t|%#6.2o|\t|%#-12.2o|\t|%#.3o|\t\t|%#09.2o|\t|%#02.2o|\n", 8400,8400,0,8400,8400);fflush(stdout);
	ft_printf("\tFt:\t|%#6.2o|\t|%#-12.2o|\t|%#.3o|\t\t|%#09.2o|\t|%#02.2o|\n", 8400,8400,0,8400,8400);
	printf("\tOrigin:\t|%-#13.10o|\t|%-12#.10o|\t|%-13.10#o|\t|%-13.-9#o|\n", 25,25,25,25); fflush(stdout);
	ft_printf("\tFt:\t|%-#13.10o|\t|%-12#.10o|\t|%-13.10#o|\t|%-13.-9#o|\n", 25,25,25,25);
	//O
	printf("  |O|\tOrigin:\t|%#6O|\t|%#-12O|\t|%#O|\t\t|%#09O|\t|%#02O|\n", 8400,8400,0,8400,8400);fflush(stdout);
	ft_printf("\tFt:\t|%#6O|\t|%#-12O|\t|%#O|\t\t|%#09O|\t|%#02O|\n", 8400,8400,0,8400,8400);
	printf("\tOrigin:\t|%#6.7O|\t|%#-12.7O|\t|%#.7O|\t|%#09.7O|\t|%#02.7O|\n", 8400,8400,0,8400,8400);fflush(stdout);
	ft_printf("\tFt:\t|%#6.7O|\t|%#-12.7O|\t|%#.7O|\t|%#09.7O|\t|%#02.7O|\n", 8400,8400,0,8400,8400);
	printf("\tOrigin:\t|%#6.2O|\t|%#-12.2O|\t|%#.3O|\t\t|%#09.2O|\t|%#02.2O|\n", 8400,8400,0,8400,8400);fflush(stdout);
	ft_printf("\tFt:\t|%#6.2O|\t|%#-12.2O|\t|%#.3O|\t\t|%#09.2O|\t|%#02.2O|\n", 8400,8400,0,8400,8400);
	printf("\tOrigin:\t|%-#13.10O|\t|%-12#.10O|\t|%-13.10#O|\t|%-13.-9#O|\n", 25,25,25,25); fflush(stdout);
	ft_printf("\tFt:\t|%-#13.10O|\t|%-12#.10O|\t|%-13.10#O|\t|%-13.-9#O|\n", 25,25,25,25);
	//x
	printf("  |x|\tOrigin:\t|%#6x|\t|%#-12x|\t|%#x|\t\t|%#09x|\t|%#02x|\n", 8400,8400,0,8400,8400);fflush(stdout);
	ft_printf("\tFt:\t|%#6x|\t|%#-12x|\t|%#x|\t\t|%#09x|\t|%#02x|\n", 8400,8400,0,8400,8400);
	printf("\tOrigin:\t|%#6.7x|\t|%#-12.7x|\t|%#.7x|\t|%#09.7x|\t|%#02.7x|\n", 8400,8400,0,8400,8400);fflush(stdout);
	ft_printf("\tFt:\t|%#6.7x|\t|%#-12.7x|\t|%#.7x|\t|%#09.7x|\t|%#02.7x|\n", 8400,8400,0,8400,8400);
	printf("\tOrigin:\t|%#6.2x|\t|%#-12.2x|\t|%#.3x|\t\t|%#09.2x|\t|%#02.2x|\n", 8400,8400,0,8400,8400);fflush(stdout);
	ft_printf("\tFt:\t|%#6.2x|\t|%#-12.2x|\t|%#.3x|\t\t|%#09.2x|\t|%#02.2x|\n", 8400,8400,0,8400,8400);
	printf("\tOrigin:\t|%-#13.10x|\t|%-12#.10x|\t|%-13.10#x|\t|%-13.-9#x|\n", 25,25,25,25); fflush(stdout);
	ft_printf("\tFt:\t|%-#13.10x|\t|%-12#.10x|\t|%-13.10#x|\t|%-13.-9#x|\n", 25,25,25,25);
	//X
	printf("  |X|\tOrigin:\t|%#6X|\t|%#-12X|\t|%#X|\t\t|%#09X|\t|%#02X|\n", 8400,8400,0,8400,8400);fflush(stdout);
	ft_printf("\tFt:\t|%#6X|\t|%#-12X|\t|%#X|\t\t|%#09X|\t|%#02X|\n", 8400,8400,0,8400,8400);
	printf("\tOrigin:\t|%#6.7X|\t|%#-12.7X|\t|%#.7X|\t|%#09.7X|\t|%#02.7X|\n", 8400,8400,0,8400,8400);fflush(stdout);
	ft_printf("\tFt:\t|%#6.7X|\t|%#-12.7X|\t|%#.7X|\t|%#09.7X|\t|%#02.7X|\n", 8400,8400,0,8400,8400);
	printf("\tOrigin:\t|%#6.2X|\t|%#-12.2X|\t|%#.3X|\t\t|%#09.2X|\t|%#02.2X|\n", 8400,8400,0,8400,8400);fflush(stdout);
	ft_printf("\tFt:\t|%#6.2X|\t|%#-12.2X|\t|%#.3X|\t\t|%#09.2X|\t|%#02.2X|\n", 8400,8400,0,8400,8400);
	printf("\tOrigin:\t|%-#13.10X|\t|%-12#.10X|\t|%-12.10#X|\t|%-13.-9#X|\n", 25,25,25,25); fflush(stdout);
	ft_printf("\tFt:\t|%-#13.10X|\t|%-12#.10X|\t|%-12.10#X|\t|%-13.-9#X|\n", 25,25,25,25);
	//i
	printf("  |i|\tOrigin:\t|%#6i|\t|%#-12i|\t|%#i|\t\t|%#09i|\t|%#02i|\n", 8400,8400,0,8400,8400);fflush(stdout);
	ft_printf("\tFt:\t|%#6i|\t|%#-12i|\t|%#i|\t\t|%#09i|\t|%#02i|\n", 8400,8400,0,8400,8400);
	printf("\tOrigin:\t|%#6.7i|\t|%#-12.7i|\t|%#.7i|\t|%#09.7i|\t|%#02.7i|\n", 8400,8400,0,8400,8400);fflush(stdout);
	ft_printf("\tFt:\t|%#6.7i|\t|%#-12.7i|\t|%#.7i|\t|%#09.7i|\t|%#02.7i|\n", 8400,8400,0,8400,8400);
	printf("\tOrigin:\t|%#6.2i|\t|%#-12.2i|\t|%#.3i|\t\t|%#09.2i|\t|%#02.2i|\n", 8400,8400,0,8400,8400);fflush(stdout);
	ft_printf("\tFt:\t|%#6.2i|\t|%#-12.2i|\t|%#.3i|\t\t|%#09.2i|\t|%#02.2i|\n", 8400,8400,0,8400,8400);
	printf("\tOrigin:\t|%-#13.10i|\t|%-12#.10i|\t|%-12.10#i|\t|%-13.-9#i|\n", 25,25,25,25); fflush(stdout);
	ft_printf("\tFt:\t|%-#13.10i|\t|%-12#.10i|\t|%-12.10#i|\t|%-13.-9#i|\n", 25,25,25,25);
	// mix
	printf("\n  Mix:\t\t| o |\t| O |\t|x|\t|X|\t|d|\t|i|\t|D|\n");
	printf("\tOrigin:\t|%#.o %#.0o|\t|%#.O %#.0O|\t|%#.x %#.0x|\t|%#.X %#.0X|\t|%#.d %#.0d|\t|%#.i %#.0i|\t|%#.D %#.0D|\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0);fflush(stdout);
	ft_printf("\tFt:\t|%#.o %#.0o|\t|%#.O %#.0O|\t|%#.x %#.0x|\t|%#.X %#.0X|\t|%#.d %#.0d|\t|%#.i %#.0i|\t|%#.D %#.0D|\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0);
//Length modifiers
	printf("\nNumber options(field width and length modifiers):\n");
	printf("\t\t|%5s|\t|%5s|\t|%20s|\t|%20s|\t|%20s|\t|%10s|\t|%10s|\n", "hh", "h", "l", "ll","j", "z", "nothing" );
	long long ll_nmb = LONG_MAX;
	short int hh_nmb = SHRT_MAX;
	//i
	printf("  |i|\tOrigin:\t|%5hhi|\t|%5hi|\t|%20li|\t|%20lli|\t|%20ji|\t|%10zi|\t|%10i|\n", ll_nmb,ll_nmb,ll_nmb,ll_nmb,ll_nmb,-2,ll_nmb);fflush(stdout);
	ft_printf("\tFt:\t|%5hhi|\t|%5hi|\t|%20li|\t|%20lli|\t|%20ji|\t|%10zi|\t|%10i|\n", ll_nmb,ll_nmb,ll_nmb,ll_nmb,ll_nmb,-2,ll_nmb);
	//d
	printf("  |d|\tOrigin:\t|%5hhd|\t|%5hd|\t|%20ld|\t|%20lld|\t|%20jd|\t|%10zd|\t|%10d|\n", hh_nmb,hh_nmb,ll_nmb,ll_nmb,ll_nmb,-2,ll_nmb);fflush(stdout);
	ft_printf("\tFt:\t|%5hhd|\t|%5hd|\t|%20ld|\t|%20lld|\t|%20jd|\t|%10zd|\t|%10d|\n", hh_nmb,hh_nmb,ll_nmb,ll_nmb,ll_nmb,-2,ll_nmb);
	//D
	printf("  |D|\tOrigin:\t|%5hhD|\t|%5hD|\t|%20lD|\t|%20llD|\t|%20jD|\t|%10zD|\t|%10D|\n", hh_nmb,hh_nmb,ll_nmb,ll_nmb,ll_nmb,-2,ll_nmb);fflush(stdout);
	ft_printf("\tFt:\t|%5hhD|\t|%5hD|\t|%20lD|\t|%20llD|\t|%20jD|\t|%10zD|\t|%10D|\n", hh_nmb,hh_nmb,ll_nmb,ll_nmb,ll_nmb,-2,ll_nmb);
	//u
	printf("  |u|\tOrigin:\t|%5hhu|\t|%5hu|\t|%20lu|\t|%20llu|\t|%20ju|\t|%10zu|\t|%10u|\n", hh_nmb,hh_nmb,ll_nmb,ll_nmb,ll_nmb,-2,ll_nmb);fflush(stdout);
	ft_printf("\tFt:\t|%5hhu|\t|%5hu|\t|%20lu|\t|%20llu|\t|%20ju|\t|%10zu|\t|%10u|\n", hh_nmb,hh_nmb,ll_nmb,ll_nmb,ll_nmb,-2,ll_nmb);
	//U
	printf("  |U|\tOrigin:\t|%5hhU|\t|%5hU|\t|%20lU|\t|%20llU|\t|%20jU|\t|%10zU|\t|%10U|\n", hh_nmb,hh_nmb,ll_nmb,ll_nmb,ll_nmb,-2,ll_nmb);fflush(stdout);
	ft_printf("\tFt:\t|%5hhU|\t|%5hU|\t|%20lU|\t|%20llU|\t|%20jU|\t|%10zU|\t|%10U|\n", hh_nmb,hh_nmb,ll_nmb,ll_nmb,ll_nmb,-2,ll_nmb);
	//x
	printf("  |x|\tOrigin:\t|%5hhx|\t|%5hx|\t|%20lx|\t|%20llx|\t|%20jx|\t|%10zx|\t|%10x|\n", hh_nmb,hh_nmb,ll_nmb,ll_nmb,ll_nmb,-2,ll_nmb);fflush(stdout);
	ft_printf("\tFt:\t|%5hhx|\t|%5hx|\t|%20lx|\t|%20llx|\t|%20jx|\t|%10zx|\t|%10x|\n", hh_nmb,hh_nmb,ll_nmb,ll_nmb,ll_nmb,-2,ll_nmb);
	//X
	printf("  |X|\tOrigin:\t|%5hhX|\t|%5hX|\t|%20lX|\t|%20llX|\t|%20jX|\t|%10zX|\t|%10X|\n", hh_nmb,hh_nmb,ll_nmb,ll_nmb,ll_nmb,-2,ll_nmb);fflush(stdout);
	ft_printf("\tFt:\t|%5hhX|\t|%5hX|\t|%20lX|\t|%20llX|\t|%20jX|\t|%10zX|\t|%10X|\n", hh_nmb,hh_nmb,ll_nmb,ll_nmb,ll_nmb,-2,ll_nmb);
	//o
	printf("  |o|\tOrigin:\t|%5hho|\t|%5ho|\t|%20lo|\t|%20llo|\t|%20jo|\t|%10zo|\t|%10o|\n", hh_nmb,hh_nmb,ll_nmb,ll_nmb,ll_nmb,-2,ll_nmb);fflush(stdout);
	ft_printf("\tFt:\t|%5hho|\t|%5ho|\t|%20lo|\t|%20llo|\t|%20jo|\t|%10zo|\t|%10o|\n", hh_nmb,hh_nmb,ll_nmb,ll_nmb,ll_nmb,-2,ll_nmb);
	//O
	printf("  |O|\tOrigin:\t|%5hhO|\t|%5hO|\t|%20lO|\t|%20llO|\t|%20jO|\t|%10zO|\t|%10O|\n", hh_nmb,hh_nmb,ll_nmb,ll_nmb,ll_nmb,-2,ll_nmb);fflush(stdout);
	ft_printf("\tFt:\t|%5hhO|\t|%5hO|\t|%20lO|\t|%20llO|\t|%20jO|\t|%10zO|\t|%10O|\n", hh_nmb,hh_nmb,ll_nmb,ll_nmb,ll_nmb,-2,ll_nmb);
//Length modifiers + biiiiiiiiiiiiiiiiiiiiiiiiig numbers
	printf("\nVery big number options(field width and length modifiers):\n\t\t|%22s|\t|%22s|\t|%22s|\t|%22s|\n", "ll + small letter", "ll + BIG letter","hh + small letter", "hh + BIG letter");
	printf(" |d/D|\tOrigin:\t|%22lld|\t|%22llD|\t|%22hhd|\t|%22hhD|\n", -9223372036854775808,-9223372036854775808,-9223372036854775808,-9223372036854775808);fflush(stdout);
	ft_printf("\tFt:\t|%22lld|\t|%22llD|\t|%22hhd|\t|%22hhD|\n", -9223372036854775808,-9223372036854775808,-9223372036854775808,-9223372036854775808);
	printf(" |u/U|\tOrigin:\t|%22llu|\t|%22llU|\t|%22hhu|\t|%22hhU|\n", -9223372036854775808,-9223372036854775808,-9223372036854775808,-9223372036854775808);fflush(stdout);
	ft_printf("\tFt:\t|%22llu|\t|%22llU|\t|%22hhu|\t|%22hhU|\n", -9223372036854775808,-9223372036854775808,-9223372036854775808,-9223372036854775808);
	printf(" |o/O|\tOrigin:\t|%22llo|\t|%22llO|\t|%22hho|\t|%22hhO|\n", -9223372036854775808,-9223372036854775808,-9223372036854775808,-9223372036854775808);fflush(stdout);
	ft_printf("\tFt:\t|%22llo|\t|%22llO|\t|%22hho|\t|%22hhO|\n", -9223372036854775808,-9223372036854775808,-9223372036854775808,-9223372036854775808);
	printf(" |x/X|\tOrigin:\t|%22llx|\t|%22llX|\t|%22hhx|\t|%22hhX|\n", -9223372036854775808,-9223372036854775808,-9223372036854775808,-9223372036854775808);fflush(stdout);
	ft_printf("\tFt:\t|%22llx|\t|%22llX|\t|%22hhx|\t|%22hhX|\n", -9223372036854775808,-9223372036854775808,-9223372036854775808,-9223372036854775808);
	printf("\nVery big number options(field width and length modifiers):\n\t\t|%22s|\t|%22s|\t|%22s|\t|%22s|\n", "z + small letter", "z + BIG letter","j + small letter", "j + BIG letter");
	printf(" |d/D|\tOrigin:\t|%22zd|\t|%22zD|\t|%22jd|\t|%22jD|\n", -9223372036854775808,-9223372036854775808,-9223372036854775808,-9223372036854775808);fflush(stdout);
	ft_printf("\tFt:\t|%22zd|\t|%22zD|\t|%22jd|\t|%22jD|\n", -9223372036854775808,-9223372036854775808,-9223372036854775808,-9223372036854775808);
	printf(" |u/U|\tOrigin:\t|%22zu|\t|%22zU|\t|%22ju|\t|%22jU|\n", -9223372036854775808,-9223372036854775808,-9223372036854775808,-9223372036854775808);fflush(stdout);
	ft_printf("\tFt:\t|%22zu|\t|%22zU|\t|%22ju|\t|%22jU|\n", -9223372036854775808,-9223372036854775808,-9223372036854775808,-9223372036854775808);
	printf(" |o/O|\tOrigin:\t|%22zo|\t|%22zO|\t|%22jo|\t|%22jO|\n", -9223372036854775808,-9223372036854775808,-9223372036854775808,-9223372036854775808);fflush(stdout);
	ft_printf("\tFt:\t|%22zo|\t|%22zO|\t|%22jo|\t|%22jO|\n", -9223372036854775808,-9223372036854775808,-9223372036854775808,-9223372036854775808);
	printf(" |x/X|\tOrigin:\t|%22zx|\t|%22zX|\t|%22jx|\t|%22jX|\n", -9223372036854775808,-9223372036854775808,-9223372036854775808,-9223372036854775808);fflush(stdout);
	ft_printf("\tFt:\t|%22zx|\t|%22zX|\t|%22jx|\t|%22jX|\n", -9223372036854775808,-9223372036854775808,-9223372036854775808,-9223372036854775808);
//Not number options
	printf("\nNot number number options(field width and length modifiers):\n\t\t|%20s|\t|%20s|\t|%20s|\t|%20s|\n", "l", "ll","hh", "h");
	printf(" |i|\tOrigin:\t|%20li|\t|%20lli|\t|%20hhi|\t|%20hi|\n", "4294967296","4294967296","4294967296","4294967296");fflush(stdout);
	ft_printf("\tFt:\t|%20li|\t|%20lli|\t|%20hhi|\t|%20hi|\n", "4294967296","4294967296","4294967296","4294967296");
	printf(" |d|\tOrigin:\t|%20ld|\t|%20lld|\t|%20hhd|\t|%20hd|\n", "4294967296","4294967296","4294967296","4294967296");fflush(stdout);
	ft_printf("\tFt:\t|%20ld|\t|%20lld|\t|%20hhd|\t|%20hd|\n", "4294967296","4294967296","4294967296","4294967296");
	printf(" |D|\tOrigin:\t|%20lD|\t|%20llD|\t|%20hhD|\t|%20hD|\n", "4294967296","4294967296","4294967296","4294967296");fflush(stdout);
	ft_printf("\tFt:\t|%20lD|\t|%20llD|\t|%20hhD|\t|%20hD|\n", "4294967296","4294967296","4294967296","4294967296");
	printf(" |u|\tOrigin:\t|%20lu|\t|%20llu|\t|%20hhu|\t|%20hu|\n", "4294967296","4294967296","4294967296","4294967296");fflush(stdout);
	ft_printf("\tFt:\t|%20lu|\t|%20llu|\t|%20hhu|\t|%20hu|\n", "4294967296","4294967296","4294967296","4294967296");
	printf(" |U|\tOrigin:\t|%20lU|\t|%20llU|\t|%20hhU|\t|%20hU|\n", "4294967296","4294967296","4294967296","4294967296");fflush(stdout);
	ft_printf("\tFt:\t|%20lU|\t|%20llU|\t|%20hhU|\t|%20hU|\n", "4294967296","4294967296","4294967296","4294967296");
	printf(" |x|\tOrigin:\t|%20lx|\t|%20llx|\t|%20hhx|\t|%20hx|\n", "4294967296","4294967296","4294967296","4294967296");fflush(stdout);
	ft_printf("\tFt:\t|%20lx|\t|%20llx|\t|%20hhx|\t|%20hx|\n", "4294967296","4294967296","4294967296","4294967296");
	printf(" |X|\tOrigin:\t|%20lX|\t|%20llX|\t|%20hhX|\t|%20hX|\n", "4294967296","4294967296","4294967296","4294967296");fflush(stdout);
	ft_printf("\tFt:\t|%20lX|\t|%20llX|\t|%20hhX|\t|%20hX|\n", "4294967296","4294967296","4294967296","4294967296");
	printf(" |o|\tOrigin:\t|%20lo|\t|%20llo|\t|%20hho|\t|%20ho|\n", "4294967296","4294967296","4294967296","4294967296");fflush(stdout);
	ft_printf("\tFt:\t|%20lo|\t|%20llo|\t|%20hho|\t|%20ho|\n", "4294967296","4294967296","4294967296","4294967296");
	printf(" |O|\tOrigin:\t|%20lO|\t|%20llO|\t|%20hhO|\t|%20hO|\n", "4294967296","4294967296","4294967296","4294967296");fflush(stdout);
	ft_printf("\tFt:\t|%20lO|\t|%20llO|\t|%20hhO|\t|%20hO|\n", "4294967296","4294967296","4294967296","4294967296");
//Undefined tests
	printf("\nUndefined tests:\n");
	printf("\tOrigin:\t|");printf("%");printf("|\t|");printf("% ");
	printf("|\t|");printf("{%}");printf("|\t|");printf("{%  z}");
	printf("|\t|");printf("% h");printf("|\t|");printf("%  z");
	printf("|\t|");printf("%  z  ");printf("|\t|");printf("% ll");
	printf("|\n");fflush(stdout);
	ft_printf("\tFt:\t|");ft_printf("%");ft_printf("|\t|");ft_printf("% ");
	ft_printf("|\t|");ft_printf("{%}");ft_printf("|\t|");ft_printf("{%  z}");
	ft_printf("|\t|");ft_printf("% h");	ft_printf("|\t|");ft_printf("%  z");
	ft_printf("|\t|");ft_printf("%  z  ");ft_printf("|\t|");ft_printf("% ll");
	ft_printf("|\n");
	printf("\tOrigin:\t|");printf("%  Z");printf("|\t|");printf("% llZ");
	printf("|\t|");printf("% Z  ");printf("|\t|");printf("%  llK");
	printf("|\t|");printf("%  llLzZ  ");printf("|\t|");printf("% hh");
	printf("|\n");fflush(stdout);
	ft_printf("\tFt:\t|");ft_printf("%  Z");ft_printf("|\t|");ft_printf("% llZ");
	ft_printf("|\t|");ft_printf("% Z  ");	ft_printf("|\t|");ft_printf("%  llK");
	ft_printf("|\t|");ft_printf("%  llLzZ  ");ft_printf("|\t|");ft_printf("% hh");
	ft_printf("|\n");
//Strange undefined tests to test the atoi of the field width and presicion
	printf("\nVery undefined tests(field width, presicion and all flags) only 'd':\n");
	printf("Round 1:\t|-5.#3|\t|-5.#6.5|\t|-5.#6|\t\t|-5.#6.|\t|-5.#6#4|\t|-5.#6#.4|\t|-5.#6.#0|\t|-5.#6.#0#7|\n");
	printf("\tOrigin:\t|%-5.#3d|\t|%-5.#6.5d|\t|%-5.#6d|\t|%-5.#6.d|\t|%-5.#6#4d|\t\t|%-5.#6#.4d|\t|%-5.#6.#0d|\t|%-5.#6.#0#7d|\n", 42,42,42,42,42,42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%-5.#3d|\t|%-5.#6.5d|\t|%-5.#6d|\t|%-5.#6.d|\t|%-5.#6#4d|\t\t|%-5.#6#.4d|\t|%-5.#6.#0d|\t|%-5.#6.#0#7d|\n", 42,42,42,42,42,42,42,42);
	printf("\nRound 2:\t|.7.3|\t|07.3|\t\t|. 7.3|\t\t|.07.03|\t|.#7.3|\t\t|.+7.3|\n");
	printf("\tOrigin:\t|%.7.3d|\t|%07.3d|\t|%. 7.3d|\t|%.07.03d|\t\t|%.#7.3d|\t|%.+7.3d|\n",42,42,42,42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%.7.3d|\t|%07.3d|\t|%. 7.3d|\t|%.07.03d|\t\t|%.#7.3d|\t|%.+7.3d|\n",42,42,42,42,42,42);
	printf("\nRound 3:\t|.07.+6.3|\t|+5 +4.3|\t|+0+7+5|\t|+0+7+5.3|\t|+.07.3|\n");
	printf("\tOrigin:\t|%.07.+6.3d|\t|%+5 +4.3d|\t\t|%+0+7+5d|\t\t|%+0+7+5.3d|\t\t|%+.07.3d|\n", 42,42,42,42,42);fflush(stdout);
	ft_printf("\tFt:\t|%.07.+6.3d|\t|%+5 +4.3d|\t\t|%+0+7+5d|\t\t|%+0+7+5.3d|\t\t|%+.07.3d|\n", 42,42,42,42,42);
	printf("\nRound 4:\t|ll.15.12|\t|.ll 15.12|\t\t|.015ll.12|\t|.ll#15.12|\t\t|.ll#15.12x|\n",-42,-42,-42,-42);
	printf("\tOrigin:\t|%ll.15.12d|\t|%.ll 15.12d|\t|%.015ll.12d|\t|%.ll#15.12d|\t|%.ll#15.12x|\n",-42,-42,-42,-42,-42);fflush(stdout);
	ft_printf("\tFt:\t|%ll.15.12d|\t|%.ll 15.12d|\t|%.015ll.12d|\t|%.ll#15.12d|\t|%.ll#15.12x|\n",-42,-42,-42,-42,-42);
//Asterics tests
	printf("Asterics tests!\n\tOrigin:\t|%*.*i|\t\t|%*.*i|\t\t|%*.*i|\t\t|%*.*i|\n",1,1,nmb, 5,1,nmb, 5,3,nmb, 1,5,nmb);fflush(stdout);
	ft_printf("\tFt:\t|%*.*i|\t\t|%*.*i|\t\t|%*.*i|\t\t|%*.*i|\n",1,1,nmb, 5,1,nmb, 5,3,nmb, 1,5,nmb);
	printf("\tOrigin:\t|%ll.*.*d|\t|%.ll *.*d|\t|%.0*ll.*d|\t|%.ll#*.*d|\t|%.ll#*.*x|\n",15,12,-42,15,12,-42,15,12,-42,15,12,-42,15,12,-42);fflush(stdout);
	ft_printf("\tFt:\t|%ll.*.*d|\t|%.ll *.*d|\t|%.0*ll.*d|\t|%.ll#*.*d|\t|%.ll#*.*x|\n",15,12,-42,15,12,-42,15,12,-42,15,12,-42,15,12,-42);
	printf("\tOrigin:\t|%-*.#*d|\t|%*.#*.*d|\t|%-*.#*d|\t|%*.#*.d|\t|%-*.#*#*d|\t\t|%*.#*#.*d|\t|%-*.#*.#*d|\t|%-*.#*.#*#*d|\n", 5,3,42,-5,6,5,42,5,6,42,-5,6,42,5,6,4,42,-5,6,4,42,5,6,0,42,5,6,0,7,42);fflush(stdout);
	ft_printf("\tFt:\t|%-*.#*d|\t|%*.#*.*d|\t|%-*.#*d|\t|%*.#*.d|\t|%-*.#*#*d|\t\t|%*.#*#.*d|\t|%-*.#*.#*d|\t|%-*.#*.#*#*d|\n", 5,3,42,-5,6,5,42,5,6,42,-5,6,42,5,6,4,42,-5,6,4,42,5,6,0,42,5,6,0,7,42);
//Color tests
	ft_printf("\nColorssssss:!\n");

	ft_printf("\t%r|solid|","RED");ft_printf("%r","reset");
	ft_printf("\t%r|blink|","blinking RED");ft_printf("%r","reset");
	ft_printf("\t%r|bold|","asd bold RED");ft_printf("%r","reset");
	ft_printf("\t%r|dim|","asd bold RED");ft_printf("%r","reset");
	ft_printf("\t%r|underline|","_ RED");ft_printf("%r","reset");
	ft_printf("\t%r|reverse|","reverSe RED");ft_printf("%r","reset");
	ft_printf("\t%r|hidden|","hidden RED");ft_printf("%r\n","reset");
	ft_printf("\t%r|solid|","GrEEn");ft_printf("%r","reset");
	ft_printf("\t%r|blink|","blinking GrEEn");ft_printf("%r","reset");
	ft_printf("\t%r|bold|","asd bold GrEEn");ft_printf("%r","reset");
	ft_printf("\t%r|dim|","asd bold GrEEn");ft_printf("%r","reset");
	ft_printf("\t%r|underline|","_ GrEEn");ft_printf("%r","reset");
	ft_printf("\t%r|reverse|","reverSe GrEEn");ft_printf("%r","reset");
	ft_printf("\t%r|hidden|","hidden GrEEn");ft_printf("%r\n","reset");
	ft_printf("\t%r|solid|","yeLLOw");ft_printf("%r","reset");
	ft_printf("\t%r|blink|","blinking yeLLOw");ft_printf("%r","reset");
	ft_printf("\t%r|bold|","asd bold yeLLOw");ft_printf("%r","reset");
	ft_printf("\t%r|dim|","asd bold yeLLOw");ft_printf("%r","reset");
	ft_printf("\t%r|underline|","_ yeLLOw");ft_printf("%r","reset");
	ft_printf("\t%r|reverse|","reverSe yeLLOw");ft_printf("%r","reset");
	ft_printf("\t%r|hidden|","hidden yeLLOw");ft_printf("%r\n","reset");
	ft_printf("\t%r|solid|","  ffcyanrrr ");ft_printf("%r","reset");
	ft_printf("\t%r|blink|","blinking   ffcyanrrr ");ft_printf("%r","reset");
	ft_printf("\t%r|bold|","asd bold   ffcyanrrr ");ft_printf("%r","reset");
	ft_printf("\t%r|dim|","asd bold   ffcyanrrr ");ft_printf("%r","reset");
	ft_printf("\t%r|underline|","_   ffcyanrrr ");ft_printf("%r","reset");
	ft_printf("\t%r|reverse|","reverSe   ffcyanrrr ");ft_printf("%r","reset");
	ft_printf("\t%r|hidden|","hidden   ffcyanrrr ");ft_printf("%r\n","reset");
	ft_printf("\t%r|solid|","magenta");ft_printf("%r","reset");
	ft_printf("\t%r|blink|","blinking magenta");ft_printf("%r","reset");
	ft_printf("\t%r|bold|","asd bold magenta");ft_printf("%r","reset");
	ft_printf("\t%r|dim|","asd bold magenta");ft_printf("%r","reset");
	ft_printf("\t%r|underline|","_ magenta");ft_printf("%r","reset");
	ft_printf("\t%r|reverse|","reverSe magenta");ft_printf("%r","reset");
	ft_printf("\t%r|hidden|","hidden magenta");ft_printf("%r\n","reset");
	ft_printf("\t%r|solid|","blue");ft_printf("%r","reset");
	ft_printf("\t%r|blink|","blinking blue");ft_printf("%r","reset");
	ft_printf("\t%r|bold|","asd bold blue");ft_printf("%r","reset");
	ft_printf("\t%r|dim|","asd bold blue");ft_printf("%r","reset");
	ft_printf("\t%r|underline|","_ blue");ft_printf("%r","reset");
	ft_printf("\t%r|reverse|","reverSe blue");ft_printf("%r","reset");
	ft_printf("\t%r|hidden|","hidden blue");ft_printf("%r\n","reset");
	ft_printf("\t%r|solid|","light gray");ft_printf("%r","reset");
	ft_printf("\t%r|blink|","blinking light gray");ft_printf("%r","reset");
	ft_printf("\t%r|bold|","asd bold light gray");ft_printf("%r","reset");
	ft_printf("\t%r|dim|","asd bold light gray");ft_printf("%r","reset");
	ft_printf("\t%r|underline|","_ light gray");ft_printf("%r","reset");
	ft_printf("\t%r|reverse|","reverSe light gray");ft_printf("%r","reset");
	ft_printf("\t%r|hidden|","hidden light gray");ft_printf("%r\n","reset");
	ft_printf("\t%r|solid|","light grey");ft_printf("%r","reset");
	ft_printf("\t%r|blink|","blinking light grEy");ft_printf("%r","reset");
	ft_printf("\t%r|bold|","asd bold light grEy");ft_printf("%r","reset");
	ft_printf("\t%r|dim|","asd bold light grEy");ft_printf("%r","reset");
	ft_printf("\t%r|underline|","_ light grEy");ft_printf("%r","reset");
	ft_printf("\t%r|reverse|","reverSe light grEy");ft_printf("%r","reset");
	ft_printf("\t%r|hidden|","hidden light grEy");ft_printf("%r\n","reset");
	ft_printf("\t%r|solid|","dark gray");ft_printf("%r","reset");
	ft_printf("\t%r|blink|","blinking dark gray");ft_printf("%r","reset");
	ft_printf("\t%r|bold|","asd bold dark gray");ft_printf("%r","reset");
	ft_printf("\t%r|dim|","asd bold dark gray");ft_printf("%r","reset");
	ft_printf("\t%r|underline|","_ dark gray");ft_printf("%r","reset");
	ft_printf("\t%r|reverse|","reverSe dark gray");ft_printf("%r","reset");
	ft_printf("\t%r|hidden|","hidden dark gray");ft_printf("%r\n","reset");
	ft_printf("\t%r|solid|","dark grEy");ft_printf("%r","reset");
	ft_printf("\t%r|blink|","blinking dark grEy");ft_printf("%r","reset");
	ft_printf("\t%r|bold|","asd bold dark grEy");ft_printf("%r","reset");
	ft_printf("\t%r|dim|","asd bold dark grEy");ft_printf("%r","reset");
	ft_printf("\t%r|underline|","_ dark grEy");ft_printf("%r","reset");
	ft_printf("\t%r|reverse|","reverSe dark grEy");ft_printf("%r","reset");
	ft_printf("\t%r|hidden|","hidden dark grEy");ft_printf("%r\n","reset");
	ft_printf("\t%r|solid|","black");ft_printf("%r","reset");
	ft_printf("\t%r|blink|","blinking black");ft_printf("%r","reset");
	ft_printf("\t%r|bold|","asd bold black");ft_printf("%r","reset");
	ft_printf("\t%r|dim|","asd bold black");ft_printf("%r","reset");
	ft_printf("\t%r|underline|","_ black");ft_printf("%r","reset");
	ft_printf("\t%r|reverse|","reverSe black");ft_printf("%r","reset");
	ft_printf("\t%r|hidden|","hidden black");ft_printf("%r\n","reset");
	ft_printf("\t%r|solid|","white");ft_printf("%r","reset");
	ft_printf("\t%r|blink|","blinking white");ft_printf("%r","reset");
	ft_printf("\t%r|bold|","asd bold white");ft_printf("%r","reset");
	ft_printf("\t%r|dim|","asd bold white");ft_printf("%r","reset");
	ft_printf("\t%r|underline|","_ white");ft_printf("%r","reset");
	ft_printf("\t%r|reverse|","reverSe white");ft_printf("%r","reset");
	ft_printf("\t%r|hidden|","hidden white");ft_printf("%r\n","reset");

//Final
	ft_printf("\n%M => %s\n",(errno != 0) ? strerror(errno) : "Great!");

//LEAKS test (just make <gcc -D LEAKS> and it will work)
#ifdef LEAKS
	while (1) sleep(120);
#endif
/*
**	Put new stuff here
*/

	return (0);
}
