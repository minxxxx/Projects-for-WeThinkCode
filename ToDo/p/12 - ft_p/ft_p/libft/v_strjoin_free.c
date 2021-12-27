/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_strjoin_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 09:44:22 by wide-aze          #+#    #+#             */
/*   Updated: 2015/06/07 15:19:07 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*v_strjoin_free(char *s1, char *s2, int frees1, int frees2)
{
	char	*str;

	str = v_strjoin(s1, s2);
	if (frees1)
		ft_free (s1);
	if (frees2)
		ft_free (s2);
	return (str);
}
