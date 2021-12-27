/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:11:04 by fkoehler          #+#    #+#             */
/*   Updated: 2016/09/13 17:53:16 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <get_next_line.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putnchar(char c, size_t n);
void				ft_putstr(char const *s);
void				ft_putnstr(char const *s, int n);
void				ft_putnstr_fd(char const *s, int n, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_print_array(char **array);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_replace_char(char *s, char to_find, char replace);
char				*ft_replace_str(const char *s1, unsigned int start,
					size_t len, const char *s2);
void				ft_strclr(char *s);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isquote(int c);
int					ft_isspace(int c);
int					ft_atoi(const char *str);
long				ft_atol(const char *str);
char				*ft_itoa(int n);
char				*ft_ltoa_base(long nb, int base);
int					ft_toupper(int c);
int					ft_tolower(int c);

size_t				ft_strlen(const char *s);
size_t				ft_multi_strlen(char **array);
int					ft_str_isempty(char *s);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strchr(const char *s, int c);
int					ft_strchr_index(const char *s, int c);
int					ft_strchr_count(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strrchr_index(const char *s, int c);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_countwords(char const *s, char c);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strstr(const char *big, const char *little);
int					ft_strstr_index(const char *big, const char *little);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
char				*ft_strnew(size_t size);
char				*ft_strdup(const char *s1);
void				ft_strdel(char **as);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_multi_strjoin(char **array, char *delimiter);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
int					free_tab(char **tab);

t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));

#endif
