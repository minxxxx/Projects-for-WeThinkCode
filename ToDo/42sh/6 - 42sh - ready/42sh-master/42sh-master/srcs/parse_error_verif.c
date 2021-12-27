/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error_verif.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:16 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:20 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

int	verif_first_pipe_error(char *str, size_t *i, int *pipe_last,
	int first_char)
{
	if (first_char ||
			(str[*i + 1] && str[*i + 2] && is_wrong_pipe(str, *i + 2)))
		return (0);
	else if (ft_strnequ(str + *i, "&&", 2) || ft_strnequ(str + *i, "||", 2))
		(*i)++;
	(*i)++;
	*pipe_last = 1;
	return (1);
}

int	verif_wrong_sep(int *pipe_last, int *first_char)
{
	if (*pipe_last)
		return (0);
	*first_char = 1;
	*pipe_last = 0;
	return (1);
}
