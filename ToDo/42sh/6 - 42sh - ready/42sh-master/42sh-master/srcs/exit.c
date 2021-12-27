/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

void		exit_ctrl_d(t_env *env, t_data *data)
{
	free(singleton_termios(NULL, 0));
	history_exit(data);
	delete_list(env);
	delete_heredocs(data);
	delete_list_history(data->history);
	delete_list_var(data->var);
	delete_list_auto(data->list_auto);
	delete_data(data);
	exit(EXIT_SUCCESS);
}
