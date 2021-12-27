/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <sfranc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 16:56:23 by sfranc            #+#    #+#             */
/*   Updated: 2017/10/03 17:12:01 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

int		ft_is_eol(char *buff)
{
	int i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
		{
			buff[i] = '\0';
			return (1);
		}
		++i;
	}
	return (0);
}

/*
** Insert an char or a string into the current line.
*/

int		ft_insertchar(char *buff, t_input *input)
{
	char	*end;
	int		start;
	int		buff_size;
	int		ret;

	ret = ft_is_eol(buff);
	buff_size = ft_strlen(buff);
	if (input->len < INPUTSIZE - buff_size - 2)
	{
		ft_clear(input);
		start = input->y * (input->width + 1) + input->x - input->prompt;
		end = ft_strsub(input->line, start, input->len - start);
		ft_bzero(input->line + start, INPUTSIZE - start);
		input->line = ft_strcat(input->line, buff);
		input->line = ft_strcat(input->line, end);
		ft_putstr(input->line);
		input->len += buff_size;
		ft_goto_lastpos(input);
		while (buff_size-- > 0)
			ft_move_right(input);
		free(end);
	}
	else
		tputs(tgetstr("bl", NULL), 1, &ft_intputchar);
	return (ret);
}

/*
** Delete the char right on the left, with "delete" key.
*/

void	ft_back_deletechar(t_input *input)
{
	char	*begin;
	char	*end;
	int		start;

	if ((input->y == 0 && input->x > input->prompt) || input->y > 0)
	{
		ft_clear(input);
		start = input->y * (input->width + 1) + input->x - input->prompt;
		begin = ft_strsub(input->line, 0, start - 1);
		end = ft_strsub(input->line, start, input->len - ft_strlen(begin));
		ft_bzero(input->line, INPUTSIZE);
		input->line = ft_strcpy(input->line, begin);
		input->line = ft_strcat(input->line, end);
		ft_putstr(input->line);
		input->len--;
		ft_goto_lastpos(input);
		ft_move_left(input);
		free(begin);
		free(end);
	}
	else
		tputs(tgetstr("bl", NULL), 1, &ft_intputchar);
}

/*
** Delete the char right below the cursor with "delete >" key or fn + "delete".
*/

void	ft_deletechar(t_input *input)
{
	char	*begin;
	char	*end;
	int		start;

	start = input->y * (input->width + 1) + input->x - input->prompt;
	if (start >= 0 && start < input->len)
	{
		ft_clear(input);
		begin = ft_strsub(input->line, 0, start);
		end = ft_strsub(input->line, start + 1, input->len - ft_strlen(begin));
		ft_bzero(input->line, INPUTSIZE);
		input->line = ft_strcpy(input->line, begin);
		input->line = ft_strcat(input->line, end);
		ft_putstr(input->line);
		input->len--;
		ft_goto_lastpos(input);
		free(begin);
		free(end);
	}
	else
		tputs(tgetstr("bl", NULL), 1, &ft_intputchar);
}
