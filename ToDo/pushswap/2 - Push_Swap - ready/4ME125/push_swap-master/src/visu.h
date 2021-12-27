/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps/visu.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:15:51 by alucas-           #+#    #+#             */
/*   Updated: 2018/03/12 18:15:53 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_VISU_H
# define PS_VISU_H

# include <ncurses.h>

# include "ps.h"

typedef struct	s_psui
{
	t_ps		*ps;
	WINDOW		*wa;
	WINDOW		*wb;
	int			x;
	int			y;
	int			wax;
	int			way;
	int			wbx;
	int			wby;
	uint32_t	max;
}				t_psui;

extern t_psui	*g_ui;

extern void		ps_ncdraw(void);
extern void		ps_ncupdate(int sig);

#endif
