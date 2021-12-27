/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 15:35:51 by jcamhi            #+#    #+#             */
/*   Updated: 2017/07/25 13:17:59 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

int	create_list_64(t_data *data, size_t poids)
{
	uint32_t		i;

	i = 0;
	data->list = NULL;
	while (i < data->nsyms)
	{
		if ((void*)(data->symoff + i * sizeof(struct nlist_64)) > data->tend)
		{
			data->error = 1;
			return (0);
		}
		data->list = add_elem_end(data, data->list, (uint64_t)(data->symoff +
					i * sizeof(struct nlist_64)), poids);
		i++;
	}
	data->list = ft_sort(data->list);
	return (1);
}

int	create_list_32(t_data *data, size_t poids)
{
	uint32_t		i;

	i = 0;
	data->list = NULL;
	while (i < data->nsyms)
	{
		if ((void*)(data->symoff + i * sizeof(struct nlist)) > data->tend)
			return (0);
		data->list = add_elem_end(data, data->list, (uint64_t)(data->symoff +
					i * sizeof(struct nlist)), poids);
		i++;
	}
	data->list = ft_sort(data->list);
	return (1);
}
