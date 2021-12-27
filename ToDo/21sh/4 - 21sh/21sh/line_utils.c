/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 13:52:22 by sasiedu           #+#    #+#             */
/*   Updated: 2016/08/07 17:23:01 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_add_char_line(char **line, const char c, int pos, int *size)
{
	int		i;

	if (*size + 1 > MAX_LEN)
		return (-1);
	i = *size;
	while (--i >= pos)
		(*line)[i + 1] = (*line)[i];
	(*line)[pos] = c;
	*size += 1;
	return (0);
}

int		ft_remove_char_line(char **line, int pos, int *size)
{
	while (pos < *size)
	{
		(*line)[pos] = (*line)[pos + 1];
		pos++;
	}
	*size -= 1;
	return (0);
}

void	ft_check_quotes(char *line, t_term **sh, int i)
{
	static int	chk2 = 0;
	static int chk = 0;

	chk2 = 0;
	while (line[++i] != '\0')
	{
		if (line[i] == 34 && chk == 0)
			chk = 1;
		else if (line[i] == 34 && chk == 1)
			chk = 0;
		if (line[i] == 39 && chk2 == 0)
			chk2 = 1;
		else if (line[i] == 39 && chk2 == 1)
			chk2 = 0;
	}
	if (chk == 0 && chk2 == 0)
		(*sh)->std_usr = 0;
	else
		(*sh)->std_usr = 1;
}
