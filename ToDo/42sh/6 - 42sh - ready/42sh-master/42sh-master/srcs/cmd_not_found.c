/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_not_found.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void		free_exec(char *exec)
{
	if (exec)
	{
		free(exec);
		exec = NULL;
	}
}

void		cmd_not_found_1(int *ok, int *absolute_ok, t_cmd *last_found)
{
	(void)last_found;
	*ok = 0;
	*absolute_ok = 0;
	last_found = NULL;
}

t_cmd		*cmd_not_found_0(t_cmd *command, t_data *data, t_env *env,\
		int *absolute_ok)
{
	t_cmd		*last_found;
	char		*exec;
	int			ok;
	int			was_ok;

	ok = 0;
	was_ok = 1;
	exec = NULL;
	last_found = NULL;
	while (command && (command->sep == '|' || was_ok))
	{
		if (command->sep != '|')
			was_ok = 0;
		if (!is_builtin(command->av[0]) &&\
				!(exec = find_exec(command->av[0], data, env)))
			cmd_not_found_1(&ok, absolute_ok, last_found);
		else if (!ok)
		{
			ok = 1;
			last_found = command;
		}
		free_exec(exec);
		command = command->next;
	}
	return (last_found);
}

t_cmd		*cmd_not_found(t_cmd *command, t_data *data, t_env *env)
{
	t_cmd		*last_found;
	int			absolute_ok;

	absolute_ok = 1;
	last_found = NULL;
	if (command->sep != '|')
		return (command);
	last_found = cmd_not_found_0(command, data, env, &absolute_ok);
	if (!absolute_ok)
		return (NULL);
	return (last_found);
}
