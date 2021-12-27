/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_wide.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 17:35:27 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/19 17:38:29 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_strlen_wide(const wchar_t *original)
{
	const wchar_t	*end;

	end = original;
	while (*end != L'\0')
		end++;
	return (end - original);
}
