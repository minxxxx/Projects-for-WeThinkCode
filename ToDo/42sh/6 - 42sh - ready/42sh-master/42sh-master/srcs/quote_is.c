/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_is.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:16 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:21 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

int			is_quote(char car)
{
	if (car == '\'' || car == '"' || car == '`' || car == '(' || car == ')'
			|| car == '[' || car == ']' || car == '{' || car == '}')
		return (1);
	return (0);
}

int			is_quote_open(char car)
{
	if (car == '\'' || car == '"' || car == '`' || car == '('
			|| car == '[' || car == '{')
		return (1);
	return (0);
}

int			is_quote_close(char car, char open)
{
	if (car == '\'' && open == '\'')
		return (1);
	else if (car == '"' && open == '"')
		return (1);
	else if (car == '`' && open == '`')
		return (1);
	else if (car == '(' && open == ')')
		return (1);
	else if (car == '[' && open == ']')
		return (1);
	else if (car == '{' && open == '}')
		return (1);
	return (0);
}
