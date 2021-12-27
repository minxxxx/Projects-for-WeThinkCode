/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_lib.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 15:36:05 by jcamhi            #+#    #+#             */
/*   Updated: 2017/07/25 15:54:48 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

uint32_t		find_first_obj(t_data *data, uint32_t offset)
{
	void	*obj;

	obj = data->binary + offset;
	if ((void*)obj > data->tend)
	{
		data->error = 1;
		return (0);
	}
	while (!ft_strnequ(obj, "  `\n", 4))
	{
		obj++;
		if ((void*)obj > data->tend)
		{
			data->error = 1;
			return (0);
		}
	}
	return (obj + 4 - data->binary - sizeof(struct ar_hdr));
}

static int		handle_weird_lib(t_data *data, struct ranlib *symtab, t_opt opt)
{
	uint32_t		min;

	min = find_first_obj(data, (void*)symtab - data->binary);
	if (data->error == 1)
		return (1);
	if (handle_obj_sl(data, min, data->end - 1, opt) == 0)
		data->error = 1;
	return (1);
}

static int		init_nbr_symtab(t_data *data, uint32_t offset, uint32_t **nbr,
	struct ranlib **symtab)
{
	*nbr = (uint32_t*)(data->binary + offset + SARMAG + sizeof(struct ar_hdr)
		+ sizeof(char[20]));
	*symtab = data->binary + offset + SARMAG + sizeof(struct ar_hdr)
		+ sizeof(char[20]) + sizeof(uint32_t);
	if ((void*)*nbr > data->tend || (void*)*symtab > data->tend)
	{
		data->error = 1;
		return (0);
	}
	return (1);
}

static void		fln(uint32_t *min, uint32_t *max, struct ranlib **start,
	struct ranlib *symtab)
{
	*min = 0;
	*max = 0;
	*start = symtab;
}

void			handle_static_lib(t_data *data, uint32_t offset, t_opt opt)
{
	struct ranlib	*symtab;
	struct ranlib	*start;
	uint32_t		*nbr;
	uint32_t		min;
	uint32_t		max;

	if (init_nbr_symtab(data, offset, &nbr, &symtab) == 0)
		return ;
	fln(&min, &max, &start, symtab);
	if (*nbr == 0 && handle_weird_lib(data, symtab, opt))
		return ;
	while ((void*)symtab < (void*)start + *nbr)
	{
		min = ((min == 0 || symtab->ran_off < min) ? symtab->ran_off : min);
		max = (symtab->ran_off > max ? symtab->ran_off : max);
		symtab++;
		if ((void*)symtab > data->tend || min + offset > (uint32_t)data->tend
			|| max + offset > (uint32_t)data->tend)
			set_error_and_return(data);
	}
	if (handle_obj_sl(data, min + offset, max + offset, opt) == 0)
	{
		data->error = 1;
		return ;
	}
}
