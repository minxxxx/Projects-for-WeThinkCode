/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 10:42:25 by ggroener          #+#    #+#             */
/*   Updated: 2016/05/14 10:44:02 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	reverse_str(char *s)
{
	char	tmp;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s) - 1;
	while (i < j || (((ft_strlen(s)) % 2 == 0) && i > j))
	{
		if (*s == '-')
			i++;
		tmp = *(s + i);
		*(s + i) = *(s + j);
		*(s + j) = tmp;
		i++;
		j--;
	}
}

static int	get_int_len(int n)
{
	int	len;

	len = 0;
	while (n /= 10)
		len++;
	return (n);
}

char		*ft_itoa(int n)
{
	int		sign;
	int		i;
	char	*ptr;

	i = 0;
	sign = (n < 0) ? -1 : 1;
	n *= sign;
	if (n < 0 && (ptr = (char *)malloc(sizeof(char) * 12)))
		return (ft_strcpy(ptr, "-2147483648"));
	ptr = NULL;
	if ((ptr = (char *)malloc(sizeof(char) + get_int_len(n))))
	{
		if (sign == -1)
			ptr[i++] = '-';
		while (n >= 0)
		{
			ptr[i++] = '0' + n % 10;
			n /= 10;
			n = (n == 0) ? -1 : n;
		}
		ptr[i] = '\0';
		reverse_str(ptr);
	}
	return (ptr);
}
