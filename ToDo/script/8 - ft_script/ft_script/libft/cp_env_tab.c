/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cp_env_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 17:37:10 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/28 14:52:21 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char	**cp_env_tab(char **env)
{
	char	**new;
	size_t	i;

	i = 0;
	while (env[i] != NULL)
		i++;
	new = (char**)v_malloc(sizeof(char*) * i + 1);
	new[i] = NULL;
	while (i-- > 0)
		new[i] = v_strdup(env[i]);
	return (new);
}
