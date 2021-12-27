/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boucle_ctrl_d_and_l.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 19:05:35 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

static void	boucle_ctrl_d(t_data *data, t_env **env)
{
	if (data->c == '<')
	{
		reinitialise_heredoc(data, 0);
		create_history(data, env);
	}
	else if (ft_strequ(data->cmd, "") && data->c == '\0')
	{
		ft_putstr_fd("exit", 2);
		exit_ctrl_d(*env, data);
	}
}

static void	boucle_ctrl_l(t_data *data)
{
	int	ind_act;

	if (data->list_auto)
	{
		delete_list_auto(data->list_auto);
		data->list_auto = NULL;
	}
	exec_tcap("cl");
	ft_putstr("\e[38;5;208m");
	ft_putstr(data->prompt);
	ft_putstr("\e[39m");
	ft_putstr(data->cmd);
	ind_act = ft_strlen(data->cmd);
	while (ind_act > data->index)
	{
		exec_tcap("le");
		ind_act--;
	}
}

int			is_boucle_ctrl_d_and_l(t_data *data, char buf[11], t_env **env)
{
	if (buf[0] == 4 && buf[1] == 0)
		boucle_ctrl_d(data, env);
	else if (buf[0] == 12 && buf[1] == 0 && buf[2] == 0 && !data->mode_copy)
		boucle_ctrl_l(data);
	else
		return (0);
	return (1);
}
