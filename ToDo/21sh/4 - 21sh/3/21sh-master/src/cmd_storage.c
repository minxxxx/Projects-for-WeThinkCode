/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_storage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 11:04:50 by fkoehler          #+#    #+#             */
/*   Updated: 2016/09/22 19:21:23 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_btree	*store_cmd(char *str)
{
	int		i;
	t_btree	*new;

	if (!(new = (t_btree *)malloc(sizeof(*new))))
		quit_error(9);
	new->str = NULL;
	new->redir = NULL;
	if ((i = strrchr_outside_quotes(ft_strdup(str), ';', 0)) != -1)
		new->type = SEM;
	else if ((i = strrchr_outside_quotes(ft_strdup(str), '|', 0)) != -1)
		new->type = PIP;
	if (i != -1 && ++i)
	{
		new->left = store_cmd(ft_strsub(str, 0, i - 1));
		new->right = store_cmd(ft_strsub(str, i, (ft_strlen(str) - i)));
		free(str);
	}
	else
	{
		new->type = CMD;
		new->str = str;
		new->left = NULL;
		new->right = NULL;
	}
	return (new);
}
