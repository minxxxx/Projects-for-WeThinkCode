/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 17:46:46 by wide-aze          #+#    #+#             */
/*   Updated: 2015/02/21 17:53:02 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	**ft_strtabnew(size_t size)
{
	char	**new;
	int		i;

	if (size == (size_t)-1)
		return (NULL);
	if (!(new = (char**)ft_malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	i = -1;
	while (++i < (int)size)
		new[i] = NULL;
	return (new);
}
