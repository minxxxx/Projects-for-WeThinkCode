/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <telain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 23:26:02 by telain            #+#    #+#             */
/*   Updated: 2016/02/27 16:26:57 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

char	*read_input(t_value *value)
{
	char	*buff;
	int		ret;

	buff = (char*)malloc(2);
	ft_putstr("\nAttente d'une touche\n");
	while ((ret = read(0, buff, 10)) > 2 || ft_atoi(buff) > value->size_x)
	{
		ft_putstr("Invalide... essaie encore\n");
	}
	return (buff);
}
