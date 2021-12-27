/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 15:31:53 by sasiedu           #+#    #+#             */
/*   Updated: 2017/07/02 13:50:05 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

size_t		my_read(void *dst, size_t size, size_t offset, void *src)
{
	size_t			index;
	unsigned char	*a;
	unsigned char	*b;

	if (size == 0 || src == NULL || dst == NULL)
		return (0);
	index = 0;
	a = (unsigned char *)dst;
	b = (unsigned char *)src;
	while (index < size)
	{
		a[index] = b[index + offset];
		index++;
	}
	return (index - offset);
}

void		get_file_type(t_file *file, unsigned char *src)
{
	my_read(&file->file_magic, sizeof(uint32_t), 0, src);
	if (file->file_magic == MH_MAGIC || file->file_magic == MH_CIGAM ||
			file->file_magic == MH_MAGIC_64 ||
			file->file_magic == MH_CIGAM_64 ||
			file->file_magic == ELF_MAGIC ||
			file->file_magic == ELF_CIGAM ||
			file->file_magic == FAT_MAGIC ||
			file->file_magic == FAT_CIGAM)
	{
		file->is_valid = 1;
		file->is_archive = 0;
		return ;
	}
	my_read(&file->archive_magic, sizeof(uint64_t), 0, src);
	if (file->archive_magic == ARH_MAGIC ||
			file->archive_magic == ARCH_CIGAM)
	{
		file->is_valid = 1;
		file->is_archive = 1;
	}
}

int			open_file(t_file *file, char *filename)
{
	int				fd;
	unsigned char	*src;
	struct stat		buf;

	file->is_valid = 0;
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (-1);
	if (fstat(fd, &buf) == -1)
		return (1);
	src = (unsigned char *)mmap(NULL, buf.st_size, PROT_READ | PROT_WRITE,
			MAP_PRIVATE, fd, 0);
	if (src == NULL)
		return (1);
	get_file_type(file, src);
	if (file->is_valid)
	{
		file->fd = fd;
		file->size = buf.st_size;
		file->data = src;
	}
	return (0);
}
