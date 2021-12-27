/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_answer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 15:33:49 by jcamhi            #+#    #+#             */
/*   Updated: 2017/08/30 15:34:17 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

void		free_answer(t_answer answer)
{
	ft_strdel(&(answer.commentaire));
	ft_strdel(&(answer.str));
}

static char	*get_com(char *str)
{
	int	i;

	i = 0;
	while (str[i] != ' ' && str[i])
		i++;
	while (str[i] == ' ')
		i++;
	return (ft_strdup(str + i));
}

t_answer	get_answer(t_data *data)
{
	t_answer	ret;
	char		*str;
	int			i;

	ret.error = -1;
	ret.str = NULL;
	ret.commentaire = NULL;
	if ((i = get_next_line(data->socket, &str)) <= 0 || !str)
	{
		ret.error = (i < 0 ? -1 : 0);
		return (ret);
	}
	remove_cr(str);
	ret.str = str;
	if ((ret.code = ft_atoi(str)) == 0)
		return (ret);
	if ((ret.commentaire = get_com(str)) == NULL)
		return (ret);
	ret.error = 1;
	return (ret);
}
