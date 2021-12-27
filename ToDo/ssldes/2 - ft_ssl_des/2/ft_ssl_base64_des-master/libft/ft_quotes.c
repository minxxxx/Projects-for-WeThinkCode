/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdanain <vdanain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 03:11:24 by jmontija          #+#    #+#             */
/*   Updated: 2016/12/13 18:50:36 by vdanain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ret_clean_quotes(int free, int *quotes)
{
	int	i;

	i = -1;
	while (quotes && ++i < 6)
	{
		if (free == 0 && quotes[i] > 0)
			return (1);
		else if (free == 0 && quotes[i] < 0)
			return (-1);
		else if (free == 1)
			quotes[i] = 0;
	}
	if (free == 1)
		return (-1);
	return (0);
}

void	check_quotes(int *quotes, char c, char type, int idx)
{
	if (c != type)
		return ;
	else if ((type == '{' || type == '[' || type == '(') ||
		((type == '\'' || type == '"' || type == '`') && quotes[idx] == 0))
	{
		quotes[idx] += 1;
	}
	else
		quotes[idx] -= 1;
}

int		malloc_free(int **quotes, char c)
{
	int	i;

	i = -1;
	if (c == -4)
	{
		free(*quotes);
		*quotes = NULL;
		return (-1);
	}
	if (*quotes == NULL)
	{
		*quotes = (int *)malloc(sizeof(int) * 6);
		while (++i < 6)
			(*quotes)[i] = 0;
	}
	if (c == 0)
		return (ret_clean_quotes(1, *quotes));
	return (0);
}

/*
**	ADD FOR 21SH ==>> check_quotes(quotes, c, '`', bquote);
*/

int		check_parentheses(char c)
{
	int			ret;
	static int	*quotes = NULL;

	ret = 0;
	if (malloc_free(&quotes, c) < 0)
		return (ret);
	quotes[dquote] == 0 && quotes[par] == 0 && quotes[bquote] == 0 ?
	check_quotes(quotes, c, '\'', squote) : 0;
	quotes[squote] == 0 && quotes[par] == 0 && quotes[bquote] == 0 ?
	check_quotes(quotes, c, '"', dquote) : 0;
	quotes[squote] == 0 && quotes[par] == 0 && quotes[dquote] == 0 ?
	check_quotes(quotes, c, '`', bquote) : 0;
	if (quotes[squote] == 0 && quotes[dquote] == 0 && quotes[bquote] == 0)
	{
		check_quotes(quotes, c, '{', acc);
		check_quotes(quotes, c, '}', acc);
		check_quotes(quotes, c, '[', cro);
		check_quotes(quotes, c, ']', cro);
		check_quotes(quotes, c, '(', par);
		check_quotes(quotes, c, ')', par);
	}
	ret = ret_clean_quotes(0, quotes);
	return (ret);
}
