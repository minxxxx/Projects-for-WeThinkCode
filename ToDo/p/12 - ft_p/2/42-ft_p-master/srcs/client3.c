/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 11:24:30 by jtranchi          #+#    #+#             */
/*   Updated: 2018/05/24 11:24:32 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ftp.h"

void	check_put2(char **tabl, t_mem *tmp, t_mem **mem)
{
	int				file;
	struct stat		buf;

	if (stat(tabl[1], &buf) == -1)
	{
		write_error("put", "file doesnt exists", 2);
		return ;
	}
	if ((file = open(tabl[1], O_RDONLY)) < 0)
	{
		write_error("put", "permission denied", 2);
		return ;
	}
	tmp->data = ft_strjoin("data ", tabl[1]);
	tmp->data = ft_strjoin_nf(tmp->data, " ", 1);
	tmp->len = ft_strlen(tmp->data);
	if (buf.st_size > 0)
		*mem = ft_memjoin(tmp, read_fd(file));
	else
		*mem = tmp;
	close(file);
}

int		check_put(t_mem **mem)
{
	t_mem	*tmp;
	char	**tabl;

	tmp = NULL;
	tmp = (t_mem*)malloc(sizeof(t_mem));
	remove_back(*mem);
	tabl = ft_strsplit((*mem)->data, ' ');
	if (!tabl[1])
		write_error("put", "please specify a file", 2);
	else
		check_put2(tabl, tmp, mem);
	ft_free_tabl(tabl);
	return (0);
}
