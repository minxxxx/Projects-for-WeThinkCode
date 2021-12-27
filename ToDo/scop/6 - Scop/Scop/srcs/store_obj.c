/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:40:43 by khansman          #+#    #+#             */
/*   Updated: 2016/11/25 09:40:48 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

void	store_struct(void const *struc, size_t size, t_list **pos)
{
	t_list		*new_link;

	if (struc == NULL || pos == NULL || size < 1)
		return ;
	if (!(new_link = ft_lstnew(struc, size)))
		error_quit("Error: failed to store item in memory.");
	if (!g_lst)
	{
		g_lst = new_link;
		(*pos) = new_link;
	}
	else
	{
		(*pos)->next = new_link;
		(*pos) = (*pos)->next;
	}
}

void	store_vertex(char *line, t_list **pos)
{
	t_vertex	vertex;
	char		**parts;

	ft_bzero(&vertex, sizeof(t_vertex));
	parts = ft_strsplit(line, ' ');
	if (parts[1] == NULL || parts[2] == NULL || parts[3] == NULL)
		error_quit("Error: invalid vertex.");
	vertex.type = TYPE_VERTEX;
	vertex.x = atof(parts[1]);
	vertex.y = atof(parts[2]);
	vertex.z = atof(parts[3]);
	vertex.w = (parts[4]) ? atof(parts[4]) : 1.0f;
	ft_free_2d_array(&parts);
	store_struct((void const *)&vertex, sizeof(t_vertex), pos);
}

void	store_normal(char *line, t_list **pos)
{
	t_vertex	vertex;
	char		**parts;

	ft_bzero(&vertex, sizeof(t_vertex));
	parts = ft_strsplit(line, ' ');
	if (parts[1] == NULL || parts[2] == NULL || parts[3] == NULL)
		error_quit("Error: invalid normal.");
	vertex.type = TYPE_NORMAL;
	vertex.x = atof(parts[1]);
	vertex.y = atof(parts[2]);
	vertex.z = atof(parts[3]);
	vertex.w = (parts[4]) ? atof(parts[4]) : 1.0f;
	ft_free_2d_array(&parts);
	store_struct((void const *)&vertex, sizeof(t_vertex), pos);
}

void	store_texture(char *line, t_list **pos)
{
	t_vertex2	vertex;
	char		**parts;

	ft_bzero(&vertex, sizeof(t_vertex2));
	parts = ft_strsplit(line, ' ');
	if (parts[1] == NULL || parts[2] == NULL)
		error_quit("Error: invalid texture.");
	vertex.type = TYPE_TEXTURE;
	vertex.u = atof(parts[1]);
	vertex.v = atof(parts[2]);
	vertex.w = (parts[3] != NULL) ? atof(parts[3]) : 0;
	ft_free_2d_array(&parts);
	store_struct((void const *)&vertex, sizeof(t_vertex), pos);
}

void	store_pspace(char *line, t_list **pos)
{
	t_vertex2	vertex;
	char		**parts;

	ft_bzero(&vertex, sizeof(t_vertex2));
	parts = ft_strsplit(line, ' ');
	if (parts[1] == NULL || parts[2] == NULL)
		error_quit("Error: invalid paramiter space.");
	vertex.type = TYPE_PSPACE;
	vertex.u = atof(parts[1]);
	vertex.v = atof(parts[2]);
	vertex.w = (parts[3] != NULL) ? atof(parts[3]) : 0;
	ft_free_2d_array(&parts);
	store_struct((void const *)&vertex, sizeof(t_vertex), pos);
}
