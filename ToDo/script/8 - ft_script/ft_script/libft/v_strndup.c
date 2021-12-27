/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_strndup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 08:25:02 by wide-aze          #+#    #+#             */
/*   Updated: 2015/06/17 16:25:54 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*v_strndup(char *str, int len)
{
	char	*new;

	new = v_strnew(len);
	return (ft_strncat(new, str, len));
}
