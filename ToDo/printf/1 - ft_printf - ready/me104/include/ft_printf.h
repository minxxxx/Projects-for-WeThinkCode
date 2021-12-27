/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:28:47 by juspende          #+#    #+#             */
/*   Updated: 2017/12/06 10:34:07 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef LLNEGMAX
#  define LLNEGMAX -9223372036854775807
# endif

# ifndef COLOR_ERROR
#  define COLOR_ERROR "Color not supported, please enter an int between 0 and "
# endif

# ifndef COLOR_ERROR2
#  define COLOR_ERROR2 "10, color has not been changed. Usage %b[nb[0-9]]\n"
# endif

# ifndef LEAVE
#  define LEAVE -1
# endif

/*
** Bonus are defined are intialized at  0 which means that they are not
** If you wnt to activate them, you just have to put an other int value
** Except 0, you oculd maybe try to put 1 or anything else like 42
** Why 42? Because it's the reason of life. You don't think so?
** Nethermind, better clone an other Printf
*/

# ifndef BONUS
#  define BONUS 0
# endif

# ifndef SUCCESS
#  define SUCCESS 1
# endif

# ifndef ERROR
#  define ERROR -1
# endif

/*
**                       COLOR DEFINE :D
**                       ________________
**
**					###   ###   #      ###   ###
**				   #     #  ##  #     #  ##  # #
**				  #     #    #  #    #    #  # #
**				  #     #   #   #    #   #  ###
**				  #     #   #  #     #   #  # #
**					###   ###   ####   ###   #  #
*/

/*
** If you need a special color or policy, you can change the ANSI code of the
** 9th, it is called PERSONNALIZED and it is made to be PERSONNALIZED.
** So feel free to configure your brand new Printf
*/

# ifndef BLACK
#  define BLACK "\033[30m"
# endif

# ifndef DEFAULT
#  define DEFAULT "\033[0m"
# endif

# ifndef RED
#  define RED "\033[31m"
# endif

# ifndef GREEN
#  define GREEN "\033[32m"
# endif

# ifndef YELLOW
#  define YELLOW "\033[33m"
# endif

# ifndef BLUE
#  define BLUE "\033[34m"
# endif

# ifndef MAGENTA
#  define MAGENTA "\033[35m"
# endif

# ifndef CYAN
#  define CYAN "\033[36m"
# endif

# ifndef WHITE
#  define WHITE "\033[37m"
# endif

# ifndef PERSONNALIZED
#  define PERSONNALIZED "\033[39m"
# endif

# include <wchar.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <inttypes.h>
# include <fcntl.h>

typedef struct		s_flag
{
	int				neg;
	int				pos;
	int				space;
	int				zero;
	int				diez;
	int				comma;
	int				point;
	int				larg;
	int				charn;
	int				h;
	int				hh;
	int				ll;
	int				l;
	int				j;
	int				z;
	int				tilt;
	intmax_t		nbr;
	char			c;
	int				cpy;
	char			*printed;
	int				instantquit;
	int				color;
}					t_flag;

int					ft_printtab(char **tab);
int					ft_putsterr(char *str);
int					x2(int b, char *fnl, const char *arg, t_flag *flag);
int					big_c2(va_list argp, wint_t *s, int i, t_flag *flag);
void				ft_putnstr_free(void *str, t_flag *flag, int *c);
int					big_s2(va_list argp, wint_t *tmp, int b, t_flag *flag);
void				ft_putchar_s(wchar_t c, t_flag *flag);
void				ft_puts(char *str, t_flag *flag);
void				larg_flag_before_s(t_flag *flag);
void				larg_flag_after_s(t_flag *flag);
void				empty_buffer(t_flag *flag);
void				ft_putwchar(char c, t_flag *flag);
int					ft_wstrlen(wint_t c);
void				larg_flag_after_d(t_flag *flag);
void				larg_flag_before_d2(t_flag *flag, char *str, int i);
void				larg_flag_before_d(t_flag *flag);
int					ft_uintlen(uintmax_t n, int base);
int					ft_uintstr(char *dst, uintmax_t n, int base);
char				*ft_strcat(char *dest, char *src);
char				*ft_strncat(char *dest, char *src, size_t len);
int					ft_strchr(const char *str, int c);
void				ft_putnstr(void *str, t_flag *flag, int *c);
int					free_main(t_flag *flag, int returned);
void				free_tab(char **tab);
int					int_len(intmax_t nbr);
int					int_len2(uintmax_t nbr);
void				length_modif_uox(va_list argp, t_flag *flag,
		uintmax_t *tmp);
void				length_modif_di(va_list argp, t_flag *flag, intmax_t *tmp);
void				larg_flag_before(t_flag *flag);
void				larg_flag_after(t_flag *flag);
size_t				ft_strlen(char *str);
char				*ft_strdup(const char *str);
char				*ft_getnbr_base(intmax_t nbr, char *base);
char				*ft_getnbr_base_ui(uintmax_t nbr, char *base);
char				*ft_strrev(char *str);
int					precision_pars(va_list argp, const char *arg, int *index,
		t_flag *flag);
void				*ft_print_memory(char *addr,
		unsigned int size, t_flag *flag);
int					ft_atoi(const char *str);
void				ft_print_adress(void *buf, t_flag *flag);
void				ft_print_bits(void *buf, t_flag *flag);
void				ft_putnbr_base(int nbr, char *base, t_flag *flag);
void				ft_putshort(short int nb, t_flag *flag);
char				*ft_strnew(size_t size);
int					ft_printf(const char *list, ...);
void				ft_putstr(const char *str, t_flag *flag);
void				ft_putoctal(const char *str, t_flag *flag);
void				ft_putchar(wchar_t c, t_flag *flag);
void				ft_printchar(char c, t_flag *flag);
void				ft_printwchar(char c, t_flag *flag);
void				ft_putint(intmax_t n, t_flag *flag);
void				ft_putuint(uintmax_t nb, t_flag *flag);
void				ft_putlong(long nb, t_flag *flag);
void				ft_putdouble(double nb, int index, t_flag *flag);
int					arg_parser(va_list argp, const char *arg,
		int *index, t_flag *flag);
int					init_struct(t_flag *flag);
char				*ft_itoa(uintmax_t n, int base);
char				*ft_itoa_double(double nb, int index);
int					flag_parser(va_list argp, const char *arg, int *index,
		t_flag *flag);
int					a(va_list argp, const char *arg, int *index, t_flag *flag);
int					b(va_list argp, const char *arg, int *index, t_flag *flag);
int					c(va_list argp, const char *arg, int *index, t_flag *flag);
int					d(va_list argp, const char *arg, int *index, t_flag *flag);
int					e(va_list argp, const char *arg, int *index, t_flag *flag);
int					f(va_list argp, const char *arg, int *index, t_flag *flag);
int					g(va_list argp, const char *arg, int *index, t_flag *flag);
int					h(va_list argp, const char *arg, int *index, t_flag *flag);
int					i(va_list argp, const char *arg, int *index, t_flag *flag);
int					j(va_list argp, const char *arg, int *index, t_flag *flag);
int					k(va_list argp, const char *arg, int *index, t_flag *flag);
int					l(va_list argp, const char *arg, int *index, t_flag *flag);
int					m(va_list argp, const char *arg, int *index, t_flag *flag);
int					n(va_list argp, const char *arg, int *index, t_flag *flag);
int					o(va_list argp, const char *arg, int *index, t_flag *flag);
int					p(va_list argp, const char *arg, int *index, t_flag *flag);
int					q(va_list argp, const char *arg, int *index, t_flag *flag);
int					r(va_list argp, const char *arg, int *index, t_flag *flag);
int					s(va_list argp, const char *arg, int *index, t_flag *flag);
int					t(va_list argp, const char *arg, int *index, t_flag *flag);
int					u(va_list argp, const char *arg, int *index, t_flag *flag);
int					v(va_list argp, const char *arg, int *index, t_flag *flag);
int					w(va_list argp, const char *arg, int *index, t_flag *flag);
int					x(va_list argp, const char *arg, int *index, t_flag *flag);
int					y(va_list argp, const char *arg, int *index, t_flag *flag);
int					z(va_list argp, const char *arg, int *index, t_flag *flag);
int					(*g_letter_parser[26])(va_list, const char*, int*, t_flag*);

#endif
