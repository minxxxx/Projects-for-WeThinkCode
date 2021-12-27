/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_str_strtab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 08:18:35 by wide-aze          #+#    #+#             */
/*   Updated: 2015/06/18 12:24:27 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	**add_str_strtab(char **tab, char *str)
{
	char	**new;
	size_t	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	new = (char**)v_malloc(sizeof(char*) * (i + 2));
	i = 0;
	while (tab[i] != NULL)
	{
		new[i] = tab[i];
		i++;
	}
	new[i] = v_strdup(str);
	new[i + 1] = NULL;
	ft_free(tab);
	return (new);
}
