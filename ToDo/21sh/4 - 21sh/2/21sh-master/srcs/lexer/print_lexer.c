/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 15:51:29 by sfranc            #+#    #+#             */
/*   Updated: 2017/09/15 16:44:06 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

static void		ft_putstr3(char *s1, char *s2, char *s3)
{
	ft_putstr(s1);
	ft_putstr(s2);
	ft_putstr(s3);
}

void			ft_printlexer(t_token *lexer, int nbr_token)
{
	static char	*operator[] = {"", "DSEMI", "SEMI", "AND_IF", "AND", "OR_IF",\
		"PIPE", "DLESS_DASH", "DLESS", "LESS_AND", "LESS_GREAT", "LESS",\
			"DGREAT", "GREAT_AND", "CLOBBER", "GREAT"};
	static char	*token[] = {"WORD", "OPERATOR", "REDIRECT", "IO_NUMBER",\
		"NEWLINE"};
	t_token		*temp;

	temp = lexer;
	ft_putendl(BBLUE"_______________ LEXER _______________"RESET);
	ft_putstr("--- NB TOKEN = ");
	ft_putnbr_endl(nbr_token);
	while (temp)
	{
		ft_putstr3(token[temp->token_type], " ", operator[temp->operator_type]);
		if (ft_strlen(token[temp->token_type]) + 1 >= 8)
			ft_putstr("\t");
		else
			ft_putstr("\t\t");
		ft_putstr(temp->str);
		if (temp->heredoc)
			ft_putstr3("\t", "heredoc: ", temp->heredoc);
		ft_putendl("");
		temp = temp->next;
	}
	ft_putendl(BBLUE"_____________________________________"RESET);
}
