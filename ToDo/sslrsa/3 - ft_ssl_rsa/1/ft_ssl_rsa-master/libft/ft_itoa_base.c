/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 09:52:39 by jtranchi          #+#    #+#             */
/*   Updated: 2018/08/25 16:46:49 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static	char	*itoa_store(intmax_t *num, int base, int *i, int *count)
{
	char	*new;
	long	tmp;
	int		len;

	len = 0;
	if (*num < 0)
	{
		if (base == 10)
			(*i)++;
		(*num) *= -1;
	}
	tmp = *num;
	while (tmp >= base)
	{
		tmp /= base;
		len++;
	}
	len++;
	*count = (len + (*i));
	new = (char*)malloc(sizeof(char) * (*count) + 1);
	return (new);
}

char			*ft_itoa_base(intmax_t n, int base)
{
	char		*base_d;
	char		*new;
	intmax_t	num;
	int			i;
	int			count;

	i = 0;
	count = 0;
	num = n;
	base_d = ft_strdup("0123456789abcdef");
	new = itoa_store(&num, base, &i, &count);
	if (!new)
		return (NULL);
	if (i > 0)
		new[0] = '-';
	new[count] = '\0';
	while (num >= base)
	{
		new[--count] = base_d[num % base];
		num /= base;
	}
	new[i] = base_d[num % base];
	ft_strdel(&base_d);
	return (new);
}
