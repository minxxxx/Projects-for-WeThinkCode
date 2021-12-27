/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:16:00 by alucas-           #+#    #+#             */
/*   Updated: 2018/03/12 18:16:02 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	main(int ac, char *av[])
{
	t_ps	ps;
	uint8_t	*it;
	char	*op;

	ft_bzero(&ps, sizeof(t_ps));
	ps.input = STDIN_FILENO;
	ps.output = STDOUT_FILENO;
	ps.options |= OPT_OPTI;
	ps_init(&ps, ac, av);
	ps_sort(&ps, STACK_A, (uint32_t)ps.stacks[STACK_A].len);
	if (ps.options & OPT_OPTI)
	{
		ps_opti(&ps);
		it = ft_vecbeg(&ps.ops);
		while (it < (uint8_t *)ft_vecend(&ps.ops))
		{
			op = ps_opstr(*it++);
			write(ps.output, op, ft_strlen(op));
		}
	}
	if (ps.options & OPT_VERB)
		ps_dump(&ps, STACK_BOTH);
	ps_exit(&ps, EXIT_SUCCESS);
}
