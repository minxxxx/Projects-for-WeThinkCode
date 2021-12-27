/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 18:02:06 by sasiedu           #+#    #+#             */
/*   Updated: 2016/08/07 16:05:45 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char	**myenv_control_tower(char **envp, char *var, char *line, char *rule)
{
	static char		**myenv = NULL;
	char			*tmp;

	tmp = NULL;
	if (ft_strncmp(rule, "load", 4) == 0)
		myenv = ft_load_myenv(envp);
	else if (ft_strcmp(rule, "add") == 0)
		envp = ft_add_line_myenv(envp, var, line);
	else if (ft_strcmp(rule, "remove") == 0)
		envp = ft_remove_line_myenv(envp, var);
	else if (ft_strcmp(rule, "get") == 0)
		tmp = ft_get_line_myenv(envp, var);
	else if (ft_strncmp(rule, "update", 6) == 0)
		envp = ft_update_myenv(envp, var, line);
	else if (ft_strcmp(rule, "print") == 0)
		ft_print_myenv(envp);
	else if (ft_strcmp(rule, "myenv") == 0)
		envp = myenv;
	return (ft_load_myenv(myenv));
}

char	**ft_load_myenv(char **envp)
{
	char	**myenv;
	int		i;
	int		size;

	size = ft_array_size(envp);
	if ((myenv = (char **)malloc(sizeof(myenv) * size + 1)) == NULL)
		ft_error(1, "myenv");
	i = -1;
	while (++i < size)
	{
		myenv[i] = ft_strnew(ft_strlen(envp[i]));
		ft_strncpy(myenv[i], envp[i], ft_strlen(envp[i]));
		myenv[i][ft_strlen(envp[i])] = '\0';
	}
	myenv[i] = 0;
	return (myenv);
}

char	**ft_add_line_myenv(char **myenv, char *var, char *line)
{
	char	**tmpenv;
	int		size;
	int		i;

	if (myenv == NULL || var == NULL)
		return (myenv);
	if (ft_check_var_exist_myenv(myenv, var) == 1)
		return (ft_update_myenv(myenv, var, line));
	size = ft_array_size(myenv);
	if ((tmpenv = (char **)malloc(sizeof(tmpenv) * (size + 2))) == NULL)
		write(2, "error: failed to malloc tmpenv.", 30);
	if (tmpenv == NULL)
		return (myenv);
	i = -1;
	while (++i < size)
		tmpenv[i] = ft_strdup(myenv[i]);
	tmpenv[i] = ft_join_var_line(var, line);
	tmpenv[i + 1] = 0;
	free(myenv);
	return (tmpenv);
}

char	**ft_update_myenv(char **myenv, char *var, char *line)
{
	char	**s;
	int		i;
	int		size;

	if (myenv == NULL || var == NULL)
		return (myenv);
	if (ft_check_var_exist_myenv(myenv, var) == 0)
		return (ft_add_line_myenv(myenv, var, line));
	i = -1;
	size = (int)ft_array_size(myenv) + 1;
	s = (char **)malloc(sizeof(char *) * size);
	while (myenv[++i] != NULL)
	{
		if (ft_strncmp(myenv[i], var, ft_strlen(var)) == 0)
			s[i] = ft_strjoin(var, ft_strjoin("=", line));
		else
			s[i] = ft_strdup(myenv[i]);
	}
	s[i] = 0;
	ft_del_array(myenv);
	return (s);
}

char	*ft_get_line_myenv(char **myenv, char *var)
{
	int		i;
	char	*line;

	if (myenv == NULL || var == NULL)
		return (NULL);
	line = NULL;
	i = -1;
	while (myenv[++i] != NULL)
	{
		if (ft_strncmp(myenv[i], var, ft_strlen(var)) == 0)
		{
			line = ft_strchr(myenv[i], '=');
			break ;
		}
	}
	if (line == NULL)
		return (NULL);
	return (ft_strdup(&line[1]));
}
