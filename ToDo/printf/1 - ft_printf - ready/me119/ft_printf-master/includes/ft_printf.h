/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 12:03:22 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/20 17:55:10 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <wchar.h>
# include "../libft/includes/libft.h"

# define RED  "\x1B[31m"
# define GREEN  "\x1B[32m"
# define YELLOW  "\x1B[33m"
# define BLUE  "\x1B[34m"
# define MAGENTA  "\x1B[35m"
# define CYAN  "\x1B[36m"
# define WHITE  "\x1B[37m"
# define NORMAL  "\x1B[0m"

typedef enum
{
	none,
	hh,
	h,
	l,
	ll,
	j,
	z,
	L,
}	t_length;

typedef enum
{
	no,
	yes,
	o,
	x,
	X,
	b,
}	t_hash;

typedef struct	s_flags
{
	int			left;
	int			plus;
	int			space;
	t_hash		hash;
	int			zero;
	int			unread;
	int			quote_mark;
}				t_flags;

typedef struct	s_mods
{
	t_flags		flags;
	int			width;
	int			precision;
	t_length	length;
	char		qualifier;
	int			base;
	int			sigfig;
	int			exp_base;
	char		exp_char;
	int			exp_len;
}				t_mods;

int				ft_printf(const char *format, ...);
int				ft_flags(const char *format, t_mods *mods);
int				ft_width(const char *format, t_mods *mods, va_list ap);
int				ft_precision(const char *format, t_mods *mods, va_list ap);
int				ft_length(const char *format, t_mods *mods);
int				ft_qualifier(char c, t_mods *mods);

int				ft_no_qual(t_mods *mods);
int				ft_numb(va_list ap, t_mods *mods);
int				ft_char(va_list ap, t_mods *mods);
int				ft_str(va_list ap, t_mods *mods);
int				ft_float(va_list ap, t_mods *mods);

int				ft_size(char *str, t_mods *mods);
int				ft_is_mb(char *s);
char			*ft_convert_len(va_list ap, t_mods *mods, char c);
char			*ft_convert_ulen(va_list ap, t_mods *mods, char c);
void			ft_push_right(t_mods *mods, char **mas, int size, char *str);
void			ft_push_left(t_mods *mods, char **mas, int size, char *str);
char			*ft_ftoa_handler(long double n, t_mods *mods, char c);
long double		ft_get_mantissa(long double n, int base);
int				ft_put_sign(t_mods *mods, char **mas, int i, char *str);
int				ft_put_content(t_mods *mods, char **mas, int i, char *str);
char			*ft_unprint(char *s, int i);
char			*ft_quote_mark(char *str);

#endif
