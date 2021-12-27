/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_boundaries_32.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 15:35:55 by jcamhi            #+#    #+#             */
/*   Updated: 2017/07/25 18:53:42 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

static int	get_good_sign_32(t_data *data, struct section *tab,
	uint32_t i, uint32_t j)
{
	if ((void*)(tab + j) > data->tend)
		return (-1);
	if (ft_strequ(tab[j].sectname, "__text"))
		data->sections[j + i] = 'T';
	else if (ft_strequ(tab[j].sectname, "__bss"))
		data->sections[j + i] = 'B';
	else if (ft_strequ(tab[j].sectname, "__data"))
		data->sections[j + i] = 'D';
	else
		data->sections[j + i] = 'S';
	return (1);
}

static int	handle_seg_header_32(t_data *data, struct load_command *lc,
		uint32_t i)
{
	struct segment_command	*sc;
	struct section			*tab;
	uint32_t				j;

	j = 0;
	sc = (struct segment_command*)lc;
	tab = (void*)sc + sizeof(struct segment_command);
	if ((void*)sc > data->tend || (void*)tab > data->tend)
		return (-1);
	if (get_good_endian(*data, sc->nsects) == 0)
		return (i);
	while (j < get_good_endian(*data, sc->nsects))
	{
		data->nbsect++;
		if (get_good_sign_32(data, tab, i, j) == -1)
			return (-1);
		j++;
	}
	return (i + j);
}

int			fill_data_sections(t_data *data, struct mach_header *header,
	struct load_command *lc)
{
	uint32_t			i;
	int32_t				j;

	i = 0;
	j = 0;
	while (i < get_good_endian(*data, header->ncmds))
	{
		if (get_good_endian(*data, lc->cmd) == LC_SEGMENT)
			j = handle_seg_header_32(data, lc, j);
		if (j == -1)
			return (0);
		lc = (void*)lc + get_good_endian(*data, lc->cmdsize);
		if ((void*)lc > data->tend)
			return (0);
		i++;
	}
	return (1);
}

int			find_boundaries_32(t_data *data, uint64_t offset)
{
	struct mach_header			*header;
	struct load_command			*lc;

	header = (struct mach_header*)(data->binary + offset);
	if ((void*)header > data->tend)
		return (0);
	lc = (void*)(header) + sizeof(*header);
	if ((void*)lc > data->tend)
		return (0);
	data->nbsect = 0;
	if (!(data->sections = (char*)malloc(get_good_endian(*data, header->ncmds)
					+ 50)))
		return (0);
	data->sections = ft_memset(data->sections, 'S',
			get_good_endian(*data, header->ncmds));
	data->sections[get_good_endian(*data, header->ncmds)] = '\0';
	return (fill_data_sections(data, header, lc));
}
