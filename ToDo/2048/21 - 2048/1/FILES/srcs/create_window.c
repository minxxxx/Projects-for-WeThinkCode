/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 15:37:12 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/31 15:37:25 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wkw.h"

WINDOW	*create_newwin(int height, int width, int starty, int startx)
{
	WINDOW	*new_win;

	new_win = newwin(height, width, starty, startx);
	box(new_win, 0, 0);
	return (new_win);
}
