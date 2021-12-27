/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 15:35:58 by jcamhi            #+#    #+#             */
/*   Updated: 2017/07/25 18:55:25 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

static void	create_list_from_sc64(t_data *data, int poids,
		struct symtab_command *sc, uint64_t offset)
{
	data->symoff = get_good_endian(*data, sc->symoff) + offset;
	data->stroff = get_good_endian(*data, sc->stroff) + offset;
	data->strsize = get_good_endian(*data, sc->strsize);
	data->nsyms = get_good_endian(*data, sc->nsyms);
	if (create_list_64(data, poids) == 0)
		data->error = 1;
	return ;
}

void		handle_64(t_data *data, uint64_t offset, size_t poids)
{
	struct mach_header_64	*header;
	struct load_command		*lc;
	uint32_t				i;

	header = (struct mach_header_64*)(data->binary + offset);
	lc = (void*)(data->binary + offset) + sizeof(struct mach_header_64);
	i = 0;
	if ((void*)header > data->tend || (void*)lc > data->tend
			|| find_boundaries_64(data, offset) == 0)
		return (set_error_and_return(data));
	while (i < header->ncmds)
	{
		if (get_good_endian(*data, lc->cmd) == LC_SYMTAB)
		{
			return (create_list_from_sc64(data, poids,
				(struct symtab_command*)lc, offset));
		}
		lc = (void*)lc + get_good_endian(*data, lc->cmdsize);
		if ((void*)lc > data->tend)
			return (set_error_and_return(data));
		i++;
	}
}

static void	create_list_form_sc32(t_data *data, size_t poids,
	struct symtab_command *sc, uint64_t offset)
{
	data->symoff = get_good_endian(*data, sc->symoff) + offset;
	data->stroff = get_good_endian(*data, sc->stroff) + offset;
	data->strsize = get_good_endian(*data, sc->strsize);
	data->nsyms = get_good_endian(*data, sc->nsyms);
	if (create_list_32(data, poids) == 0)
		data->error = 1;
	return ;
}

void		handle_32(t_data *data, uint64_t offset, size_t poids)
{
	struct mach_header		*header;
	struct load_command		*lc;
	uint32_t				i;

	header = (struct mach_header*)(data->binary + offset);
	lc = (void*)(data->binary + offset) + sizeof(struct mach_header);
	i = 0;
	if ((void*)header > data->tend || (void*)lc > data->tend ||
		find_boundaries_32(data, offset) == 0)
		return (set_error_and_return(data));
	while (i < header->ncmds)
	{
		if (get_good_endian(*data, lc->cmd) == LC_SYMTAB)
		{
			return (create_list_form_sc32(data, poids,
				(struct symtab_command*)lc, offset));
		}
		lc = (void*)lc + get_good_endian(*data, lc->cmdsize);
		if ((void*)lc > data->tend)
			return (set_error_and_return(data));
		i++;
	}
}
