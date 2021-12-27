/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:41:23 by jcamhi            #+#    #+#             */
/*   Updated: 2018/07/04 16:41:23 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_script.h>

char		*get_shell(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnequ(envp[i], "SHELL=", 6))
			return (envp[i] + 6);
		i++;
	}
	return (NULL);
}

static char	*get_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnequ(envp[i], "PATH=", 5))
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

static void	build_path(char *path, char *filename, char buffer[1024])
{
	size_t	len;

	ft_strcpy(buffer, path);
	len = ft_strlen(path);
	buffer[len] = '/';
	ft_strcpy(buffer + len + 1, filename);
}

int			find_in_path(char *file, char **envp, char buffer[1024])
{
	char	*path;
	char	*ptr;

	path = get_path(envp);
	while ((ptr = ft_strchr(path, ':')))
	{
		*ptr = '\0';
		if (ft_strlen(path) + ft_strlen(file) + 1 <= 1024)
		{
			build_path(path, file, buffer);
			if (access(buffer, X_OK) == 0)
			{
				*ptr = ':';
				return (1);
			}
		}
		*ptr = ':';
		path = ptr + 1;
	}
	return (0);
}
