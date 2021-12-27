/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <jtranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 15:33:26 by jtranchi          #+#    #+#             */
/*   Updated: 2018/02/26 22:59:15 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/otool.h"

void		handle_64(struct mach_header_64 *header)
{
	int							nb;
	int							i;
	struct segment_command_64	*segment;
	struct segment_command_64	*tmp;

	i = -1;
	nb = header->ncmds;
	segment = (struct segment_command_64 *)(header + 1);
	while (++i < nb)
	{
		if (ft_strcmp(segment->segname, SEG_TEXT) == 0)
		{
			print_output_64(segment, header);
			tmp = NULL;
			break ;
		}
		else if (segment->cmd == LC_SEGMENT_64)
			tmp = segment;
		segment = (struct segment_command_64 *)((char *)segment +
		segment->cmdsize);
	}
	if (tmp)
		print_output_64(tmp, header);
}

void		handle_32(struct mach_header *header)
{
	int							nb;
	int							i;
	struct segment_command		*segment;
	struct segment_command		*tmp;

	i = -1;
	nb = header->ncmds;
	segment = (struct segment_command *)(header + 1);
	while (++i < nb)
	{
		if (ft_strcmp(segment->segname, SEG_TEXT) == 0)
		{
			print_output_32(segment, header);
			tmp = NULL;
			break ;
		}
		else if (segment->cmd == LC_SEGMENT)
			tmp = segment;
		segment = (struct segment_command *)((char *)segment +
		segment->cmdsize);
	}
	if (tmp)
		print_output_32(tmp, header);
}

void		otool(void *ptr)
{
	int magic;

	magic = *(int *)ptr;
	if (magic == (int)MH_MAGIC_64)
		handle_64((struct mach_header_64 *)ptr);
	else if (magic == (int)MH_MAGIC)
		handle_32((struct mach_header *)ptr);
	else if (magic == (int)FAT_CIGAM_64)
		find_fat_64(ptr);
	else if (magic == (int)FAT_CIGAM)
		find_fat_32(ptr);
}

void		process(char *argv)
{
	int				fd;
	char			*ptr;
	struct stat		buf;

	if ((fd = open(argv, O_RDONLY)) < 0)
		error(argv, "Permission or file doesnt exists");
	else if (fstat(fd, &buf) < 0)
		error(argv, "fstat");
	else if ((ptr = mmap(0, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) ==
	MAP_FAILED)
		error(argv, "mmap");
	else
	{
		ft_putstr(argv);
		ft_putendl(":");
		otool(ptr);
		if (munmap(ptr, buf.st_size) < 0)
			error(argv, "munmap");
	}
}

int			main(int argc, char **argv)
{
	int			i;

	i = 0;
	if (argc < 2)
		return (print_usage(argv));
	while (++i < argc)
		process(argv[i]);
	return (EXIT_SUCCESS);
}
