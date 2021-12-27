/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 16:36:59 by thou              #+#    #+#             */
/*   Updated: 2017/02/09 17:29:00 by thou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 42

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

# define SAFEMALLOC(x) if (!x) return (-1);
# define FIN(x) if (!x) return (0);

int					get_next_line(int const fd, char **line);

#endif
