/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd_ret.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 08:21:24 by wide-aze          #+#    #+#             */
/*   Updated: 2015/10/27 08:25:02 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_putendl_fd_ret(const char *msg, int fd, int toreturn)
{
	if (msg)
		ft_putendl_fd(msg, fd);
	return (toreturn);
}
