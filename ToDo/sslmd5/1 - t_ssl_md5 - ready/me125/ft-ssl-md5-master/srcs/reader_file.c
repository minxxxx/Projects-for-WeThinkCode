/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 13:43:03 by apakhomo          #+#    #+#             */
/*   Updated: 2018/02/03 13:43:03 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl_des.h"

ssize_t	allocsize(char *file)
{
	char	buf;
	int		fd;
	int		ret;
	ssize_t	size;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (-1);
	size = 0;
	while ((ret = read(fd, &buf, 1)) == 1)
		size++;
	close(fd);
	if (ret == 0)
		return (size);
	else
		return (-1);
}

void	*readoutfile(char *file, size_t *size)
{
	unsigned char	*buf;
	ssize_t			ret;
	int				fd;

	if ((int)(*size = allocsize(file)) == -1)
		exit_error(errno, NULL);
	if ((buf = ft_memalloc(*size + 1)) == NULL)
		exit_error(errno, NULL);
	if ((fd = open(file, O_RDONLY)))
	{
		ret = read(fd, buf, *size);
		close(fd);
		if (ret == (ssize_t)*size)
			return (buf);
	}
	free(buf);
	exit_error(errno, NULL);
	return (NULL);
}

void	printinfile(char *file, UC *str, size_t size)
{
	int		fd;

	if ((fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644)) == -1)
		exit_error(errno, str);
	if ((write(fd, str, size)) == -1)
	{
		close(fd);
		exit_error(errno, str);
	}
	close(fd);
}
