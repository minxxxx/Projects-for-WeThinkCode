/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 18:03:46 by sfranc            #+#    #+#             */
/*   Updated: 2017/09/15 15:10:45 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

int		ft_goto_next_quote(char *line, char quote)
{
	int	len;

	len = 1;
	while (*(line + len) && *(line + len) != quote)
		len++;
	return (len);
}

int		ft_goto_next_quote_withescape(char *line, char quote)
{
	int	len;

	len = 1;
	while (*(line + len) && *(line + len) != quote)
	{
		if (*(line + len) == '\\')
			len++;
		len++;
	}
	return (len);
}

int		ft_is_quoted_no_dquotes(char *str, char *c)
{
	int	escape;

	escape = 0;
	while (str < c)
	{
		if (*str == '\\')
			escape = 1;
		if (*str == '\\' && (str + 1) && *(str + 1) == *c)
			return (1);
		else if (!escape && *str == '\''\
				&& ((str = str + ft_goto_next_quote(str, *str)) > c))
			return (1);
		else
		{
			str++;
			escape = 0;
		}
	}
	return (0);
}

int		ft_is_quoted(char *str, char *c)
{
	int	escape;

	escape = 0;
	while (str < c)
	{
		if (*str == '\\')
			escape = 1;
		if (*str == '\\' && (str + 1) && *(str + 1) == *c)
			return (1);
		if (!escape && *str == '"'\
				&& ((str = str\
						+ ft_goto_next_quote_withescape(str, *str) + 1) > c))
			return (1);
		else if (!escape && *str == '\''\
				&& ((str = str + ft_goto_next_quote(str, *str)) > c))
			return (1);
		else
		{
			str++;
			escape = 0;
		}
	}
	return (0);
}
