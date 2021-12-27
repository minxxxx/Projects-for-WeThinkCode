/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 15:35:59 by jcamhi            #+#    #+#             */
/*   Updated: 2017/07/25 15:10:04 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

void			add_elem_start(t_data *data, t_symbole **list, uint64_t offset,
	size_t poids)
{
	t_symbole	*elem;

	elem = create_elem(data, offset, poids);
	*list = elem;
}

t_symbole		*add_elem_end(t_data *data, t_symbole *list, uint64_t offset,
	size_t poids)
{
	t_symbole	*elem;
	t_symbole	*fl;

	if (!(elem = create_elem(data, offset, poids)))
		return (NULL);
	if (!list)
		return (elem);
	fl = list;
	while (list->next != NULL)
		list = list->next;
	list->next = elem;
	return (fl);
}

void			delete_list(t_symbole *list)
{
	t_symbole	*prev;

	while (list)
	{
		if (list->str)
			free(list->str);
		prev = list;
		list = list->next;
		free(prev);
	}
}

static void		print_not_u(t_symbole *list)
{
	if (list->magic == MH_MAGIC_64 || list->magic == MH_MAGIC_64)
		ft_printf("%016llx ", list->value);
	else if (list->magic == MH_MAGIC || list->magic == MH_CIGAM)
		ft_printf("%08llx ", list->value);
}

void			print_list(t_data *data, t_symbole *list, t_opt opt)
{
	while (list)
	{
		if (!list->is_debug && !(opt.u && ft_toupper(list->sym) != 'U')
			&& !(opt.um && ft_toupper(list->sym) == 'U'))
		{
			if (!opt.u && ft_toupper(list->sym) != 'U')
				print_not_u(list);
			else if (!opt.u)
			{
				if (list->magic == MH_MAGIC_64 || list->magic == MH_CIGAM_64)
					ft_printf("%16c ", ' ');
				else if (list->magic == MH_MAGIC || list->magic == MH_CIGAM)
					ft_printf("%8c ", ' ');
			}
			if (!opt.u)
				ft_printf("%c ", list->sym);
			if (list->str)
				ft_printf("%s\n", list->str);
			else
				ft_printf("\n");
		}
		list = list->next;
	}
	data = NULL;
}
