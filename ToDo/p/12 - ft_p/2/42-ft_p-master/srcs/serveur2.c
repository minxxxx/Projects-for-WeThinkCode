/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 15:13:11 by jtranchi          #+#    #+#             */
/*   Updated: 2018/05/12 15:13:12 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ftp.h"

void	print_usage(void)
{
	ft_putendl("usage : <port>");
	exit(0);
}

int		check_put_data(t_mem *mem, int socket)
{
	char	**tabl;
	int		fd;
	int		i;
	int		ret;

	ret = -1;
	tabl = ft_strsplit(mem->data, ' ');
	if (ft_strequ(tabl[0], "data") == 1 && tabl[1])
	{
		fd = open(tabl[1], O_RDWR | O_CREAT, 0666);
		i = 4 + 1 + ft_strlen(tabl[1]);
		while (++i < mem->len)
			write(fd, &mem->data[i], 1);
		write_success("put", socket);
		close(fd);
		ret = 0;
	}
	ft_free_tabl(tabl);
	return (ret);
}
