/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goto.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 15:13:47 by sfranc            #+#    #+#             */
/*   Updated: 2017/07/21 11:08:33 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

/*
** Bring the cursor to the beginning of the input, BEFORE the prompt.
*/

void	ft_goto_begin(t_input *input)
{
	int i;

	if (input->y != 0)
	{
		i = input->y;
		while (i--)
			tputs(tgetstr("up", NULL), 1, &ft_intputchar);
	}
	tputs(tgetstr("cr", NULL), 1, &ft_intputchar);
}

/*
** Bring the cursor right after the prompt.
*/

void	ft_goto_prompt(t_input *input)
{
	int i;

	ft_goto_begin(input);
	i = input->prompt;
	while (i--)
		tputs(tgetstr("nd", NULL), 1, &ft_intputchar);
}

/*
** With a new x or y, bring the cursor to the new position. No write in between.
*/

void	ft_goto_newpos(t_input *input, int cur_y)
{
	int i;

	while (cur_y-- > 0)
		tputs(tgetstr("up", NULL), 1, &ft_intputchar);
	tputs(tgetstr("cr", NULL), 1, &ft_intputchar);
	i = 0;
	while (i++ < input->y)
		tputs(tgetstr("sf", NULL), 1, &ft_intputchar);
	i = 0;
	while (i++ < input->x)
		tputs(tgetstr("nd", NULL), 1, &ft_intputchar);
}

/*
** After "write", the cursor is moved at the end of the string printed,
** bring the cursor to its last position before write.
*/

void	ft_goto_lastpos(t_input *input)
{
	int	y;
	int	i;

	y = (input->len + input->prompt) / (input->width + 1);
	if (((input->len + input->prompt) % (input->width + 1)) == 0)
		y--;
	while (y--)
		tputs(tgetstr("up", NULL), 1, &ft_intputchar);
	tputs(tgetstr("cr", NULL), 1, &ft_intputchar);
	i = 0;
	while (i++ < input->y)
		tputs(tgetstr("sf", NULL), 1, &ft_intputchar);
	i = 0;
	while (i++ < input->x)
		tputs(tgetstr("nd", NULL), 1, &ft_intputchar);
}
