/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uni_covert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 17:12:04 by sasiedu           #+#    #+#             */
/*   Updated: 2016/05/25 16:56:47 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uni_convert(unsigned int num, int base)
{
	int				len;
	unsigned	int	temp;
	size_t			i;
	static	char	bases[] = "0123456789abcdef";
	char			*save;

	temp = num;
	i = 0;
	len = ft_count_UInum(num, base);
	save = ft_strnew(len + 1);
	while (temp != 0)
	{
		save[i] = bases[temp % base];
		temp = temp / base;
		i++;
	}
	save[i] = '\0';
	ft_strrev(&save);
	return (save);
}

char	*ft_UNI_CONVERT(unsigned int num, int base)
{
	int             len;
	unsigned    int temp;
	size_t          i;
	static  char    bases[] = "0123456789ABCDEF";
	char            *save;

	temp = num;
	i = 0;
	len = ft_count_UInum(num, base);
	save = ft_strnew(len + 1);
	while (temp != 0)
	{
		save[i] = bases[temp % base];
		temp = temp / base;
		i++;
	}
	save[i] = '\0';
	ft_strrev(&save);
	return (save);
}
