/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 09:26:28 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/23 12:32:31 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFT_H
# define _LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <libc.h>
# include <sys/uio.h>
# include <fcntl.h>

# include <stdarg.h>
# include <string.h>
# include <stdio.h>

# define BUFF_SIZE 32
# define HEX "0123456789abcdef"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *s1, const void *s2, size_t n);
void				*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void				*ft_memmove(void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *s1, const char *s2);
char				*ft_strncpy(char *s1, const char *s2, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
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
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

int					get_next_line(const int fd, char **line);
int					ft_printf(const char *format, ...);
int					ft_intlen(int n);
int					ft_printf_hex(unsigned int n);
int					ft_print_hex(const char *format, int i, va_list ap);
int					ft_printf_hexm(unsigned int n);
int					ft_printf_hexa(unsigned long n);
int					ft_printf_ptr(void *n);
int					ft_printf_nbr_ld(long n);
int					ft_printf_char(char c);
int					ft_printf_nbr(int nb);
int					ft_printf_str(char *str);
int					ft_printf_long(const char *format, int i, va_list ap);
int					ft_printf_type(const char *format, int i, va_list ap);
int					ft_printf_unbr(unsigned int n);
int					ft_printf_octal(unsigned int n);
void				ft_putnbr_lf(double n);
int					ft_printf_nbr_lf(double n);
void				ft_putnbr_ld(long n);

void				ft_free_2d_array(char ***str);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_bufferreader(const int fd, char **line);
char				*ft_strjoin_free1(char *s1, char *s2);
char				*ft_strjoin_free2(char *s1, char *s2);
char				*ft_strjoin_free3(char *s1, char *s2);
double				ft_atod(const char *str);
char				*ft_ltoa(long long int n);
char				*ft_ultoa(unsigned long long int n);
char				*ft_ltoa_base(long long int n, char *base);
char				*ft_ultoa_base(unsigned long long int n, char *base);
void				ft_putwchar(wchar_t c);
void				ft_putwchar_fd(wchar_t c, int fd);
void				ft_putwstr(wchar_t const *s);
void				ft_putwstr_fd(wchar_t const *s, int fd);
size_t				ft_wstrlen(wchar_t const *s);
wchar_t				*ft_wstrsub(wchar_t const *s, unsigned int st, size_t l);
long				ft_atol(char const *str);
char				*ft_strsub_free(char const *s, unsigned int st, size_t l);
char				*ft_strtrim_free(char const *s);
void				ft_exit(char *message, int exit_status);
void				ft_putul(size_t n);
void				ft_putul_fd(size_t n, int fd);

#endif
