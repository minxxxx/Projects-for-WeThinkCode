/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findParent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 00:27:24 by smonroe           #+#    #+#             */
/*   Updated: 2019/01/11 03:05:01 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_node *find(struct s_node *root, char *firstSpecies, char *secondSpecies)
{
	if (!strcmp(root->name, firstSpecies) || !strcmp(root->name, secondSpecies))
		return root;
	int count = 0;
	struct s_node *tmp = 0, *res = 0;
	for (int i = 0; root->children[i]; i++)
	{
		if ((res = find(root->children[i], firstSpecies, secondSpecies)))
		{
			count++;
			tmp = res;
		}
	}
	if (count == 2) return root;
	return tmp;

}

struct s_node *findParent(struct s_node *root, char *firstSpecies, char *secondSpecies)
{
	struct s_node *res = 0;
	if ((res = find(root, firstSpecies, secondSpecies)))
		if (!strcmp(res->name, firstSpecies) || !strcmp(res->name, secondSpecies))
			return 0;
	return res;
}
