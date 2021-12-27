/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete_function_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

void		init_autocomplete(t_data *data, char **split,
		char *str_to_equ, char *prefix)
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
			if (ft_strnequ(truc->d_name, str_to_equ, ft_strlen(str_to_equ))
			&& !ft_strequ(truc->d_name, ".") && !ft_strequ(truc->d_name, ".."))
				data->list_auto = add_auto_elem(data->list_auto,
					create_auto_elem(ft_strjoinaf2(prefix,
						ft_strdup(truc->d_name))));
		}
		if (directory)
			closedir(directory);
		i++;
	}
	free(str_to_equ);
	free(prefix);
}

char		*find_ptr(char *cmd)
{
	size_t	i;

	i = ft_strlen(cmd);
	if (i)
		i--;
	while (i > 0 && !ft_isspace2(cmd[i]) && !is_sep(&i, cmd, 0, NULL))
		i--;
	if (!ft_isspace2(cmd[i]) && i == 0)
	{
	}
	else if (!is_sep(&i, cmd, 1, NULL) && !is_sep(&i, cmd, 0, NULL) && cmd[i] &&
			cmd[i + 1])
		i++;
	while (is_sep(&i, cmd, 1, NULL))
		i++;
	if (cmd[i] == ' ')
	{
		return (cmd + ft_strlen(cmd));
	}
	return (cmd + i);
}
