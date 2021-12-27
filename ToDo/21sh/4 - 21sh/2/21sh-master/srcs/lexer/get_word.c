/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 17:51:10 by sfranc            #+#    #+#             */
/*   Updated: 2017/09/19 15:10:07 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

int			ft_part_word(char c)
{
	if (ft_isprint(c) && !ft_isspace(c) && !ft_part_operator(c))
		return (1);
	return (0);
}

static int	ft_get_word_with_dquotes(char *line, int len, int *quoting)
{
	*quoting |= DQUOTES;
	len += ft_goto_next_quote_withescape(line + len, *(line + len));
	if (*(line + len) == '"')
	{
		*quoting ^= DQUOTES;
		len++;
	}
	return (len);
}

static int	ft_get_word_with_squotes(char *line, int len, int *quoting)
{
	*quoting |= SQUOTES;
	len += ft_goto_next_quote(line + len, *(line + len));
	if (*(line + len) == '\'')
	{
		*quoting ^= SQUOTES;
		len++;
	}
	return (len);
}

static int	ft_create_word_token(t_lexer *lexer, char *line, int len,\
		int quoting)
{
	t_token	*token;
	char	*tmp;

	tmp = ft_strsub(line, 0, len);
	token = ft_newtoken(tmp, WORD, NONE);
	token->quoting = quoting;
	ft_addtoken(lexer, token);
	free(tmp);
	return (len);
}

int			ft_get_word(t_lexer *lexer, char *line)
{
	int		len;
	int		quoting;

	quoting = 0;
	len = 0;
	while (*(line + len) && !ft_part_operator(*(line + len))\
			&& !ft_isspace(*(line + len)))
	{
		if (*(line + len) == '\\')
		{
			len++;
			quoting |= ESCAPE;
		}
		if (!quoting && *(line + len) == '"')
			len = ft_get_word_with_dquotes(line, len, &quoting);
		else if (!quoting && *(line + len) == '\'')
			len = ft_get_word_with_squotes(line, len, &quoting);
		else
		{
			if (*(line + len) != '\n')
				quoting = (quoting & ESCAPE) ? quoting ^ ESCAPE : 0;
			len++;
		}
	}
	return (ft_create_word_token(lexer, line, len, quoting));
}
