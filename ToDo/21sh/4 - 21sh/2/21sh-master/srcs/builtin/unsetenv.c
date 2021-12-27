/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 15:31:52 by sfranc            #+#    #+#             */
/*   Updated: 2017/09/15 16:38:21 by sfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell21.h"

int		ft_isinenv(char *var)
{
	char	*temp;
	int		i;
	int		ret;

	i = 0;
	ret = -1;
	if (!g_shell->env)
		return (ret);
	while (*(g_shell->env + i))
	{
		temp = ft_strsub(*(g_shell->env + i), 0,\
				ft_strchr(*(g_shell->env + i), '=') - *(g_shell->env + i));
		if (ft_strequ(temp, var))
			ret = i;
		i++;
		free(temp);
	}
	return (ret);
}

int		ft_builtin_unsetenv(char **cmd)
{
	int suppr;
	int i;

	i = 1;
	while (cmd[i])
	{
		if ((suppr = ft_isinenv(cmd[i])) != -1)
			ft_supprtotab(&g_shell->env, suppr);
		i++;
	}
	return (EXIT_SUCCESS);
}
