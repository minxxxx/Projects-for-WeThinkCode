/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:39:38 by apakhomo          #+#    #+#             */
/*   Updated: 2017/11/07 20:39:39 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# define ABS(x) (x < 0 ? -x : x)
# define MIM(x, y) (x < y ? y : x)
# define BUFF_SIZE 1
# define ERR(e) if (!e) return (-1);
# define NOMEM(no) if (!no) return (NULL);
# define BRK(ch) if (ch) break ;
# define NIL(z) z = 0;
# define WTHT 0
# define HASH 1
# define ZERO 2
# define MINUS 4
# define PLUS 8
# define SPACE 16
# define APOST 32
# define HEXCHAR1 (str[i] >= 'a' && str[i] <= 'f')
# define HEXCHAR2 (str[i] >= 'A' && str[i] <= 'F')
# define HEXCHAR HEXCHAR1 || HEXCHAR2
# define HEXSYMB str[i] == 'x' || str[i] == 'X'

/*
** ****************************************************************************
** **********************************LIBFT*************************************
** ****************************************************************************
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_gnl
{
	int				fd;
	char			*str;
	char			*after;
	struct s_gnl	*next;
	char			*temp;
	char			*tmp;
	int				i;
}					t_gnl;

char				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putnbr(int a);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strcpy (char *dst, const char *src);
char				*ft_strdup(const char *s1);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, char *s2, size_t n);
size_t				ft_strlcat(char *dst, char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *str, int ch);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putendl(char const *s);
char				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_swap(int *a, int *b);
int					*ft_range(int min, int max);
int					ft_sqrt(int nb);
int					ft_iterative_power(int nb, int power);
int					ft_recursive_power(int nb, int power);
char				**ft_split(char *str);
void				ft_print_hex(int dc);
int					get_next_line(const int fd, char **line);
int					ft_abs(int i);
int					ft_atoi_base(char *str, int base);
void				ft_testintstr(int a, char *name);
unsigned char		*ft_strtolower(unsigned char *s);
void				ft_prcharr(char **str, int a);
void				ft_free_arr(char **arr);
int					ft_check_hex(char *str);
int					ft_check_hex_char(char c);
unsigned long		ft_hex_to_ul(char *str);
int					ft_count_to_null(void **data, int type);
char				**ft_new_char_arr(size_t size);
int					**ft_new_int_arr(size_t size);
int					**ft_new_int_matrix(size_t size);
void				ft_strscpy(char *dst, const char *src, char stop);
char				*ft_strjoin_free(char *s1, char *s2);

/*
** ****************************************************************************
** ******************************FT_PRINTF*************************************
** ****************************************************************************
*/

typedef struct		s_pfs
{
	const char		*str;
	size_t			length;
}					t_pfs;

typedef enum		e_pf_mod
{
	NONE = 0, L = 1, H = 2, J = 3, Z = 4, LL = 5, HH = 6
}					t_pf_mod;

typedef struct		s_pf_argument
{
	size_t			position;
	size_t			length;
	t_pfs			str;
}					t_pf_argument;

typedef struct		s_arg
{
	t_pfs			str;
	int				add;
	int				flags;
	unsigned int	width;
	int				width_add;
	int				precision;
	t_pf_mod		mod;
	char			conver;
	int				error;
	void			*value;
}					t_arg;

typedef struct		s_pf_mngr
{
	char			conver;
	int				(*mngr)(t_arg, va_list);
}					t_pf_mngr;

int					pf_atoi(const char *s, int allow_neg, int *result,
						size_t *i);
char				*pf_itoa(intmax_t n, t_arg all, char sign);
char				*pf_uitoa(uintmax_t n, unsigned int base,
						const char *digits,
						size_t precision);
size_t				ft_strnlen(const char *s, const size_t max);
int					max(int a, int b);
int					bs(char c);
int					pf_mngr_percent(t_arg all, va_list arg);
int					pf_mngr_char(t_arg all, va_list arg);
int					pf_mngr_string(t_arg all, va_list arg);
int					pf_mngr_hex(t_arg all, va_list arg);
int					pf_write_chunk(const char *s, int free,
						size_t len, t_arg all);
int					pf_core(va_list arg, const char *s);
int					pf_transform(t_arg all, va_list arg, int i);
int					pf_write(const char *s, const size_t len);
int					pf_repeat(const char c, int len);
int					ft_printf(const char *format, ...);
int					mngr_add(t_arg *all, const char *s, size_t *i);
int					mngr_flags(t_arg *all, const char *s, size_t *i);
int					mngr_width(t_arg *all, const char *s, size_t *i);
int					mngr_precision(t_arg *p, const char *s, size_t *i);
int					mngr_mod(t_arg *p, const char *s, size_t *i);
int					mngr_conver(t_arg *p, const char *s, size_t *i);
t_arg				get_all(const char *s, size_t len);
int					conver(const char c);
int					modfc(const char c);
int					flag(const char c);
int					validsymb(const char c);
t_arg				arg(const char *s, const size_t len);
t_pfs				pfs(const char *s, size_t len);
t_arg				get_all(const char *s, size_t len);
int					pf_atoi(const char *s, int allow_neg,
						int *result, size_t *i);
char				*pf_itoa(intmax_t n, t_arg all, char sign);
char				*pf_uitoa(uintmax_t n, unsigned int base,
						const char *digits,
						size_t precision);

#endif
