/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_function_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

size_t		ft_str2len(char **array)
{
	int i;

	i = 0;
	if (array)
	{
		while (array[i])
		{
			i++;
		}
	}
	return (i);
}

char		*concat_chdir(char *path, t_env **env, t_data *data, int i)
{
	char	*dirs;
	char	*full;
	char	**dir_l;

	dirs = find_var_env(data, "CHDIR", *env);
	if (!ft_strequ(dirs, ""))
	{
		dir_l = ft_lz_strsplit(dirs, ':');
		i = 0;
		while (dir_l[i])
		{
			full = triple_join(dir_l[i], "/", path);
			if (access(full, F_OK) == 0)
			{
				ft_str2del(dir_l);
				return (full);
			}
			ft_strdel(&full);
			i++;
		}
		ft_str2del(dir_l);
	}
	else
		free(dirs);
	return (NULL);
}

void		ft_remove_endchar(char *str, char c)
{
	size_t	len;

	len = ft_strlen(str);
	if (str[len - 1] == c)
		str[len - 1] = '\0';
}

char		*remove_duplicate_slash(char *path)
{
	char	*ready;

	if (ft_strstr(path, "//"))
	{
		ready = strdup_skip(path);
		return (ready);
	}
	else
	{
		return (ft_strdup(path));
	}
}

void		ft_str2defrag(char **array, size_t origin_size)
{
	size_t	i;
	size_t	j;
	size_t	b;

	i = 0;
	if (origin_size != ft_str2len(array))
	{
		while (i < origin_size + 1)
		{
			if (array[i] == NULL)
			{
				b = i;
				j = i + 1;
				while (j < origin_size + 1)
				{
					array[i] = array[j];
					i++;
					j++;
				}
				i = b;
			}
			i++;
		}
	}
}
