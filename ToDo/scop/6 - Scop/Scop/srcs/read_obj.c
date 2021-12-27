/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:39:10 by khansman          #+#    #+#             */
/*   Updated: 2016/11/26 11:29:43 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"

static void	find_vertex_func(char *line, t_list **pos)
{
	if (line[1] == 'n')
		store_normal(line, pos);
	else if (line[1] == 't')
		store_texture(line, pos);
	else if (line[1] == 'p')
		store_pspace(line, pos);
	else
		store_vertex(line, pos);
}

int			read_obj(int ac, char **av)
{
	int			fd;
	char		*line;
	t_list		*pos;

	listener();
	if (ac < 2 || !(av[1]))
		error_quit("Error: please give an object file as the first paramiter.");
	if ((fd = open(av[1], O_RDONLY)) < 0)
		error_quit("Error: Can't open file. Please enter a valid file name.");
	pos = NULL;
	while (get_next_line(fd, &line))
	{
		if (line == NULL)
			continue ;
		trim_str(line);
		if (*line == 'v')
			find_vertex_func(line, &pos);
		else if (*line == 'f')
			store_face(line, &pos);
		else if (*line == 'm' && ft_strstr(line, "mtllib") && !g_mtl_file)
			g_mtl_file = ft_strdup(line);
		free(line);
	}
	return (1);
}
