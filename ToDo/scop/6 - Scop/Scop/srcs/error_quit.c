/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_quit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:33:10 by khansman          #+#    #+#             */
/*   Updated: 2016/11/25 09:33:17 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

void	error_quit(char *message)
{
	ft_putendl((message != NULL) ? "Error: An unlabled error occured." :
		message);
	safe_free_lst(&g_lst);
	safe_free((void **)&g_vertecies);
	exit(0);
}
