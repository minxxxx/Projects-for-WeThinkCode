/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <dtedgui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 10:08:39 by dtedgui           #+#    #+#             */
/*   Updated: 2016/04/22 18:36:53 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh.h"

t_line g_main_line;

static t_cmd_path		*create_link_cmd_path(char *name, t_cmd_path **head)
{
	t_cmd_path		*new;
	t_cmd_path		*current;

	new = (t_cmd_path *)ft_memalloc(sizeof(t_cmd_path));
	new->name = ft_strdup(name);
	new->next = NULL;
	if (head && *head)
	{
		current = *head;
		while (current->next)
			current = current->next;
		current->next = new;
	}
	return (new);
}

static t_cmd_path		*store_all_cmds(char *path)
{
	DIR				*dirp;
	struct dirent	*file;
	char			**path_array;
	t_cmd_path		*cmds;

	cmds = NULL;
	path_array = ft_strsplit(path, ':');
	while (*path_array)
	{
		if (!(dirp = opendir(*path_array)))
			return (NULL);
		while ((file = readdir(dirp)))
		{
			if (ft_strcmp(file->d_name, ".") && ft_strcmp(file->d_name, "."))
			{
				if (cmds == NULL)
					cmds = create_link_cmd_path(file->d_name, &cmds);
				else
					create_link_cmd_path(file->d_name, &cmds);
			}
		}
		closedir(dirp);
		path_array++;
	}
	return (cmds);
}

t_env					*store_env_variables(char **env)
{
	t_env			*head;
	int				i;
	char			*sep;
	char			*name;
	char			*value;

	i = 0;
	head = NULL;
	while (env[i])
	{
		if (!(sep = ft_strchr(env[i], '=')))
			return (NULL);
		name = ft_strndup(env[i], sep - env[i]);
		value = ft_strdup(sep + 1);
		ft_setenv(name, value, &head);
		i++;
	}
	return (head);
}

static void				main_tmp(t_env *env_list, t_cmd_path *cmds)
{
	t_hist			*history;
	char			*key;

	history = NULL;
	key = ft_strnew(15);
	get_key(env_list, cmds, history, key);
}

int						main(void)
{
	char			*buf;
	extern char		**environ;
	t_env			*env_list;
	int				size_prompt;
	t_cmd_path		*cmds;

	buf = NULL;
	env_list = store_env_variables(environ);
	cmds = store_all_cmds(search_in_env("PATH", env_list));
	execute_command("clear", &env_list, environ);
	size_prompt = prompt(env_list, NULL);
	init_line(size_prompt);
	ft_signal();
	if (raw_terminal_mode() == -1)
		return (-1);
	main_tmp(env_list, cmds);
	default_terminal_mode();
	return (0);
}
