/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 19:28:26 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/14 16:14:35 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_unprint(char *s, int i)
{
	if (s[i] == 0)
		return (ft_strdup("\\0"));
	else if (s[i] == 7)
		return (ft_strdup("\\a"));
	else if (s[i] == 8)
		return (ft_strdup("\\b"));
	else if (s[i] == 9)
		return (ft_strdup("\\t"));
	else if (s[i] == 10)
		return (ft_strdup("\\n"));
	else if (s[i] == 11)
		return (ft_strdup("\\v"));
	else if (s[i] == 12)
		return (ft_strdup("\\f"));
	else if (s[i] == 13)
		return (ft_strdup("\\r"));
	else if (s[i] == 34)
		return (ft_strdup("\\\""));
	else if (s[i] == 92)
		return (ft_strdup("\\\\"));
	return (0);
}
