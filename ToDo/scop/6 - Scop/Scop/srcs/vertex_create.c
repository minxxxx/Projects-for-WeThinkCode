/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:41:11 by khansman          #+#    #+#             */
/*   Updated: 2016/11/25 09:41:13 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

t_vertex	vertex_create(float x, float y, float z, float w)
{
	t_vertex	vertex;

	ft_bzero(&vertex, sizeof(t_vertex));
	vertex.type = TYPE_VERTEX;
	vertex.x = x;
	vertex.y = y;
	vertex.z = z;
	vertex.w = w;
	return (vertex);
}
