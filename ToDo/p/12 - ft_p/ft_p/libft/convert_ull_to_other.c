/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_ull_to_other.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 09:43:00 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/05 14:42:19 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#define ULL unsigned long long

static int	ft_strlen_nb(ULL nb, char *base_name, ULL *len)
{
	int		i;

	*len = ft_strlen(base_name);
	i = 1;
	while ((nb = nb / *len))
		i++;
	return (i - 1);
}

char		*convert_ull_to_other(ULL nb, char *base_name)
{
	char	*str;
	ULL		len;
	int		i;

	if (!nb)
		return (ft_strdup("0"));
	i = ft_strlen_nb(nb, base_name, &len);
	str = ft_strnew(i + 1);
	while (i >= 0)
	{
		str[i] = base_name[nb % len];
		nb = nb / len;
		i--;
	}
	return (str);
}
