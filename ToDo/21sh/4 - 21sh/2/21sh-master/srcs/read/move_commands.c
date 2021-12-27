/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 12:19:35 by sfranc            #+#    #+#             */
/*   Updated: 2017/07/21 11:24:42 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

/*
** Ctrl + A bring the cursor to the beginning of the line.
** Ctrl + E bring the cursor to the end of the line.
** Ctrl + F bring jump forward to the next word.
** Ctrl + B bring jump back to the previous word.
*/

void	ft_beginning_of_line(t_input *input)
{
	ft_goto_prompt(input);
	input->x = input->prompt;
	input->y = 0;
}

void	ft_end_of_line(t_input *input)
{
	while ((input->y * (input->width + 1) + input->x)\
			< (input->prompt + input->len))
		ft_move_right(input);
}

void	ft_jumpword_forward(t_input *input)
{
	int	i;

	i = input->y * (input->width + 1) + input->x - input->prompt;
	while (input->line[i] && input->line[i] != ' ')
	{
		ft_move_right(input);
		++i;
	}
	while (input->line[i] && input->line[i] == ' ')
	{
		ft_move_right(input);
		++i;
	}
}

void	ft_jumpword_backward(t_input *input)
{
	int	i;

	i = input->y * (input->width + 1) + input->x - input->prompt;
	if ((i > 0 && input->line[i] != ' ' && input->line[i - 1] == ' ') \
			|| (i > 0 && input->line[i] == '\0'))
	{
		ft_move_left(input);
		--i;
	}
	while ((i > 0) && input->line[i] == ' ')
	{
		ft_move_left(input);
		--i;
	}
	while ((i > 0) && input->line[i] != ' ')
	{
		ft_move_left(input);
		--i;
	}
	if (i > 0)
		ft_move_right(input);
}
