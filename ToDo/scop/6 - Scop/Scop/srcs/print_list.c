/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:37:45 by khansman          #+#    #+#             */
/*   Updated: 2016/11/25 09:49:03 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

/*
**	This file is debug purposes, to test the content of the linked list
*/

void	print_vetex(t_vertex *vertex)
{
	printf("\tTYPE:\t%s\n", (vertex->type == TYPE_VERTEX) ?
		P_VERTEX : "unknown");
	printf("\tX:\t%f\n", vertex->x);
	printf("\tY:\t%f\n", vertex->y);
	printf("\tZ:\t%f\n", vertex->z);
	printf("\tW:\t%f\n", vertex->w);
}

void	print_vertex2(t_vertex2 *vertex)
{
	printf("\tTYPE:\t%s\n", (vertex->type == TYPE_TEXTURE) ? P_VERTEX2
		: "unknown");
	printf("\tU:\t%f\n", vertex->u);
	printf("\tV:\t%f\n", vertex->v);
	printf("\tW:\t%f\n", vertex->w);
}

void	print_face(t_face *face)
{
	printf("\tTYPE:\tface\n");
	printf("\tVERTEX SET: %s; TEXTURE SET %s; NORMAL SET %s\n",
		(face->set & F_VERTEX) ? "YES" : "NO",
		(face->set & F_TEXTURE) ? "YES" : "NO",
		(face->set & F_NORMAL) ? "YES" : "NO");
	if (face->set & F_VERTEX)
		printf("\tX:\t%d\n\tY:\t%d\n\tZ:\t%d\n\tW:\t%d\n",
			face->x, face->y, face->z, face->w);
	if (face->set & F_TEXTURE)
		printf("\tT_X:\t%d\n\tT_Y:\t%d\n\tT_Z:\t%d\n",
			face->t_x, face->t_y, face->t_z);
	if (face->set & F_NORMAL)
		printf("\tN_X:\t%d\n\tN_Y:\t%d\n\tN_Z:\t%d\n",
			face->n_x, face->n_y, face->n_z);
}

void	print_list_details(t_list *pos, unsigned int k)
{
	char	tmp;

	if (pos == NULL)
	{
		ft_putendl("Error: print_list_details called with a NULL argument");
		return ;
	}
	printf("List Item [%u]: size: %zu; Has Content: %s, Has next: %s\n",
			k, pos->content_size,
			((pos->content != NULL) ? "YES" : "NO"),
			((pos->next != NULL) ? "YES" : "NO"));
	if (pos->content_size && pos->content != NULL)
	{
		ft_memcpy(&tmp, pos->content, 1);
		if (tmp == TYPE_VERTEX || tmp == TYPE_NORMAL)
			print_vetex((t_vertex *)(pos->content));
		else if (tmp == TYPE_FACE)
			print_face((t_face *)(pos->content));
		else if (tmp == TYPE_PSPACE || tmp == TYPE_TEXTURE)
			print_vertex2((t_vertex2 *)(pos->content));
		else
			printf("\tTYPE:\tunknown\n");
	}
}

void	print_list(t_list *list)
{
	t_list			*pos;
	unsigned int	k;

	if (list == NULL)
	{
		ft_putendl("Error: print_list called with a NULL argument");
		return ;
	}
	pos = list;
	k = 0;
	ft_putendl("--- PRINTING LINKED LIST ---");
	while (pos != NULL && (++k + 1))
	{
		print_list_details(pos, k);
		pos = pos->next;
	}
	ft_putendl("--- DONE PRINTING LINKED LIST ---");
}
