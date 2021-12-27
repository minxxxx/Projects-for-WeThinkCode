/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:14:50 by wide-aze          #+#    #+#             */
/*   Updated: 2015/02/21 17:01:43 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

# define GNL_BSIZE 32

typedef struct		s_rdgnl
{
	char			s[GNL_BSIZE];
	int				read;
	int				start;
	int				end;
	struct s_rdgnl	*next;
}					t_rdgnl;

typedef struct		s_flgnl
{
	int				fd;
	t_rdgnl			**firstcall;
	struct s_flgnl	*next;
}					t_flgnl;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_gnl_list
{
	char			buf[33];
	int				fd_save;
	int				i;
}					t_gnl_list;

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
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
int					ft_atoi(const char *str);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putnbr(int n);
void				ft_putendl(char const *s);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_itoa(int n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				*ft_strtrim(char const *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				**ft_strsplit(char const *s, char c);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				*v_malloc(size_t size);
char				*v_strnew(size_t size);
char				*v_strdup(char *str);
char				*v_strsub(char *str, unsigned int start, size_t len);
char				*v_strjoin(char *s1, char *s2);
char				*ft_strsub_free(char *str, int start, size_t len);
char				*ft_strjoin_free(char *s1, char const *s2);
char				*ft_strjoin_free_s2(char *s1, char *s2);
int					get_next_line(int const fd, char **line);
char				*ft_itoa_ui(unsigned int n);
char				*ft_itoa_ul(unsigned long n);
char				*ft_itoa_ull(unsigned long long n);
char				*ft_itoa_l(long n);
char				*ft_itoa_ll(long long n);
char				*ft_itoa_st(size_t n);
char				*convert_ui_to_other(unsigned int nb, char *base);
char				*convert_ul_to_other(unsigned long nb, char *base);
char				*convert_ull_to_other(unsigned long long nb, char *base);
char				*convert_st_to_other(size_t nb, char *base);
void				swap_two_int(int *a, int *b);
void				ft_exit(char *msg);
int					ft_str_isdigit(char *str);
char				**add_str_strtab(char **tab, char *str);
void				del_str_strtab(char **tab, char *str);
int					ft_strlen_strtab(char **tab);
void				*ft_malloc(unsigned int size);
int					str_is_digit(char *str);
void				swap_two_str(char **s1, char **s2);
void				ft_free(void *tofree);
void				v_free(void *tofree);
char				**cp_env_tab(char **env);
int					ft_random(int min, int max);
void				ft_quicksort_int(int *tab, int start, int end);
void				ft_quicksort_int_dsc(int *tab, int start, int end);
void				ft_quicksort_str(char **tab, int start, int end);
void				ft_quicksort_str_dsc(char **tab, int start, int end);
void				ft_srand(void);

#endif
