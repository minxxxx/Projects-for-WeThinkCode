/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findParent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 11:16:34 by jaleman           #+#    #+#             */
/*   Updated: 2017/08/04 11:16:34 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <strings.h>

struct s_node		*findParent(struct s_node *root, \
									char *firstSpecies, char *secondSpecies)
{
	int				check;
	struct s_node	*tmp;
	struct s_node	*parent;

	check = 0;
	tmp = NULL;
	if (!strcmp(root->name, firstSpecies) || !strcmp(root->name, secondSpecies))
		return (root);
	for (int i = 0; root->children[i]; i += 1)
	{
		parent = findParent(root->children[i], firstSpecies, secondSpecies);
		if (parent == NULL)
			continue ;
		else if (parent && ++check)
			tmp = parent;
		else
			break ;
	}
	return (check == 2 ? root : tmp);
}
