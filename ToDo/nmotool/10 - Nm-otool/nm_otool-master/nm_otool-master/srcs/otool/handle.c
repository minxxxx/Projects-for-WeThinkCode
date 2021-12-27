/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 15:36:44 by jcamhi            #+#    #+#             */
/*   Updated: 2017/07/25 18:26:40 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <otool.h>

void	handle_lc_seg_64(t_data *data, uint64_t offset, uint64_t tot_offset)
{
	struct segment_command_64	*seg;
	struct section_64			*sect;
	uint32_t					i;

	seg = data->binary + offset;
	sect = (void*)seg + sizeof(struct segment_command_64);
	if ((void*)seg > data->tend || (void*)sect > data->tend)
		return (set_error_and_return(data));
	i = 0;
	while (i < get_good_endian(*data, seg->nsects))
	{
		if ((void*)sect > data->tend)
			return (set_error_and_return(data));
		if (ft_strequ(sect->sectname, "__text") && ft_strequ(sect->segname,
				"__TEXT"))
			print(data, data->binary + get_good_endian(*data, sect->offset)
				+ tot_offset, get_good_endian(*data, sect->size),
				get_good_endian(*data, sect->addr));
		sect++;
		i++;
	}
}

void	handle_64(t_data *data, uint64_t offset)
{
	struct load_command		*lc;
	struct mach_header_64	*header;
	uint32_t				i;

	header = data->binary + offset;
	lc = data->binary + offset + sizeof(struct mach_header_64);
	i = 0;
	if ((void*)header > data->tend || (void*)lc > data->tend)
		return (set_error_and_return(data));
	while (i < header->ncmds)
	{
		if ((void*)lc > data->tend)
			return (set_error_and_return(data));
		if (lc->cmd == LC_SEGMENT_64)
			handle_lc_seg_64(data, (void*)lc - data->binary, offset);
		lc = (void*)lc + get_good_endianu(*data, lc->cmdsize);
		i++;
	}
}

void	handle_lc_seg_32(t_data *data, uint64_t offset, uint64_t tot_offset)
{
	struct segment_command	*seg;
	struct section			*sect;
	uint32_t				i;

	seg = data->binary + offset;
	sect = (void*)seg + sizeof(struct segment_command);
	if ((void*)seg > data->tend || (void*)sect > data->tend)
		return (set_error_and_return(data));
	i = 0;
	while (i < get_good_endian(*data, seg->nsects))
	{
		if ((void*)sect > data->tend)
			return (set_error_and_return(data));
		if (ft_strequ(sect->sectname, "__text") && ft_strequ(sect->segname,
				"__TEXT"))
			print(data, data->binary + get_good_endian(*data, sect->offset)
				+ tot_offset, get_good_endian(*data, sect->size),
				get_good_endian(*data, sect->addr));
		sect++;
		i++;
	}
}

void	handle_32(t_data *data, uint64_t offset)
{
	struct load_command	*lc;
	struct mach_header	*header;
	uint32_t			i;

	header = data->binary + offset;
	lc = data->binary + offset + sizeof(struct mach_header);
	if ((void*)header > data->tend || (void*)lc > data->tend)
		return (set_error_and_return(data));
	i = 0;
	while (i < get_good_endian(*data, header->ncmds))
	{
		if ((void*)lc > data->tend)
			return (set_error_and_return(data));
		if (get_good_endian(*data, lc->cmd) == LC_SEGMENT)
			handle_lc_seg_32(data, (void*)lc - data->binary, offset);
		lc = (void*)lc + get_good_endian(*data, lc->cmdsize);
		i++;
	}
}
