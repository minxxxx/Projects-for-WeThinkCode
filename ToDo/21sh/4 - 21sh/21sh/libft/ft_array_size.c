/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 11:46:42 by sasiedu           #+#    #+#             */
/*   Updated: 2016/07/24 17:33:13 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_array_size(char **tab)
{
	size_t	size;

	if (tab == NULL)
		return (0);
	size = 0;
	while (tab[size] != NULL)
		size++;
	return (size);
}
