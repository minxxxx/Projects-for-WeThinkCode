/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_ctrl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 03:48:46 by sasiedu           #+#    #+#             */
/*   Updated: 2016/08/07 17:26:27 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_ctrl_home_key(t_term **sh, char *line, int i, int j)
{
	while ((*sh)->my_cur >= 0 && line[(*sh)->my_cur] != ' ' && \
			line[(*sh)->my_cur] != '\t')
	{
		(*sh)->my_cur -= 1;
		(*sh)->std_cur -= 1;
		if ((*sh)->std_cur < 0)
			(*sh)->std_cur = tgetnum("co") - 1;
	}
	(*sh)->my_cur += 1;
	(*sh)->std_cur += 1;
	if ((*sh)->std_cur < 0)
		(*sh)->std_cur = tgetnum("co") - 1;
	ft_reset_screen(&(*sh), (*sh)->my_cur, 0, 0);
	i = (*sh)->my_cur - 1;
	j = (*sh)->std_cur - 1;
	ft_move_home_word(&(*sh), line, i, j);
}

void	ft_move_home_word(t_term **sh, char *line, int i, int j)
{
	int	chk;

	chk = 0;
	while (i > 0)
	{
		if (line[i] != ' ' && line[i] != '\t' && \
				(line[i - 1] == ' ' || line[i - 1] == '\t'))
			chk++;
		if (chk == 1)
			break ;
		i--;
		j--;
		if (j < 0)
			j = tgetnum("co") - 1;
	}
	if (line[i] == ' ' || line[i] == '\t')
		return ;
	(*sh)->my_cur = i;
	(*sh)->std_cur = j;
	ft_reset_screen(&(*sh), (*sh)->my_cur, 0, 0);
}

void	ft_ctrl_end_key(t_term **sh, char *line)
{
	int		chk;

	chk = 0;
//	if (line[(*sh)->my_cur] != ' ' && line[(*sh)->my_cur] != '\t')
//		chk--;
	while ((*sh)->my_cur <= (*sh)->len)
	{
		if (line[(*sh)->my_cur - 1] && ft_strchr(" 		", \
				line[(*sh)->my_cur - 1]) != NULL && \
				line[(*sh)->my_cur] != ' ' && line[(*sh)->my_cur] != '\t')
			chk++;
		if (chk > 2)
			break ;
		(*sh)->my_cur += 1;
		(*sh)->std_cur += 1;
		if ((*sh)->std_cur >= tgetnum("co"))
			(*sh)->std_cur = 0;
	}
	ft_ctrl_home_key(&(*sh), line, 0, 0);
}

void	ft_move_end_word(t_term **sh, char *line, int i, int j)
{
	int	chk;

	chk = 0;
	while (i > 0)
	{
		if (line[i] != ' ' && line[i] != '\t' && \
				(line[i - 1] == ' ' || line[i - 1] == '\t'))
			chk++;
		if (chk == 1)
			break ;
		i--;
		j--;
		if (j < 0)
			j = tgetnum("co") - 1;
	}
	if (line[i] == ' ' || line[i] == '\t')
		return ;
	(*sh)->my_cur = i;
	(*sh)->std_cur = j;
	ft_reset_screen(&(*sh), (*sh)->my_cur, 0, 0);
}
