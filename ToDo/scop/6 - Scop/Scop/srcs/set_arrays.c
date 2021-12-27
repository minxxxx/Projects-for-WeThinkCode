/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_arrays.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 14:13:45 by khansman          #+#    #+#             */
/*   Updated: 2016/11/26 14:13:46 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

/*
** NB! pos 0 is the number of vertecies.
** g_vertecies[index]->x
*/

void	set_vertix_arr(void)
{
	int		k;
	t_list	*pos;
	char	tmp;

	if (!(k = count_elements(TYPE_VERTEX)))
		error_quit("Error: no vertecies found.");
	if (!(g_vertecies = (t_vertex **)malloc(sizeof(t_vertex *) * (k + 2))))
		error_quit("Error: failed to malloc memory for vertex array.");
	ft_bzero(g_vertecies, sizeof(t_vertex *) * (k + 2));
	g_num_vertex = k;
	k = -1;
	pos = g_lst;
	while (pos != NULL)
	{
		ft_memcpy(&tmp, pos->content, 1);
		if (tmp == TYPE_VERTEX)
			g_vertecies[++k] = (t_vertex *)(pos->content);
		pos = pos->next;
	}
}
