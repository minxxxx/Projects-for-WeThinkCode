/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_state.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 06:49:27 by ggroener          #+#    #+#             */
/*   Updated: 2016/11/15 06:49:28 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

t_state *new_state()
{
	t_state *state;

	if (!(state = malloc(sizeof(*state))))
	{
		ft_putendl_fd("npuzzle: failed to malloc new state", 2);
		exit(EXIT_FAILURE);
	}
	state->pred = NULL;
	state->g = 0;
	return (state);
}
