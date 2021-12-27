/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_lib_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 15:55:04 by jcamhi            #+#    #+#             */
/*   Updated: 2017/07/25 16:01:38 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

static void		fin_obj_sl(t_data *data, t_opt opt)
{
	print_list(data, data->list, opt);
	delete_list(data->list);
	data->list = NULL;
	if (data->sections)
		free(data->sections);
	data->sections = NULL;
}

static	int		find_next_obj(t_data *data, void **obj)
{
	while (data->magic != MH_MAGIC_64 && data->magic != MH_MAGIC)
	{
		*obj = *obj + 1;
		if ((void*)(*obj) > data->tend)
			return (0);
		data->magic = *(uint32_t*)(*obj);
	}
	return (1);
}

static int		exec_obj(t_data *data, void *obj)
{
	if (data->magic == MH_MAGIC_64)
		handle_64(data, obj - data->binary, 0);
	else if (data->magic == MH_MAGIC)
		handle_32(data, obj - data->binary, 0);
	if (data->error)
		return (0);
	return (1);
}

static int		find_next_and_exec_obj(t_data *data, void **obj)
{
	data->magic = *(uint32_t*)(*obj);
	data->sections = NULL;
	if (find_next_obj(data, obj) == 0)
		return (0);
	if (exec_obj(data, *obj) == 0)
		return (0);
	return (1);
}

int				handle_obj_sl(t_data *data, uint32_t offset, uint32_t max,
		t_opt opt)
{
	struct ar_hdr	*hdr;
	void			*obj;

	hdr = data->binary + offset;
	obj = (void*)(hdr + 1);
	while (offset <= max)
	{
		if ((void*)hdr > data->tend || (void*)obj > data->tend)
			return (0);
		ft_printf("\n%s(%s):\n", data->av, hdr + 1);
		obj = (void*)(hdr + 1);
		if ((void*)obj > data->tend)
			return (0);
		if (find_next_and_exec_obj(data, &obj) == 0)
			return (0);
		offset += ft_atoi(hdr->ar_size) + sizeof(struct ar_hdr);
		fin_obj_sl(data, opt);
		hdr = data->binary + offset;
		if ((void*)hdr > data->tend)
			return (0);
	}
	return (1);
}
