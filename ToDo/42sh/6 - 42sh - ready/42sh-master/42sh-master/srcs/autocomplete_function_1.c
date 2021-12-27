/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete_function_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

t_auto	*create_auto_elem(char *content)
{
	t_auto		*elem;

	elem = mallocp(sizeof(t_auto));
	elem->str = content;
	elem->next = NULL;
	return (elem);
}

t_auto	*add_auto_elem(t_auto *list, t_auto *elem)
{
	t_auto		*tmp;

	tmp = list;
	if (list == NULL)
		return (elem);
	while (list->next != NULL)
		list = list->next;
	list->next = elem;
	return (tmp);
}

int		is_auto_arg(char *cmd, char **ptr, size_t i, int first_word)
{
	while (ft_isspace2(cmd[i]))
		i++;
	while (cmd[i])
	{
		while (ft_isspace2(cmd[i]))
		{
			first_word = 0;
			i++;
		}
		if (is_sep(&i, cmd, 1, NULL))
		{
			first_word = 1;
			while (ft_isspace2(cmd[i]))
				i++;
		}
		else if (cmd[i])
		{
			jump_all_quote_for_arg(cmd, &i);
		}
	}
	*ptr = ft_strdup(find_ptr(cmd));
	return (!first_word);
}

int		is_empty_border_in_actual_cmd(char *str, size_t i)
{
	while (!is_sep(&i, str, 1, NULL) && i > 0)
		i--;
	while (ft_isspace2(str[i]))
		i++;
	if (!str[i] || is_sep(&i, str, 0, NULL))
		return (1);
	return (0);
}

void	jump_all_quote_for_arg(char *str, size_t *i)
{
	while (str[*i] && !ft_isspace2(str[*i]) && !is_sep(i, str, 0, NULL))
	{
		if (is_quote_open(str[*i]))
		{
			get_pos_after_quote(i, str);
			if (str[*i])
				(*i)++;
		}
		else
			(*i)++;
	}
}
