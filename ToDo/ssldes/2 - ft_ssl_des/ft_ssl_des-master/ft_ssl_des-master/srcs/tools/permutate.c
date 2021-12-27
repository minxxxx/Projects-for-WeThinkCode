/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:32:02 by jcamhi            #+#    #+#             */
/*   Updated: 2018/11/12 17:36:34 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

/*
** Effectuates the permutation given in the permutation on in.
** The output is stored in the out parameter. in and out can overlap.
** Permutation must be at least size bytes long, in and out must
** be at least size bits long.
** The permutation parameter is given as in the FIPS Pub 46-3.
** Params :
** in : input, pointer to a memory address containing at least size bits.
** out : output, same thing
** permutation : permutation array, at least size bytes long
** size : bit size of in and out, byte size of permutation.
** this parameter must be a multiple of 8
** Return value : 1 if successfull, 0 else.
*/

int8_t	permutate(const int8_t *in, int8_t *out, const int *permutation,
	size_t size)
{
	size_t		i;
	char		b[64 / 8];
	char		*buffer;

	if (size <= 64 / 8)
		buffer = b;
	else
		buffer = malloc(size);
	if (!buffer)
		return (0);
	ft_bzero(buffer, (size + 7) / 8);
	i = 0;
	while (i < size)
	{
		if ((in[(permutation[i] - 1) / 8] >> (7 - ((permutation[i] - 1)
			% 8))) & 1)
			buffer[i / 8] |= (1 << (7 - (i % 8)));
		i++;
	}
	ft_memcpy(out, buffer, (size + 7) / 8);
	if (size > 64 / 8)
		free(buffer);
	return (1);
}
