/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errno.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 10:19:26 by wide-aze          #+#    #+#             */
/*   Updated: 2015/06/13 10:32:24 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <libft.h>

void	init_ft_errno(void)
{
	errno = 0;
}

int		ft_errno(void)
{
	return (errno);
}

void	ft_puterrno(char *bef, char *aft, t_bool carr_ret, int fd)
{
	char	*tmp;

	if (!errno)
		return ;
	tmp = strerror(errno);
	if (bef)
		ft_putstr_fd(bef, fd);
	ft_putstr_fd(tmp, fd);
	if (aft)
		ft_putstr_fd(aft, fd);
	if (carr_ret == TRUE)
		ft_putchar_fd('\n', fd);
	ft_free(tmp);
}
