/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

static char	*print_error_no_path(char *tmp)
{
	ft_putstr_fd("Error : The value of the environment variable PATH", 2);
	ft_putstr_fd(" is not valid or inexistant.\n", 2);
	free(tmp);
	return (NULL);
}

static char	*while_exec(char **split, char *scmd)
{
	int			i;
	DIR			*directory;
	t_dirent	*truc;

	i = 0;
	while (split[i])
	{
		directory = opendir(split[i]);
		while (directory && (truc = readdir(directory)))
		{
			if (ft_strequ(truc->d_name, scmd) &&
					!ft_strequ(truc->d_name, ".") &&
					!ft_strequ(truc->d_name, ".."))
			{
				closedir(directory);
				return (ft_strjoinaf1(ft_strjoin(split[i], "/"), scmd));
			}
		}
		if (directory)
			closedir(directory);
		i++;
	}
	print_cmd_not_found(scmd);
	return (NULL);
}

char		*find_exec(char *scmd, t_data *data, t_env *env)
{
	char	**split;
	char	*tmp;
	char	*ret;

	if (ft_strchr(scmd, '/'))
		return (ft_strdup(scmd));
	tmp = find_var_env(data, "PATH", env);
	if (ft_strequ(tmp, ""))
		return (print_error_no_path(tmp));
	split = ft_strsplit(tmp, ':');
	free(tmp);
	ret = while_exec(split, scmd);
	free_char_tab(split);
	return (ret);
}

int			get_ret(int status, t_data *data)
{
	int ret;

	if (WIFEXITED(status))
		ret = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		ret = WTERMSIG(status);
	else if (WIFSTOPPED(status))
		ret = WSTOPSIG(status);
	else
		ret = (EXIT_FAILURE);
	data->ret = ret;
	return (ret);
}
