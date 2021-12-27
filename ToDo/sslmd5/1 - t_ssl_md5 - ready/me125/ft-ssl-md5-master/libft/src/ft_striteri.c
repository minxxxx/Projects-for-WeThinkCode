/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:59:52 by apakhomo          #+#    #+#             */
/*   Updated: 2017/11/11 14:59:53 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int a;

	a = 0;
	if (s != NULL && f != NULL)
	{
		while (s[a])
		{
			f(a, &(s[a]));
			a++;
		}
	}
	else
		return ;
}
