/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 15:35:49 by jcamhi            #+#    #+#             */
/*   Updated: 2017/07/25 18:50:21 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

char		get_char_for_symtype_64(struct nlist_64 elem, t_data data,
		t_symbole *ret)
{
	if ((elem.n_type & N_STAB) != 0)
		ret->is_debug = 1;
	if ((elem.n_type & N_TYPE) == N_UNDF)
		if (elem.n_value != 0)
			return ('C');
		else
			return ('U');
	else if ((elem.n_type & N_TYPE) == N_ABS)
		return ('A');
	else if ((elem.n_type & N_TYPE) == N_INDR)
		return ('I');
	else if ((elem.n_type & N_TYPE) == N_PBUD)
		return ('U');
	if (elem.n_sect - 1 <= data.nbsect)
		return (data.sections[elem.n_sect - 1]);
	else
		return ('S');
	return ('S');
}

char		get_char_for_symtype_32(struct nlist elem, t_data data,
		t_symbole *ret)
{
	if ((elem.n_type & N_STAB) != 0)
		ret->is_debug = 1;
	if ((elem.n_type & N_TYPE) == N_UNDF)
		if (elem.n_value != 0)
			return ('C');
		else
			return ('U');
	else if ((elem.n_type & N_TYPE) == N_ABS)
		return ('A');
	else if ((elem.n_type & N_TYPE) == N_INDR)
		return ('I');
	else if ((elem.n_type & N_TYPE) == N_PBUD)
		return ('U');
	else if ((elem.n_type & N_TYPE) == N_SECT)
	{
		if (elem.n_sect - 1 <= data.nbsect)
			return (data.sections[elem.n_sect - 1]);
		else
			return ('S');
	}
	return ('S');
}

t_symbole	*init_symbole_for_64(t_data *data, uint64_t offset, t_symbole *ret)
{
	struct nlist_64	*nl;
	char			*strings;

	strings = data->binary + data->stroff;
	if ((void*)strings > data->tend)
		return (NULL);
	nl = (data->binary + offset);
	if ((ret->n_strx = get_good_endian(*data, (int64_t)nl->n_un.n_strx)) != 0)
	{
		if ((void*)(strings + ret->n_strx) > data->tend)
			return (NULL);
		ret->str = ft_strdup(strings + ret->n_strx);
	}
	else
		ret->str = NULL;
	ret->value = get_good_endian(*data, nl->n_value);
	ret->is_debug = 0;
	ret->sym = get_char_for_symtype_64(*nl, *data, ret);
	if ((nl->n_type & N_EXT) == 0)
		ret->sym = ft_tolower(ret->sym);
	return (ret);
}

t_symbole	*init_symbole_for_32(t_data *data, uint64_t offset, t_symbole *ret)
{
	struct nlist	*nl;
	char			*strings;

	strings = data->binary + data->stroff;
	if ((void*)strings > data->tend)
		return (NULL);
	nl = data->binary + offset;
	if ((void*)nl > data->tend)
		return (NULL);
	if ((ret->n_strx = get_good_endian(*data, (int64_t)nl->n_un.n_strx)) != 0)
	{
		if ((void*)(strings + ret->n_strx) > data->tend)
			return (NULL);
		ret->str = ft_strdup(strings + ret->n_strx);
	}
	else
		ret->str = NULL;
	ret->value = get_good_endian(*data, nl->n_value);
	ret->is_debug = 0;
	ret->sym = get_char_for_symtype_32(*nl, *data, ret);
	if ((nl->n_type & N_EXT) == 0)
		ret->sym = ft_tolower(ret->sym);
	return (ret);
}

t_symbole	*create_elem(t_data *data, uint64_t offset, size_t poids)
{
	t_symbole	*ret;

	ret = (t_symbole*)malloc(sizeof(t_symbole));
	ret->next = NULL;
	ret->addr = data->binary + offset;
	ret->offset = offset;
	ret->magic = data->magic;
	ret->poids = poids;
	if (data->magic == MH_MAGIC_64)
		ret = init_symbole_for_64(data, offset, ret);
	else if (data->magic == MH_MAGIC || data->magic == MH_CIGAM)
		ret = init_symbole_for_32(data, offset, ret);
	if (!ret)
		data->error = 1;
	return (ret);
}
