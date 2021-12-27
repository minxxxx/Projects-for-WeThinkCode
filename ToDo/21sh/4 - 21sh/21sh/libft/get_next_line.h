/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 12:42:33 by sasiedu           #+#    #+#             */
/*   Updated: 2016/07/24 15:20:50 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE 512

typedef	struct			s_gnl
{
	char				*buf;
	int					fd;
	struct s_gnl		*next;
}						t_gnl;

int						get_next_line(int fd, char **line);

#endif
