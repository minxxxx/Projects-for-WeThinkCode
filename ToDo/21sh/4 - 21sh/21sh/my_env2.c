/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_env2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 18:27:12 by sasiedu           #+#    #+#             */
/*   Updated: 2016/08/07 16:11:04 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		ft_check_var_exist_myenv(char **myenv, char *var)
{
	int		i;

	i = 0;
	while (myenv[i] != NULL)
	{
		if (ft_strncmp(myenv[i], var, ft_strlen(var)) == 0)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_join_var_line(char *var, char *line)
{
	char	*env_line;
	int		size;

	size = ft_strlen(var) + ft_strlen(line) + 2;
	if ((env_line = (char *)malloc(size * sizeof(char))) == NULL)
		return (NULL);
	ft_memset(env_line, 0, size);
	ft_strncpy(env_line, var, ft_strlen(var));
	ft_strncat(env_line, "=", 1);
	ft_strncat(env_line, line, ft_strlen(line));
	env_line[size] = '\0';
	return (env_line);
}

char	**ft_remove_line_myenv(char **myenv, char *var)
{
	char	*tmp;
	int		i;

	if (myenv == NULL || var == NULL)
		return (myenv);
	i = -1;
	while (myenv[++i] != NULL)
	{
		if (ft_strncmp(myenv[i], var, ft_strlen(var)) == 0)
		{
			tmp = myenv[i];
			while (myenv[i + 1] != NULL)
			{
				myenv[i] = myenv[i + 1];
				i++;
			}
			free(tmp);
		}
	}
	myenv[i] = NULL;
	return (myenv);
}

void	ft_print_myenv(char **myenv)
{
	int		i;

	i = -1;
	while (myenv[++i] != NULL)
		ft_putendl(myenv[i]);
}
