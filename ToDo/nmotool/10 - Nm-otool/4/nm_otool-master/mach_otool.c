/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mach_otool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 02:54:26 by sasiedu           #+#    #+#             */
/*   Updated: 2017/07/02 14:15:13 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void	print_line(unsigned char *buf, uint32_t size, uint32_t i)
{
	uint32_t	y;

	y = -1;
	while (++y < 16 && i < size)
	{
		ft_putstr(" ");
		print_value((uint32_t)buf[y], 1);
		i++;
	}
}

void	found_section_32(t_mach_section *s, uint8_t is_64, void *data)
{
	uint64_t		i;
	unsigned char	*buf;

	buf = (unsigned char *)(data + s->offset);
	if (!ft_strcmp("__text", s->sectname))
		ft_putendl("(__TEXT,__text) section");
	else
		ft_putendl("(__DATA,__data) section");
	i = 0;
	while (i < s->size)
	{
		print_value(s->addr + i, (is_64) ? 15 : 7);
		ft_putstr("       ");
		print_line(&buf[i], s->size, i);
		ft_putchar('\n');
		i += 16;
	}
}

void	found_section_64(t_mach_section_64 *s, uint8_t is_64, void *data)
{
	uint64_t		i;
	unsigned char	*buf;

	buf = (unsigned char *)(data + s->offset);
	if (!ft_strcmp("__text", s->sectname))
		ft_putendl("Contents of (__TEXT,__text) section");
	else
		ft_putendl("Contents of (__DATA,__data) section");
	i = 0;
	while (i < s->size)
	{
		print_value_64(s->addr + i, (is_64) ? 15 : 7);
		ft_putstr("       ");
		print_line(&buf[i], s->size, i);
		ft_putchar('\n');
		i += 16;
	}
}

void	otool_section_32(t_mach_file *m, char *sec,
		char *seg, uint32_t off)
{
	size_t			i;
	size_t			j;
	t_mach_section	*s;
	t_mach_cmd		*cmd;

	i = -1;
	while (++i < m->header->ncmds)
	{
		cmd = (t_mach_cmd *)(m->cmd_data + off);
		if (cmd->cmd == MH_SEG)
		{
			j = -1;
			while (++j < cmd->nsects)
			{
				s = (t_mach_section *)((char *)cmd + (sizeof(t_mach_cmd)
							+ j * sizeof(t_mach_section)));
				if (!ft_strcmp(s->sectname, sec) &&
						!ft_strcmp(s->segname, seg))
					return (found_section_32(s, m->is_64, m->mach_data));
			}
		}
		off += cmd->cmdsize;
	}
}

void	otool_section_64(t_mach_file *m, char *sec,
		char *seg, uint32_t off)
{
	size_t				i;
	size_t				j;
	t_mach_section_64	*s;
	t_mach_cmd_64		*cmd;

	i = -1;
	while (++i < m->header->ncmds)
	{
		cmd = (t_mach_cmd_64 *)(m->cmd_data + off);
		if (cmd->cmd == MH_SEG_64)
		{
			j = -1;
			while (++j < cmd->nsects)
			{
				s = (t_mach_section_64 *)((char *)cmd + (sizeof(t_mach_cmd_64)
							+ j * sizeof(t_mach_section_64)));
				if (!ft_strcmp(s->sectname, sec) &&
						!ft_strcmp(s->segname, seg))
					return (found_section_64(s, m->is_64, m->mach_data));
			}
		}
		off += cmd->cmdsize;
	}
}
