/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:14:02 by ljoly             #+#    #+#             */
/*   Updated: 2017/03/02 15:08:16 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 4096

typedef struct		s_line
{
	char			*tab;
	int				fd;
	struct s_line	*next;
}					t_line;

int					get_next_line(const int fd, char **line);

#endif
