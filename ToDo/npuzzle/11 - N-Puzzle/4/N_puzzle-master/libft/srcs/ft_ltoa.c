/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 09:43:48 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/01 11:35:42 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(long long int n)
{
	size_t					size;

	size = n < 0 ? 2 : 1;
	n = n < 0 ? -n : n;
	while (n > 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char			*ft_ltoa(long long int n)
{
	char					*result;
	size_t					size;
	unsigned long long int	j;
	unsigned long long int	i;
	unsigned long long int	nb;

	if (n == 0)
		return (ft_strdup("0"));
	nb = n < 0 ? -n : n;
	size = get_size(n);
	if (!(result = malloc(sizeof(result) * size)))
		return (result);
	if (n < 0)
		result[0] = '-';
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
