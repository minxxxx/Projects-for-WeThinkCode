/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multifree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 14:18:36 by wide-aze          #+#    #+#             */
/*   Updated: 2015/06/13 14:20:09 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_multifree(void *f1, void *f2, void *f3, void *f4)
{
	if (f1)
		ft_free(f1);
	if (f2)
		ft_free(f2);
	if (f3)
		ft_free(f3);
	if (f4)
		ft_free(f4);
}
