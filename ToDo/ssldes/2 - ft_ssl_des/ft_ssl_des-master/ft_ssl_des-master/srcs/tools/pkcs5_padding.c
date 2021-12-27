/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pkcs5_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:32:04 by jcamhi            #+#    #+#             */
/*   Updated: 2018/11/12 17:32:04 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

/*
** Padds the given data according to the pkcs5 specifications.
** Dynamically allocates memory, so be sure to free the output when done
**  using it.
** The new size will be stored in size.
*/

uint8_t	*pkcs5_padding(const uint8_t *original_data,
	size_t *size, size_t padd_multiple)
{
	size_t	new_size;
	uint8_t	*ret;

	new_size = ((*size) / padd_multiple + 1) * padd_multiple;
	if (new_size == *size)
		new_size += padd_multiple;
	ret = malloc(new_size * sizeof(char));
	if (!ret)
		return (NULL);
	ft_memcpy(ret, original_data, *size);
	ft_memset(ret + *size, new_size - *size, new_size - *size);
	*size = new_size;
	return (ret);
}
