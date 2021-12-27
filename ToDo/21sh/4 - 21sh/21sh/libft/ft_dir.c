/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 19:40:00 by sasiedu           #+#    #+#             */
/*   Updated: 2016/07/25 19:45:15 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_dir(int file_no)
{
	if (file_no == 1)
		return ('p');
	if (file_no == 2)
		return ('c');
	if (file_no == 4)
		return ('d');
	if (file_no == 6)
		return ('b');
	if (file_no == 10)
		return ('-');
	if (file_no == 12)
		return ('l');
	if (file_no == 14)
		return ('s');
	return ('w');
}
