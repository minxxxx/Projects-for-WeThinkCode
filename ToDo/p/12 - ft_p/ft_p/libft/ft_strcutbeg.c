/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcutbeg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 19:35:54 by wide-aze          #+#    #+#             */
/*   Updated: 2015/06/13 19:39:17 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strcutbeg(char *str, char delim)
{
	char	*new;
	int		i;

	i = ft_strlen(str) - 1;
	while (str[i] != delim)
		i--;
	new = v_strdup(&str[i]);
	ft_free(str);
	return (new);
}
