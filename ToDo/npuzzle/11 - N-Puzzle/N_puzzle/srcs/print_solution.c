/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:32:51 by ggroener          #+#    #+#             */
/*   Updated: 2016/11/14 17:32:52 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

void print_solution(t_env *env, t_state *state)
{
	if (state != NULL)
	{
		print_solution(env, state->pred);
		dump_state(env, state);
		ft_putchar('\n');
	}
}
