/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endian.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 18:46:49 by jcamhi            #+#    #+#             */
/*   Updated: 2017/07/25 18:48:18 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libbinary.h>
#include <stdlib.h>

void		*convert_chunk_alloc(void *binary, size_t size)
{
	char		*ret;
	char		*bc;
	char		*tmp;
	size_t		i;

	ret = (char*)malloc(size);
	bc = (char*)binary;
	tmp = ret;
	i = 0;
	while (i < size)
	{
		*(tmp + 0) = *(bc + 3);
		*(tmp + 1) = *(bc + 2);
		*(tmp + 2) = *(bc + 1);
		*(tmp + 3) = *(bc + 0);
		tmp += 4;
		bc += 4;
		i += 4;
	}
	return (ret);
}

int64_t		convert_chunk(void *binary)
{
	char		*ret;
	int64_t		tm;
	char		*bc;
	char		*tmp;
	size_t		i;

	ret = (char*)malloc(sizeof(int64_t));
	bc = (char*)binary;
	tmp = ret;
	i = 0;
	while (i < sizeof(int64_t))
	{
		*(tmp + 0) = *(bc + 3);
		*(tmp + 1) = *(bc + 2);
		*(tmp + 2) = *(bc + 1);
		*(tmp + 3) = *(bc + 0);
		tmp += 4;
		bc += 4;
		i += 4;
	}
	tm = *(int64_t*)ret;
	free(ret);
	return (tm);
}

uint64_t	convert_chunk_u(void *binary)
{
	char		*ret;
	uint64_t	tm;
	char		*bc;
	char		*tmp;
	size_t		i;

	ret = (char*)malloc(sizeof(uint64_t));
	bc = (char*)binary;
	tmp = ret;
	i = 0;
	while (i < sizeof(uint64_t))
	{
		*(tmp + 0) = *(bc + 3);
		*(tmp + 1) = *(bc + 2);
		*(tmp + 2) = *(bc + 1);
		*(tmp + 3) = *(bc + 0);
		tmp += 4;
		bc += 4;
		i += 4;
	}
	tm = *(uint64_t*)ret;
	free(ret);
	return (tm);
}
