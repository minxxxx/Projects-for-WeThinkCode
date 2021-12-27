/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thendric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:33:27 by thendric          #+#    #+#             */
/*   Updated: 2016/12/19 15:59:12 by thendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 500

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

/*
** Struct to hold the line read from multiple
** file descriptors
** fd:		file descriptor
** line: 	text read from file
** next:	pointer to the next struct
*/

typedef struct			s_readfile
{
	int					fd;
	char				*line;
	char				*buf;
	size_t				cur_place;
	struct s_readfile	*next;

}						t_ext;

/*
** Declare all functions
*/

int						get_next_line(const int fd, char **line);

#endif
