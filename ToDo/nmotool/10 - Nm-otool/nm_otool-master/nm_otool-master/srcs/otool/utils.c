/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 16:02:48 by jcamhi            #+#    #+#             */
/*   Updated: 2017/07/25 18:43:07 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <otool.h>

int64_t		get_good_endian(t_data data, int64_t nbr)
{
	if (data.endiancast)
		return (convert_chunk(&nbr));
	return (nbr);
}

int			get_good_endianu(t_data data, uint64_t nbr)
{
	if (data.endiancast)
		return (convert_chunk_u(&nbr));
	return (nbr);
}

void		set_error_and_return(t_data *data)
{
	data->error = 1;
	return ;
}
