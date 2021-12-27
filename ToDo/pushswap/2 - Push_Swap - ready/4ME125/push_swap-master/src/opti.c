/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:16:00 by alucas-           #+#    #+#             */
/*   Updated: 2018/03/12 18:16:02 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void		ps_optipush(t_ps *ps, uint8_t **it)
{
	uint8_t		op;
	uint8_t		op2;
	uint32_t	i;
	uint32_t	j;

	i = (uint32_t)(*it - (uint8_t *)ft_vecbeg(&ps->ops));
	op = **it;
	op2 = OP_P + ((op - OP_P) ^ 1);
	while (++*it < (uint8_t *)ft_vecend(&ps->ops))
		if (**it == op2)
		{
			j = (uint32_t)(*it - (uint8_t *)ft_vecbeg(&ps->ops));
			ft_vecrem(&ps->ops, j, NULL);
			ft_vecrem(&ps->ops, i, NULL);
			*it = ft_vecat(&ps->ops, i);
			break ;
		}
		else if (**it != op)
			break ;
}

void		ps_optiswap(t_ps *ps, uint8_t **it)
{
	uint8_t		op;
	uint8_t		op2;
	uint32_t	i;
	uint32_t	j;

	i = (uint32_t)(*it - (uint8_t *)ft_vecbeg(&ps->ops));
	op = **it;
	op2 = (uint8_t)(OP_S + ((op - OP_S) ^ 1));
	while (++*it < (uint8_t *)ft_vecend(&ps->ops))
		if (**it == op2)
		{
			j = (uint32_t)(*it - (uint8_t *)ft_vecbeg(&ps->ops));
			ft_vecrem(&ps->ops, j, NULL);
			*it = ft_vecat(&ps->ops, i);
			**it = (uint8_t)(OP_S + STACK_BOTH);
			++*it;
			break ;
		}
		else if (**it != op)
			break ;
}

void		ps_optirotate(t_ps *ps, uint8_t **it)
{
	uint8_t		op;
	uint8_t		op2;
	uint32_t	i;
	uint32_t	j;

	i = (uint32_t)(*it - (uint8_t *)ft_vecbeg(&ps->ops));
	op = **it;
	op2 = (uint8_t)(OP_R + ((op - OP_R) ^ 1));
	while (++*it < (uint8_t *)ft_vecend(&ps->ops))
		if (**it == op2)
		{
			j = (uint32_t)(*it - (uint8_t *)ft_vecbeg(&ps->ops));
			ft_vecrem(&ps->ops, j, NULL);
			*it = ft_vecat(&ps->ops, i);
			**it = (uint8_t)(OP_R + STACK_BOTH);
			++*it;
			break ;
		}
		else if (**it != op)
			break ;
}

void		ps_optirrotate(t_ps *ps, uint8_t **it)
{
	uint8_t		op;
	uint8_t		op2;
	uint32_t	i;
	uint32_t	j;

	i = (uint32_t)(*it - (uint8_t *)ft_vecbeg(&ps->ops));
	op = **it;
	op2 = (uint8_t)(OP_RR + ((op - OP_RR) ^ 1));
	while (++*it < (uint8_t *)ft_vecend(&ps->ops))
		if (**it == op2)
		{
			j = (uint32_t)(*it - (uint8_t *)ft_vecbeg(&ps->ops));
			ft_vecrem(&ps->ops, j, NULL);
			*it = ft_vecat(&ps->ops, i);
			**it = (uint8_t)(OP_RR + STACK_BOTH);
			++*it;
			break ;
		}
		else if (**it != op)
			break ;
}

void		ps_opti(t_ps *ps)
{
	uint8_t			*it;
	t_opti			*opti;
	static t_opti	*optis[OP_RR + STACK_BOTH] = {
		[OP_P + STACK_A] = ps_optipush,
		[OP_P + STACK_B] = ps_optipush,
		[OP_S + STACK_A] = ps_optiswap,
		[OP_S + STACK_B] = ps_optiswap,
		[OP_R + STACK_A] = ps_optirotate,
		[OP_R + STACK_B] = ps_optirotate,
		[OP_RR + STACK_A] = ps_optirrotate,
		[OP_RR + STACK_B] = ps_optirrotate,
	};

	if (!ps->ops.len)
		return ;
	it = ft_vecbeg(&ps->ops);
	while (it < (uint8_t *)ft_vecend(&ps->ops))
	{
		if ((opti = optis[*it]))
			opti(ps, &it);
		else
			++it;
	}
}
