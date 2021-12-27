/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:16:00 by alucas-           #+#    #+#             */
/*   Updated: 2018/03/12 18:16:02 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

t_psui			*g_ui;

static void		ncinit(void)
{
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(FALSE);
	start_color();
	init_color(COLOR_WHITE, 0x12c, 0x12c, 0x12c);
	init_pair(0x2a, 0x8, COLOR_BLACK);
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_CYAN, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_RED, COLOR_BLACK);
	clear();
	refresh();
}

static void		drawwin(t_ps *ps, uint8_t stack, WINDOW *win, uint32_t max)
{
	t_psnode	*node;
	int			x;
	int			y;
	int			c;
	int			m;

	if (!(node = ps_head(ps, stack)))
		return ;
	x = 0;
	while (node != (t_psnode *)(ps->stacks + stack))
	{
		c = (node->val * 6 / max) + 1;
		m = node->val * getmaxy(win) / max;
		node = node->next;
		y = (getmaxy(win) - m) - 1;
		while (++y <= getmaxy(win))
			mvwaddch(win, y, x, (chtype)(' ' | COLOR_PAIR(c)));
		if ((x += 2) >= getmaxx(win))
			break ;
	}
	wsyncdown(win);
}

void			ps_ncdraw(void)
{
	clear();
	drawwin(g_ui->ps, STACK_A, g_ui->wa, g_ui->max);
	drawwin(g_ui->ps, STACK_B, g_ui->wb, g_ui->max);
}

void			ps_ncupdate(int sig)
{
	(void)sig;
	endwin();
	ncinit();
	getmaxyx(stdscr, g_ui->y, g_ui->x);
	if (!(g_ui->wa = subwin(stdscr, g_ui->y / 2, g_ui->x, 0, 0)))
		return ;
	if (!(g_ui->wb = subwin(stdscr, g_ui->y / 2, g_ui->x, g_ui->y / 2, 0)))
		return ;
	wattr_on(g_ui->wa, 0x242a00, 0);
	wattr_on(g_ui->wb, 0x242a00, 0);
	wrefresh(g_ui->wa);
	getmaxyx(g_ui->wa, g_ui->way, g_ui->wax);
	wrefresh(g_ui->wb);
	getmaxyx(g_ui->wb, g_ui->wby, g_ui->wbx);
	ps_ncdraw();
}
