/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

void		list_auto_doesnt_exist(t_data *data)
{
	int	index_to_go;

	index_to_go = data->absolute_index_before_move;
	while (data->index > 0)
		move_left_without_mod(data);
	ft_putstr(data->absolute_cmd_before_auto);
	free(data->cmd);
	data->cmd = data->absolute_cmd_before_auto;
	data->index = ft_strlen(data->cmd);
	while (data->index > index_to_go)
		move_left_without_mod(data);
	data->cmd_before_auto = NULL;
	data->absolute_cmd_before_auto = NULL;
	data->index_before_auto = 0;
	data->index_before_move = 0;
	return ;
}

void		ft_autocomplete_2(t_data *data, char *tmp)
{
	int	index_to_go;

	data->index += ft_strlen(tmp);
	data->cmd = ft_strjoinaf1(data->cmd, tmp);
	tmp = data->absolute_cmd_before_auto + data->index_before_move;
	index_to_go = data->index;
	ft_putstr(tmp);
	data->index += ft_strlen(tmp);
	data->cmd = ft_strjoinaf1(data->cmd, tmp);
	while (data->index > index_to_go)
		move_left_without_mod(data);
}

void		ft_autocomplete(t_data *data)
{
	char		*tmp;

	if (is_empty_border_in_actual_cmd(data->cmd, data->index))
		return ;
	find_list_auto(data);
	if (!data->list_auto)
		return (list_auto_doesnt_exist(data));
	while (data->index > data->index_before_move)
		move_left_without_mod(data);
	exec_tcap("cd");
	tmp = data->cmd;
	data->cmd = ft_strsub(data->cmd, 0, data->index);
	free(tmp);
	tmp = data->list_auto->str +
		ft_strlen(find_ptr(data->absolute_cmd_before_cmd_before_move));
	ft_putstr(tmp);
	ft_autocomplete_2(data, tmp);
}
