/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 14:24:10 by sasiedu           #+#    #+#             */
/*   Updated: 2016/06/04 13:24:54 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

typedef	struct		s_gnlfd
{
	char			*buff;
	int				fd;
	int				length;
	int				offset;
	int				i;
	struct s_gnlfd	*next;
}					t_gnlfd;

# ifndef EOF
#  define EOF -1
# endif

# define GNL_BUFF 512

# define GNL_SUCCES 1
# define GNL_EOF 0
# define GNL_ERROR -1

int					get_next_line(int const fd, char **line);

#endif
