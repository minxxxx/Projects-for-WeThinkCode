/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_binary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 15:41:45 by jcamhi            #+#    #+#             */
/*   Updated: 2017/07/25 13:14:15 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libbinary.h>

char	*map_binary(const char *file, off_t *size)
{
	char		*ret;
	int			fd;
	struct stat	buf;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (NULL);
	if (fstat(fd, &buf) < 0)
	{
		close(fd);
		return (NULL);
	}
	*size = buf.st_size;
	if ((ret = mmap(0, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0))
			== MAP_FAILED)
	{
		close(fd);
		return (NULL);
	}
	close(fd);
	return (ret);
}
