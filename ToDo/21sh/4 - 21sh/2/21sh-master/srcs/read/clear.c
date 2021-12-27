/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 12:59:56 by sfranc            #+#    #+#             */
/*   Updated: 2017/07/21 10:59:55 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

void	ft_clear(t_input *input)
{
	ft_goto_prompt(input);
	tputs(tgetstr("cd", NULL), 1, &ft_intputchar);
}

void	ft_clear_screen(t_input *input)
{
	ft_clear(input);
	ft_bzero(input->line, INPUTSIZE);
	input->x = input->prompt;
	input->y = 0;
	input->len = 0;
}
