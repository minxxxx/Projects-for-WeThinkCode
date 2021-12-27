/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 11:29:47 by geargenc          #+#    #+#             */
/*   Updated: 2017/12/16 11:30:21 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_puissance4.h"

void			ft_error_args(char *name)
{
	ft_putstr_fd("Usage: ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(" height width\n", 2);
}

void			ft_error_size(char *height, char *width)
{
	ft_putstr_fd("Invalid arguments : \n\"", 2);
	ft_putstr_fd(height, 2);
	ft_putstr_fd("\" is invalid or less than 6, or \"", 2);
	ft_putstr_fd(width, 2);
	ft_putstr_fd("\" is invalid or less than 7.\n", 2);
}
