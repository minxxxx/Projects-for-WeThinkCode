/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_str_with_char.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 09:14:31 by jcamhi            #+#    #+#             */
/*   Updated: 2016/01/19 15:29:23 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_alloc_str_with_char(int c)
{
	char	*ret;

	ret = (char*)malloc(2 * sizeof(char));
	ret[0] = c;
	ret[1] = '\0';
	return (ret);
}
