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

static int	gnl(int const fd, char **line)
{
	static t_sds	c[OPEN_MAX];
	char			b[FT_PAGE_SIZE + 1];
	ssize_t			i;
	char			*eol;

	eol = NULL;
	if (line && *line)
		free(*line);
	if (!line || fd < 0 || fd > OPEN_MAX)
		return (-1);
	while ((!c[fd].len || (eol || !(eol = ft_strchr(c[fd].buf, '\n')))))
		if ((i = read(fd, b, FT_PAGE_SIZE)) == 0)
			break ;
		else if (i == -1 || !(eol = ft_sdsmpush(c + fd, b, (size_t)i)))
			return (-1);
		else if ((eol = ft_strchr(eol, '\n')))
			break ;
	if (!(i = eol ? (eol - c[fd].buf + 1) : (ssize_t)c[fd].len))
		return (ft_pfree((void **)&c[fd].buf));
	if (!(*line = malloc((size_t)(i + (eol ? 1 : 0)) * sizeof(char))))
		return (-1);
	(*line)[ft_sdsnsht(c + fd, (size_t)i, *line) - (eol ? 1 : 0)] = '\0';
	return (1);
}

static int	evalr(t_ps *ps, char *cmd)
{
	if (!ft_strcmp("ra", cmd))
		ps_rotate(ps, STACK_A);
	else if (!ft_strcmp("rb", cmd))
		ps_rotate(ps, STACK_B);
	else if (!ft_strcmp("rr", cmd))
	{
		ps_rotate(ps, STACK_A);
		ps_rotate(ps, STACK_B);
	}
	else if (!ft_strcmp("rra", cmd))
		ps_rrotate(ps, STACK_A);
	else if (!ft_strcmp("rrb", cmd))
		ps_rrotate(ps, STACK_B);
	else if (!ft_strcmp("rrr", cmd))
	{
		ps_rrotate(ps, STACK_A);
		ps_rrotate(ps, STACK_B);
	}
	else
		return (0);
	return (1);
}

static int	eval(t_ps *ps, char *cmd)
{
	size_t	len;

	if ((len = ft_strlen(cmd)) < 2 || len > 4)
		return (0);
	if (cmd[len - 1] == '\n')
		cmd[--len] = '\0';
	if (!ft_strcmp("sa", cmd))
		ps_swap(ps, STACK_A);
	else if (!ft_strcmp("sb", cmd))
		ps_swap(ps, STACK_B);
	else if (!ft_strcmp("ss", cmd))
	{
		ps_swap(ps, STACK_A);
		ps_swap(ps, STACK_B);
	}
	else if (!ft_strcmp("pa", cmd))
		ps_pop(ps, STACK_B);
	else if (!ft_strcmp("pb", cmd))
		ps_pop(ps, STACK_A);
	else
		return (evalr(ps, cmd));
	return (1);
}

static void	run(t_psui *ui)
{
	char		*op;
	int			ch;

	g_ui = ui;
	ps_ncupdate(ch = 0);
	signal(SIGWINCH, ps_ncupdate);
	op = NULL;
	ps_ncdraw();
	nodelay(stdscr, TRUE);
	while (gnl(ui->ps->input, &op) == 1)
	{
		if ((ch = getch()) != ERR)
			break ;
		eval(ui->ps, op);
		ps_ncdraw();
		usleep(20000);
	}
	ps_ncdraw();
	nodelay(stdscr, FALSE);
	!ch ? getch() : 0;
	ui->wa ? delwin(ui->wa) : 0;
	ui->wb ? delwin(ui->wb) : 0;
	endwin();
	ps_dump(ui->ps, STACK_A);
	ps_exit(ui->ps, EXIT_SUCCESS);
}

int			main(int ac, char *av[])
{
	t_ps		ps;
	t_psui		ui;
	t_psnode	*node;

	if (ac < 2)
		return (EXIT_SUCCESS);
	ft_bzero(&ps, sizeof(t_ps));
	ft_bzero(&ui, sizeof(t_psui));
	ps.input = STDIN_FILENO;
	ps.output = STDOUT_FILENO;
	ps_init(&ps, ac, av);
	if (!(node = ps_head(&ps, STACK_A)))
		ps_exit(&ps, EXIT_SUCCESS);
	while (node != (t_psnode *)(ps.stacks + STACK_A))
	{
		if (node->val > ui.max)
			ui.max = node->val;
		node = node->next;
	}
	ui.ps = &ps;
	run(&ui);
}
