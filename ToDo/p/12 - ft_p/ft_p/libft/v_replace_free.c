/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_replace_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 19:03:18 by wide-aze          #+#    #+#             */
/*   Updated: 2015/06/13 19:08:45 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*v_replace_free(char *old, char *new, t_bool fnew)
{
	ft_free(old);
	old = v_strdup(new);
	if (fnew)
		ft_free(new);
	return (old);
}
