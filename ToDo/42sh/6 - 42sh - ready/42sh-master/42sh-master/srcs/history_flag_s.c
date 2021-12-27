/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_flag_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:15 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

void		delete_last_history(t_data *data)
{
	t_history	*list;

	list = data->history;
	if (list)
	{
		if (list->prec)
		{
			data->history = list->prec;
			data->history->next = NULL;
		}
		else
			data->history = NULL;
		free(list->line);
		free(list);
	}
}

char		*history_subsitution_nb_arg(t_data *data, char *command)
{
	int			nb;
	t_history	*list;
	int			i;

	if ((nb = ft_atoi(command)) == 0)
		return (NULL);
	if ((list = data->history) == NULL)
		return (NULL);
	while (list->prec)
		list = list->prec;
	i = 1;
	while (list->next && nb > i)
	{
		i++;
		list = list->next;
	}
	if (nb == i)
		return (ft_strdup(list->line));
	ft_putstr_fd("42sh: history position out of range\n", 2);
	return (NULL);
}

int			history_flag_s(t_data *data, char **scmd)
{
	int		j;

	j = 0;
	while (scmd[j] != NULL)
	{
		data->history = add_history_elem(data->history,
				create_history_elem(scmd[j]));
		j++;
	}
	return (0);
}
