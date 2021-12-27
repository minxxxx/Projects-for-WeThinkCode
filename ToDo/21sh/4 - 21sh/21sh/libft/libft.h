/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 22:15:06 by sasiedu           #+#    #+#             */
/*   Updated: 2016/08/06 13:33:49 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>
# include "ft_printf.h"
# include <sys/ioctl.h>
# include <termios.h>
# include "get_next_line.h"

typedef	struct			s_list
{
	void				*content;
	size_t				content_size;
	struct	s_list		*next;
}						t_list;

/*
*** memory functions
*/
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memset(void *b, int c, size_t len);
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *restrict dst, const void \
		*restrict src, size_t n);
void					*ft_memccpy(void *restrict dst, const void *restrict \
		src, int c, size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memchr(const void *s, int c, size_t n);

/*
*** string functions
*/
size_t					ft_strlen(const char *s);
size_t					ft_strlcat(char *restrict dst, const char \
		*restrict src, size_t size);
char					*ft_strdup(const char *s1);
char					*ft_strcpy(char *dst, const char *src);
char					*ft_strncpy(char *dst, const char *src, size_t len);
char					*ft_strcat(char *restrict s1, const char *restrict s2);
char					*ft_strncat(char *restrict s1, const char \
		*restrict s2, size_t n);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strstr(const char *big, const char *little);
char					*ft_strnstr(const char *big, const char *little, size_t len);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);

/*
*** conversion function
*/
int						ft_atoi(const char *str);
int						ft_atoi_base(char *str, int base);
int						ft_toupper(int c);
int						ft_tolower(int c);
char					*ft_itoa(int n);
char					*ft_itoa_base(int nbr, int base);
void					ft_toupper_str(char **str);
void					ft_tolower_str(char **str);
float					ft_atof(const char *str);

/*
*** string check functions
*** return 1 if true; 0 if false
*/
int						ft_isalpha(int c);
int						ft_isalpha_str(char *str);
int						ft_isdigit(int c);
int						ft_isdigit_str(char *str);
int						ft_isalnum(int c);
int						ft_isalnum_str(char *str);
int						ft_isascii(int c);
int						ft_isascii_str(char *str);
int						ft_isprint(int c);
int						ft_isprint_str(char *str);

/*
*** malloc functions
*/
char					*ft_strnew(size_t size);
void					*ft_memalloc(size_t size);

/*
*** free functions
*/
void					ft_memdel(void **ap);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
void					ft_del_array(char **tab);

/*
*** extra string functions
*/
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s, char (*f)\
		(unsigned int, char));
char					*ft_strsub(char const *s, \
		unsigned int start, size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s);
char					**ft_strsplit(char const *s, char c);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t					ft_count_words(char const *s, char c);

/*
*** printing functions
*/
void					ft_putchar(char c);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr(char const *s);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl(char const *s);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr(int n);
void					ft_putnbr_fd(int n, int fd);
void					ft_putnbr_base(int nbr, int base);
void					ft_putnbr_base_fd(int fd, int nbr, int base);

/*
*** t_list functions
*/
t_list					*ft_lstnew(void const *content, size_t content_size);
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void					ft_del(void *content, size_t content_size);
void					ft_lst_remove_if(t_list **begin_lst, \
		void *data, int (*cmp)());
void					ft_lstprint(t_list **lst);
void					ft_sort_lst(t_list **lst);
void					ft_lstsort(t_list **lst);
size_t					ft_lstsize(t_list *lst);
int						ft_sorted_lst(t_list **lst);

/*
*** maths functions
*/
int						ft_abs(int nbr);
float					ft_fabs(float nbr);
void					ft_swap_int(int *a, int *b);
void					ft_swap_float(float *a, float *b);

/*
*** error functions
*/
void					ft_error(int err, char *str);

/*
*** 2d array functions
*/
char					**ft_array_join(char **tab, char *line);
void					ft_array_print(char **tab);
size_t					ft_array_size(char **tab);

/*
*** extra functions
*/
char					*ft_build_path(char *full_path, char *ext_path);
char					ft_dir(int file_no);

#endif
