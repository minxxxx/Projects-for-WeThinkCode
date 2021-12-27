/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_operator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <dtedgui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 16:09:51 by dtedgui           #+#    #+#             */
/*   Updated: 2016/04/22 11:53:08 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh.h"

int			ft_found_and_or(char *str, t_token_info *token_info)
{
	int		type;
	size_t	i;

	i = ft_strlen(str) - 1;
	type = 0;
	while (i)
	{
		if (str[i] == '&' && str[i - 1] == '&')
			type = TOKEN_AND;
		if (str[i] == '|' && str[i - 1] == '|')
			type = TOKEN_OR;
		if (type)
		{
			token_info->type = type;
			token_info->pos = (int)i;
			return (TRUE);
		}
		i--;
	}
	return (FALSE);
}

int			ft_found_write_read_pipe(char *str, t_token_info *token_info)
{
	int		type;
	size_t	i;

	i = ft_strlen(str);
	type = 0;
	while (--i)
	{
		if (str[i] == '>' && str[i - 1] == '>')
			type = TOKEN_DOUBLE_WRITE;
		else if (str[i] == '<' && str[i - 1] == '<')
			type = TOKEN_DOUBLE_READ;
		else if (str[i] == '>' && str[i + 1] != '&')
			type = TOKEN_SIMPLE_WRITE;
		else if (str[i] == '<' && str[i + 1] != '&')
			type = TOKEN_SIMPLE_READ;
		else if (str[i] == '|' && str[i + 1] != '&')
			type = TOKEN_PIPE;
		if (type)
		{
			token_info->type = type;
			token_info->pos = (int)i;
			return (TRUE);
		}
	}
	return (FALSE);
}

void		ft_find_operator(char *str, t_token_info *token_info)
{
	if (ft_found_and_or(str, token_info))
		return ;
	else if (ft_found_write_read_pipe(str, token_info))
		return ;
	else
	{
		token_info->type = TOKEN_CMD;
		token_info->pos = -1;
	}
}
