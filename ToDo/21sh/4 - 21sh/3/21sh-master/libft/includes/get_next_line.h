/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 10:49:14 by fkoehler          #+#    #+#             */
/*   Updated: 2016/01/08 19:25:05 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 42

# include "libft.h"

typedef	struct			s_getline
{
	int					fd;
	char				buf[BUFF_SIZE + 1];
	char				*save;
	struct s_getline	*next;
}						t_getline;

int						get_next_line(int const fd, char **line);
int						read_buf(int const fd, t_getline **link, char **line);
int						fill_line(t_getline **link, char **line,
						int i, char *tmp);
void					check_link(int const fd, t_getline **link);
t_getline				*create_link(int const fd, t_getline *link);

#endif
