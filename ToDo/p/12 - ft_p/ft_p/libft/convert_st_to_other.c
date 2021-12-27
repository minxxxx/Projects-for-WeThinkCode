/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_st_to_other.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 15:27:58 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/09 15:32:38 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	ft_strlen_nb(size_t nb, char *base_name, size_t *len)
{
	int		i;

	*len = ft_strlen(base_name);
	i = 1;
	while ((nb = nb / *len))
		i++;
	return (i - 1);
}

char		*convert_st_to_other(size_t nb, char *base_name)
{
	char	*str;
	size_t	len;
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
