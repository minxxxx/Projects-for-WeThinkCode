/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 09:43:48 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/25 11:36:31 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(unsigned long long int n)
{
	size_t					size;

	size = 1;
	while (n > 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char			*ft_ultoa(unsigned long long int n)
{
	char					*result;
	size_t					size;
	unsigned long long int	j;
	unsigned long long int	i;
	unsigned long long int	nb;

	if (n == 0)
		return (ft_strdup("0"));
	nb = n;
	size = get_size(n);
	if (!(result = malloc(sizeof(result) * size)))
		return (result);
	j = 1;
	i = 1;
	while (nb / j > 0)
	{
		result[size - i++ - 1] = (nb / j) % 10 + '0';
		j = j * 10;
	}
	result[size - 1] = '\0';
	return (result);
}
