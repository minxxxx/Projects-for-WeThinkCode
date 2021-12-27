/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_strnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 08:25:30 by wide-aze          #+#    #+#             */
/*   Updated: 2015/01/31 08:30:18 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*v_strnew(size_t size)
{
	char	*new;

	size++;
	new = v_malloc(size);
	ft_bzero((void*)new, size);
	return (new);
}
