/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_is_x_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

int			is_physical(char *str)
{
	if (ft_strcmp("-P", str) == 0)
		return (1);
	return (0);
}

int			is_logical(char *str)
{
	if (ft_strcmp("-L", str) == 0)
		return (1);
	return (0);
}

int			is_minus(char *str)
{
	if (ft_strcmp("-", str) == 0)
		return (1);
	return (0);
}

int			is_legal_options(char **str, t_cmd *cmd, t_data *data)
{
	int		ret;

	ret = operate_legal_opts(str, cmd, data);
	if (ret == 0)
	{
		putstr_builtin(cmd, "cd: usage: cd [-L OR -P] [dir]\n", 2);
		data->cd_ret = 1;
		return (0);
	}
	if (ret == -1)
	{
		data->cd_ret = 1;
		return (0);
	}
	return (1);
}
