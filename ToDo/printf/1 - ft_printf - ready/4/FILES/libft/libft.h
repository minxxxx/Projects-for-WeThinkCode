/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:38:42 by dtedgui           #+#    #+#             */
/*   Updated: 2016/02/08 09:09:10 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE 100

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# include <wchar.h>

/*
** PRINTING
*/
void			ft_putchar(char c);
void			ft_putwchar(wchar_t c);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr(char const *s);
void			ft_putwstr(wchar_t *str);
void			ft_putnstr(char const *s, size_t n);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putcolor(char *str, char *color);
void			ft_putrainbow(char *str);

void			ft_putstr_array(char **array, char sep);

void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr_base(int n, int base);

/*
** NUMBERS
*/
long			ft_nbrlen(long nb, long base);
int				ft_atoi(char *nb);
int				ft_atoi_base(char *nb, int base);
long			ft_atol(char *nb);
long long		ft_atoll(char *nb);
char			*ft_itoa(int nb);
char			*ft_itoa_base(int n, int base, int uppercase);
char			*ft_ltoa(long nb);
int				ft_power(int nb, int pow);
long			ft_power_long(long nb, long pow);
void			ft_sort_integer_table(int *tab, int size);

/*
** STRINGS
*/
char			*ft_tolower(char *str);
char			*ft_toupper(char *str);

int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_isalnum(int c);
int				ft_isalpha(int c);

size_t			ft_strlen(const char *s);
size_t			ft_strlen_char(const char *s, char c);

void			ft_bzero(void *s, size_t n);
char			*ft_strnew(size_t size);
void			ft_strclr(char *s);
void			ft_strdel(char **as);
void			ft_strdel_array(char ***as);

char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);

char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t n);
char			*ft_strdup(const char *s1);
char			*ft_strndup(const char *s1, size_t n);

char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *big, const char *little);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);

int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);

void			ft_striter(char *s, void (*f)(char*));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoin_nolimit(char delimiter, char *s1, ...);
char			*ft_strjoin_array(char **array, char *delimiter);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
char			*ft_strtrim_nolimit(char *s, ...);
char			**ft_strsplit(char const *s, char c);
char			*ft_strrev(char *str);

int				ft_strcount(char *str, char to_find);

char			*ft_str_realloc(char *old, size_t size);
char			*ft_str_replace(char *origin, char *rep, char *with);

/*
** MEMORY
*/
void			*ft_memset(void *str, int src, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);

/*
** LINKED LISTS
*/
typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void			ft_lstadd_beginning(t_list **alst, t_list *new);
void			ft_lstadd_end(t_list **alst, t_list *new);
void			ft_lstinsert_before(t_list **alst, t_list *target, t_list *new);
void			ft_lstinsert_after(t_list *target, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstconcat(t_list *lnk_first_list, t_list *head_second_list);

/*
** GET NEXT LINE
*/
int				get_next_line(int const fd, char **line);

typedef struct	s_list_gnl
{
	int					fd;
	char				*temp;
	struct s_list_gnl	*next;
}				t_list_gnl;

/*
** PRINTF
*/
int				ft_max(int i, int y);
size_t			ft_strnlen(const char *s, size_t len);
size_t			ft_strnwlen(wchar_t *s, size_t len);
size_t			ft_strwlen(wchar_t *s);
void			ft_putnwstr(wchar_t *str, size_t n);
void			ft_putnbr_max(intmax_t n);
void			ft_putnbr_fd_max(intmax_t n, int fd);
void			ft_putnbr_base_max(uintmax_t nbr, char *base);

#endif
