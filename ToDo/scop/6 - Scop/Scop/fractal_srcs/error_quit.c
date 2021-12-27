/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_quit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 13:43:14 by ggroener          #+#    #+#             */
/*   Updated: 2016/09/30 13:43:15 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_quit(char *error_message)
{
	ft_putstr("Error happened, STOP TRYING TO BREAK MY CODE: ");
	ft_putendl(error_message);
	exit(-1);
}
