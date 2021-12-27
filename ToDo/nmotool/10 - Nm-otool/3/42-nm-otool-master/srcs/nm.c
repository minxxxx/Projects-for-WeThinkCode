/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <jtranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 15:32:41 by jtranchi          #+#    #+#             */
/*   Updated: 2018/02/26 22:58:01 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nm.h"

static void		handle_64(void *ptr)
{
	uint32_t				i;
	struct mach_header_64	*header;
	struct load_command		*lc;
	struct symtab_command	*sym;
	char					**tabl;

	i = -1;
	header = (struct mach_header_64*)ptr;
	lc = (void*)ptr + sizeof(*header);
	tabl = NULL;
	sym = NULL;
	while (++i < header->ncmds)
	{
		if (lc->cmd == LC_SEGMENT_64)
			tabl = get_tab_64(tabl, (struct segment_command_64 *)lc);
		if (lc->cmd == LC_SYMTAB)
			sym = (struct symtab_command*)lc;
		lc = (void*)lc + lc->cmdsize;
	}
	print_output_64(sym, ptr, tabl);
}

static void		handle_32(void *ptr)
{
	uint32_t				i;
	struct mach_header		*header;
	struct load_command		*lc;
	struct symtab_command	*sym;
	char					**tabl;

	i = -1;
	header = (struct mach_header*)ptr;
	lc = (void*)ptr + sizeof(*header);
	tabl = NULL;
	sym = NULL;
	while (++i < header->ncmds)
	{
		if (lc->cmd == LC_SEGMENT)
			tabl = get_tab_32(tabl, (struct segment_command*)lc);
		if (lc->cmd == LC_SYMTAB)
			sym = (struct symtab_command*)lc;
		lc = (void*)lc + lc->cmdsize;
	}
	print_output_32(sym, ptr, tabl);
}

void			nm(void *ptr)
{
	int magic;

	magic = *(int *)ptr;
	if (magic == (int)MH_MAGIC_64)
		handle_64(ptr);
	else if (magic == (int)MH_MAGIC)
		handle_32(ptr);
	else if (magic == (int)FAT_CIGAM_64)
		find_fat_64(ptr);
	else if (magic == (int)FAT_CIGAM)
		find_fat_32(ptr);
}

static void		process(int argc, char *argv)
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
		if (argc > 2)
		{
			ft_putstr(argv);
			ft_putendl(":");
		}
		nm(ptr);
		if (munmap(ptr, buf.st_size) < 0)
			error(argv, "munmap");
	}
}

int				main(int argc, char **argv)
{
	int			i;

	i = 0;
	if (argc < 2)
		return (print_usage(argv));
	while (++i < argc)
		process(argc, argv[i]);
	return (EXIT_SUCCESS);
}
