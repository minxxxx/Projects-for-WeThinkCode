/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:27:57 by ljoly             #+#    #+#             */
/*   Updated: 2017/02/24 16:27:59 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_wstr_size(const wchar_t *s)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i])
		len += ft_wchar_size(s[i++]);
	return (len);
}
