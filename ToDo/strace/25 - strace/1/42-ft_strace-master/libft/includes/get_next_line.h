/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmontija <jmontija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 13:06:08 by jtranchi          #+#    #+#             */
/*   Updated: 2016/12/12 01:18:04 by jmontija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include "libft.h"

# define BUFF_SIZE 4096

typedef int	t_bool;

typedef	struct		s_get
{
	int				fd;
	int				ret;
}					t_get;

typedef	struct		s_lst
{
	int				fd;
	char			*rest;
	struct s_lst	*next;
}					t_lst;

int					get_next_line(int const fd, char **line);

#endif
