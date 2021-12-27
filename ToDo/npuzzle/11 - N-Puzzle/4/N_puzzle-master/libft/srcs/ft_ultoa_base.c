/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 11:20:57 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/25 11:40:33 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(unsigned long long int n, char *base)
{
	size_t					size;

	size = 1;
	while (n > 0)
	{
		size++;
		n /= ft_strlen(base);
	}
	return (size);
}

char			*ft_ultoa_base(unsigned long long int n, char *base)
{
	char					*result;
	size_t					size;
	unsigned long long int	j;
	unsigned long long int	i;
	unsigned long long int	nb;

	if (!base || ft_strlen(base) < 2)
		return (NULL);
	if (n == 0)
		return (ft_strdup("0"));
	nb = n;
	size = get_size(n, base);
	if (!(result = malloc(sizeof(result) * size)))
		return (result);
	j = 1;
	i = 1;
	while (nb / j > 0)
	{
		result[size - i++ - 1] = base[(nb / j) % ft_strlen(base)];
		j = j * ft_strlen(base);
	}
	result[size - 1] = '\0';
	return (result);
}
