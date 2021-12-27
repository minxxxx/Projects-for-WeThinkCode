/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redir_check_redir.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

static void	double_redir_without_number(int *redir_type, char *str, size_t *tmp)
{
	*redir_type = (str[*tmp] == '<' ? 3 : 1);
	(*tmp) += 2;
}

static void	simple_redir_without_number(int *redir_type, char *str, size_t *tmp)
{
	*redir_type = (str[*tmp] == '>' ? 0 : 2);
	(*tmp)++;
}

static int	redir_with_number(int *fd, int *redir_type, char *str, size_t *tmp)
{
	*fd = str[*tmp] - '0';
	if (str[*tmp + 1] == '>' && str[*tmp + 2] == '>')
	{
		*redir_type = 1;
		(*tmp) += 3;
	}
	else if (str[*tmp + 1] == '>')
	{
		*redir_type = 0;
		(*tmp) += 2;
	}
	else
		return (0);
	return (1);
}

int			find_if_is_redir(char *str, size_t *tmp, int *fd, int *redir_type)
{
	if ((str[*tmp] == '<' && str[*tmp + 1] == '<')
		|| (str[*tmp] == '>' && str[*tmp + 1] == '>'))
		double_redir_without_number(redir_type, str, tmp);
	else if (str[*tmp] == '<' || str[*tmp] == '>')
		simple_redir_without_number(redir_type, str, tmp);
	else if (ft_isdigit(str[*tmp]))
	{
		if (!redir_with_number(fd, redir_type, str, tmp))
			return (0);
	}
	return (1);
}
