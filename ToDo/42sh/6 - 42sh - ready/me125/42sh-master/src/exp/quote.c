/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp/comm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2018/01/06 11:10:01 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ush/exp.h"

void	sh_exponquote(int *quoted, char quote)
{
	if (quote == '\'')
	{
		if (*quoted == 0)
			*quoted = 1;
		else if (*quoted == 1)
			*quoted = 0;
	}
	else if (quote == '"')
	{
		if (*quoted == 0)
			*quoted = 2;
		else if (*quoted == 2)
			*quoted = 0;
	}
}

int		sh_expdquote(t_sds *word, char **words, t_vec *av)
{
	while (**words)
	{
		if (**words == '"')
			return (YEP);
		else if (**words == '$')
			sh_expdollars(word, words, av, 1);
		else if (**words == '`')
		{
			++*words;
			sh_expbacktick(word, words, NULL);
		}
		else if (**words == '\\')
			sh_expbackslash(word, words, 1);
		else
			*ft_sdspush(word) = **words;
		++*words;
	}
	return (NOP);
}

int		sh_expsquote(t_sds *word, char **words)
{
	while (**words)
	{
		if (**words != '\'')
			*ft_sdspush(word) = **words;
		else
			return (YEP);
		++*words;
	}
	return (NOP);
}
