/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 12:46:08 by fkoehler          #+#    #+#             */
/*   Updated: 2016/09/19 17:11:19 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

size_t	lst_len(t_input *lst)
{
	size_t	len;
	t_input	*tmp;

	len = 0;
	if (!(tmp = lst))
		return (0);
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

char	*lst_to_str(t_input *lst)
{
	int		i;
	size_t	len;
	char	*str;

	i = 0;
	len = lst_len(lst);
	if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
		quit_error(9);
	while (len--)
	{
		str[i] = lst->c;
		lst = lst->next;
		i++;
	}
	str[i] = 0;
	return (str);
}

t_input	*get_last_elem(t_input *lst)
{
	t_input	*tmp;

	if (!(tmp = lst))
		return (NULL);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_input	*lst_rchr(t_input *lst, char c)
{
	t_input	*tmp;

	if (!(tmp = lst))
		return (NULL);
	while (tmp->next)
		tmp = tmp->next;
	while (tmp && tmp->c != c)
		tmp = tmp->prev;
	return (tmp);
}
