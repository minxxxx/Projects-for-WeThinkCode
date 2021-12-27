/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:16:00 by alucas-           #+#    #+#             */
/*   Updated: 2018/03/12 18:16:02 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static void	tryopen(t_ps *ps, char const *filename, int flags, int *out)
{
	int fd;

	if ((fd = open(filename, flags, 0666)) < 0)
	{
		if (ps->options & OPT_VERB)
			ft_fprintf(g_stderr, "%s: %s: %m\n", ps->prg, filename);
		ps_exit(ps, EXIT_FAILURE);
	}
	*out = fd;
}

static void	makestack(t_ps *ps, char *av[], uint32_t n)
{
	static uint32_t	words[UINT32_MAX / 16] = { 0 };
	t_psnode		*node;

	ft_lstctor(ps->stacks + STACK_A);
	ft_lstctor(ps->stacks + STACK_B);
	ps->nodes = ft_calloc(n * sizeof(t_psnode));
	node = ps->nodes;
	while (*av)
	{
		node->val = (uint32_t)ft_atoi(*av++);
		if (errno)
		{
			if (ps->options & OPT_VERB)
				ft_fprintf(g_stderr, "%s: %s: %m\n", ps->prg, *(av - 1));
			ps_exit(ps, EXIT_FAILURE);
		}
		if (words[node->val / 32] & (1 << node->val % 32))
		{
			if (ps->options & OPT_VERB)
				ft_fprintf(g_stderr, "%s: %d: Duplicate\n", ps->prg, node->val);
			ps_exit(ps, EXIT_FAILURE);
		}
		words[node->val / 32] |= (1 << node->val % 32);
		ft_lstpush(ps->stacks + STACK_A, (t_node *)(node++));
	}
}

void		ps_init(t_ps *ps, int ac, char *av[])
{
	int opt;

	ps->prg = av[0];
	while ((opt = ft_getopt(ac, av, "0123456789vsUi:o:")) != WUT)
		if (opt == 'v')
			ps->options |= OPT_VERB;
		else if (opt == 's')
			ps->options |= OPT_STEP;
		else if (opt == 'U' && (ps->options |= OPT_OPLOG))
			ps->options &= ~OPT_OPTI;
		else if (opt == 'i')
			tryopen(ps, g_optarg, O_RDONLY, &ps->input);
		else if (opt == 'o')
			tryopen(ps, g_optarg, O_WRONLY | O_CREAT | O_TRUNC, &ps->output);
		else if (ft_isdigit(opt))
			break ;
		else
			ps_exit(ps, EXIT_FAILURE);
	if (!(opt = ac - g_optind))
		return (ps_exit(ps, EXIT_FAILURE));
	ft_vecctor(&ps->ops, sizeof(uint8_t));
	ft_memcpy(ps->orders, (int[2]){1, -1}, 2 * sizeof(int));
	makestack(ps, av + g_optind, (uint32_t)opt);
	ps_norm(ps, STACK_A);
}

void		ps_exit(t_ps *ps, int ecode)
{
	if (ps->input != STDIN_FILENO)
		close(ps->output);
	if (ps->output != STDOUT_FILENO)
		close(ps->output);
	if (ps->nodes)
		free(ps->nodes);
	if (ps->ops.len)
		ft_vecdtor(&ps->ops, NULL);
	if (ecode)
		ft_dprintf(STDERR_FILENO, "Error\n");
	exit(ecode);
}
