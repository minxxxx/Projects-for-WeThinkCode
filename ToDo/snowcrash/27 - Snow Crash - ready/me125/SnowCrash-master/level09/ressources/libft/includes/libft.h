/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <dgalide@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 19:44:34 by dgalide           #+#    #+#             */
/*   Updated: 2018/03/20 15:46:57 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../printf/includes/ft_printf.h"

# define BUFF_SIZE 10

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *newi);
void				ft_lstiter(t_list *alst, void (*f)(t_list *elem));

size_t				ft_tablen(char **tab);

void				ft_printtab(char **tab);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *str, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putchar(char c);
void				ft_putnbr(int nb);
void				ft_putstr(const char *str);
void				ft_bzero(void *s, size_t n);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				*ft_memset(void *s, int c, size_t len);
void				*ft_memalloc(size_t size);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void	*dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);

int					ft_printf(const char *format, ...);
int					get_next_line(int fd, char **line);
int					ft_countwords(const char *s, char c);
int					ft_lenwords(const char *s, char c, int word);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_islower(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
int					ft_isupper(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
int					ft_atoi_base(char *str, int base);
long				ft_power(int n, int power);

char				*ft_unsigned_itoa(unsigned long long n, int base);
char				*ft_itoa(intmax_t n, int base);
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strtrim(const char *s);
char				*ft_strnew(size_t size);
char				*ft_strdup(char *str);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strjoin_free(char **s1, char **s2,
	int bool_s1, int bool_s2);
char				**ft_strsplit(const char *s, char c);
char				**ft_maketab(int column, int line);

size_t				ft_strlen(const char *str);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				**ft_tab_cpy(char **src, char **dst);
void				ft_tab_del(char **tab);
char				**ft_tab_join(char **t1, char **t2, int b1, int b2);
#endif
