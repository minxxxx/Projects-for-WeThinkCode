/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_print_and_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <jtranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 22:36:58 by jtranchi          #+#    #+#             */
/*   Updated: 2018/02/26 22:41:34 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nm.h"

void			print_letter(t_lt *lt, char **tab)
{
	char			type;
	char			*section_name;

	type = 0;
	type = ((lt->type & N_TYPE) == N_INDR) ? 'I' : type;
	type = (!type && (lt->type & N_TYPE) == N_STAB) ? '-' : type;
	type = (!type && (lt->type & N_TYPE) == N_UNDF
		&& (lt->type & N_EXT) && lt->value != 0) ? 'C' : type;
	type = (!type && (lt->type & N_TYPE) == N_UNDF
		&& (lt->type & N_TYPE) == N_PBUD) ? 'u' : type;
	type = (!type && (lt->type & N_TYPE) == N_UNDF) ? 'U' : type;
	type = (!type && (lt->type & N_TYPE) == N_ABS) ? 'A' : type;
	if (!type && (lt->type & N_TYPE) == N_SECT)
	{
		section_name = tab[lt->sect - 1];
		type = (section_name && (!ft_strcmp(section_name, "__text")
			|| !ft_strcmp(section_name, "__data")
			|| !ft_strcmp(section_name, "__bss"))) ?
		ft_toupper(section_name[2]) : 'S';
	}
	ft_putchar(' ');
	ft_putchar(!(lt->type & N_EXT) ? ft_tolower(type) : type);
	ft_putchar(' ');
	ft_putendl(lt->str);
}

void			print_output_64(struct symtab_command *sym, void *ptr,
char **tab)
{
	uint32_t			i;
	char				*stringtable;
	struct nlist_64		*array;
	t_lt				*lt;
	t_lt				*tmp;

	lt = NULL;
	stringtable = (void*)ptr + sym->stroff;
	array = (void*)ptr + sym->symoff;
	i = -1;
	while (++i < sym->nsyms)
		if (!(array[i].n_type & N_STAB))
			add_list_64(&lt, stringtable + array[i].n_un.n_strx, array[i]);
	while (lt)
	{
		if (lt->value == 0 && (lt->type & N_TYPE) != N_UNDF)
			ft_putstr("0000000000000000");
		else
			print_addr(lt->value, 1);
		print_letter(lt, tab);
		tmp = lt->next;
		free(lt);
		lt = tmp;
	}
	free(tab);
}

void			print_output_32(struct symtab_command *sym, void *ptr,
char **tab)
{
	uint32_t			i;
	char				*stringtable;
	struct nlist		*array;
	t_lt				*lt;
	t_lt				*tmp;

	lt = NULL;
	stringtable = (void*)ptr + sym->stroff;
	array = (void*)ptr + sym->symoff;
	i = -1;
	while (++i < sym->nsyms)
		if (!(array[i].n_type & N_STAB))
			add_list_32(&lt, stringtable + array[i].n_un.n_strx, array[i]);
	while (lt)
	{
		if (lt->value == 0 && (lt->type & N_TYPE) != N_UNDF)
			ft_putstr("00000000");
		else
			print_addr(lt->value, 0);
		print_letter(lt, tab);
		tmp = lt->next;
		free(lt);
		lt = tmp;
	}
	free(tab);
}

char			**get_tab_64(char **tabl, struct segment_command_64 *seg)
{
	int					i;
	int					y;
	struct section_64	*sec;
	char				**tab2;

	i = 0;
	if ((int)seg->nsects < 1)
		return (tabl);
	while (tabl && tabl[i])
		i++;
	tab2 = (char**)malloc(sizeof(char*) * ((int)seg->nsects + i + 1));
	tab2[seg->nsects + i] = 0;
	i = 0;
	while (tabl && tabl[i])
		(tab2[i] = tabl[i]) ? (i++) : 0;
	sec = (struct section_64*)(seg + 1);
	y = -1;
	while (++y < (int)seg->nsects)
		(tab2[i++] = sec->sectname) ? (sec++) : 0;
	free(tabl);
	return (tab2);
}

char			**get_tab_32(char **tabl, struct segment_command *seg)
{
	int					i;
	int					y;
	struct section		*sec;
	char				**tab2;

	i = 0;
	if ((int)seg->nsects < 1)
		return (tabl);
	while (tabl && tabl[i])
		i++;
	tab2 = (char**)malloc(sizeof(char*) * ((int)seg->nsects + i + 1));
	tab2[seg->nsects + i] = 0;
	i = 0;
	while (tabl && tabl[i])
		(tab2[i] = tabl[i]) ? (i++) : 0;
	sec = (struct section*)(seg + 1);
	y = -1;
	while (++y < (int)seg->nsects)
		(tab2[i++] = sec->sectname) ? (sec++) : 0;
	free(tabl);
	return (tab2);
}
