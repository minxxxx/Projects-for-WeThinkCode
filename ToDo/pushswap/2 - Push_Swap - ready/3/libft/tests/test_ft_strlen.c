/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprevot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:38:03 by mprevot           #+#    #+#             */
/*   Updated: 2016/11/14 15:46:11 by mprevot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		main(void)
{
	char	a[] = "";
	char	b[] = "0123456789";
	char	c[] = "oo\0xx";

	if (ft_strlen(a) != 0)
		return (10);

	if (ft_strlen(b) != 10)
		return (20);

	if (ft_strlen(c) != 2)
		return (30);

	return (0);
}
