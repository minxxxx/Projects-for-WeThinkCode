/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete_find_list_auto.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

static int	exec_in_path(t_data *data, char ***split,
		char **ptr, char **prefix)
{
	char *path;

	path = find_var_env(data, "PATH", data->env);
	if (ft_strequ(path, ""))
	{
		free(path);
		return (0);
	}
	*split = ft_strsplit(path, ':');
	free(*ptr);
	if (find_ptr(data->cmd))
		*ptr = ft_strdup(find_ptr(data->cmd));
	else
		*ptr = ft_strdup(data->cmd);
	*prefix = ft_strdup("");
	free(path);
	if (find_ptr(data->cmd))
		data->index_in_word_before_auto = data->index_before_move
			- (find_ptr(data->cmd) - data->cmd);
	else
		data->index_in_word_before_auto = 0;
	return (1);
}

static void	arg(t_data *data, char ***split, char **prefix, char **ptr)
{
	char	*tmp;
	char	*ptr_for_chr;

	data->index_in_word_before_auto = ft_strlen(*ptr);
	*split = mallocp(sizeof(char*) * 2);
	if ((ptr_for_chr = ft_strrchr(*ptr, '/')))
	{
		(*split)[0] = ft_strsub(*ptr, 0, ptr_for_chr - *ptr + 1);
		*prefix = ft_strdup((*split)[0]);
		tmp = ft_strdup(ptr_for_chr + 1);
		free(*ptr);
		*ptr = tmp;
	}
	else
	{
		*prefix = ft_strdup("");
		(*split)[0] = ft_strdup("./");
	}
	(*split)[1] = NULL;
}

static char	**exec_with_slash_heavens_door(t_data *data,
		char **ptr_for_chr, char **ptr, char **prefix)
{
	char *tmp;
	char **split;

	split = mallocp(sizeof(char*) * 2);
	split[0] = ft_strsub(*ptr, 0, *ptr_for_chr - *ptr + 1);
	split[1] = NULL;
	tmp = ft_strdup(*ptr_for_chr + 1);
	free(*ptr);
	*ptr = tmp;
	*prefix = ft_strdup(split[0]);
	data->index_in_word_before_auto = data->index;
	return (split);
}

static void	init_new_list(t_data *data)
{
	char	**split;
	char	*ptr;
	char	*prefix;
	char	*ptr_for_chr;

	data->absolute_index_before_move = data->index;
	while (data->cmd[data->index] && data->cmd[data->index] != ' ')
		move_right_without_mod(data);
	data->index_before_move = data->index;
	if (data->absolute_cmd_before_auto)
		free(data->absolute_cmd_before_auto);
	data->absolute_cmd_before_auto = data->cmd;
	data->cmd = ft_strsub(data->cmd, 0, data->index);
	if (data->absolute_cmd_before_cmd_before_move)
		free(data->absolute_cmd_before_cmd_before_move);
	data->absolute_cmd_before_cmd_before_move = ft_strdup(data->cmd);
	if (is_auto_arg(data->cmd, &ptr, 0, 1))
		arg(data, &split, &prefix, &ptr);
	else if ((ptr_for_chr = ft_strrchr(ptr, '/')))
		split = exec_with_slash_heavens_door(data,
				&ptr_for_chr, &ptr, &prefix);
	else if (!exec_in_path(data, &split, &ptr, &prefix))
		return ;
	init_autocomplete(data, split, ptr, prefix);
	free_char_tab(split);
}

void		find_list_auto(t_data *data)
{
	t_auto	*next;

	if (!data->list_auto)
		init_new_list(data);
	else if (data->list_auto->next)
	{
		next = data->list_auto->next;
		free(data->list_auto->str);
		free(data->list_auto);
		data->list_auto = next;
	}
}
