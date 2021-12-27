/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mach.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 15:01:17 by sasiedu           #+#    #+#             */
/*   Updated: 2017/07/02 14:03:41 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mach.h"

char	symbol_type_section_32(t_mach_file *mach, t_sym *sym)
{
	size_t				i;
	size_t				nsecs;
	uint32_t			off;
	t_mach_cmd			*cmd;
	t_mach_section		*s;

	i = -1;
	off = 0;
	nsecs = 1;
	while (++i < mach->header->ncmds)
	{
		cmd = (t_mach_cmd *)(mach->cmd_data + off);
		if (cmd->cmd == MH_SEG)
		{
			if (nsecs + cmd->nsects > sym->nlist->n_sect)
				break ;
			nsecs += cmd->nsects;
		}
		off += cmd->cmdsize;
	}
	if (i == mach->header->ncmds)
		return ('?');
	s = (t_mach_section *)(mach->cmd_data + (off + sizeof(t_mach_cmd)
				+ (sym->nlist->n_sect - nsecs) * sizeof(t_mach_section)));
	return (ft_get_type(s->segname, s->sectname, (N_EXT & sym->nlist->n_type)));
}

char	symbol_type_section_64(t_mach_file *mach, t_sym *sym)
{
	size_t				i;
	size_t				nsecs;
	uint32_t			off;
	t_mach_cmd_64		*cmd;
	t_mach_section_64	*s;

	i = -1;
	off = 0;
	nsecs = 1;
	while (++i < mach->header->ncmds)
	{
		cmd = (t_mach_cmd_64 *)(mach->cmd_data + off);
		if (cmd->cmd == MH_SEG_64)
		{
			if (nsecs + cmd->nsects >= sym->nlist->n_sect)
				break ;
			nsecs += cmd->nsects;
		}
		off += cmd->cmdsize;
	}
	if (i == mach->header->ncmds)
		return ('?');
	s = (t_mach_section_64 *)(mach->cmd_data + (off + sizeof(t_mach_cmd_64) +
				(sym->nlist->n_sect - nsecs) * sizeof(t_mach_section_64)));
	return (ft_get_type(s->segname, s->sectname, (N_EXT & sym->nlist->n_type)));
}

char	symbol_type(t_mach_file *mach, t_sym *sym)
{
	if ((N_TYPE & sym->nlist->n_type) == 0x0 && sym->nlist->n_value == 0)
		return ((N_EXT & sym->nlist->n_type) ? 'U' : 'u');
	if ((N_TYPE & sym->nlist->n_type) == 0x0)
		return ((N_EXT & sym->nlist->n_type) ? 'C' : 'c');
	if ((N_TYPE & sym->nlist->n_type) == 0x2)
		return ((N_EXT & sym->nlist->n_type) ? 'A' : 'a');
	if ((N_TYPE & sym->nlist->n_type) == 0xe)
	{
		if (mach->is_64)
			return (symbol_type_section_64(mach, sym));
		else
			return (symbol_type_section_32(mach, sym));
	}
	return ('?');
}

void	mach_symbol_table(t_mach_file *mach)
{
	t_sym		syms[mach->sym_tab->nsyms];
	uint32_t	i;
	size_t		off;

	i = -1;
	off = 0;
	if (mach->is_rev)
		rev_symtab(mach->sym_tab);
	while (++i < mach->sym_tab->nsyms)
	{
		syms[i].nlist = (t_nlist *)(mach->file_data + mach->sym_tab->symoff +
				off);
		if (mach->is_rev)
			rev_bytes(&syms[i].nlist->str_index, 4);
		if (mach->is_rev)
			rev_bytes(&syms[i].nlist->n_desc, 2);
		if (mach->is_rev)
			rev_bytes(&syms[i].nlist->n_value, 4);
		syms[i].name = mach->file_data + mach->sym_tab->stroff +
				syms[i].nlist->str_index;
		syms[i].type = symbol_type(mach, &syms[i]);
		off += (mach->is_64) ? 16 : 12;
	}
	process_syms(mach, &syms[0], mach->sym_tab->nsyms);
}
