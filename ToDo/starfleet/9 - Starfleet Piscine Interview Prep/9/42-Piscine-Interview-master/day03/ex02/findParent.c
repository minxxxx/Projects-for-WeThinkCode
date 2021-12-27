/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findParent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 02:50:37 by amontano          #+#    #+#             */
/*   Updated: 2019/01/12 02:50:39 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_node 
*find_it(t_node *root, char *firstSpecies, char *secondSpecies, int *found)
{
    t_node                  *tmp;
    t_node                  *cur;
    int                     match = 0;

    tmp = NULL;
    if (!strcmp(root->name, firstSpecies))
    {
        *found |= 0x01;
        return (root);
    }
     if (!strcmp(root->name, secondSpecies))
     {
        *found |= 0x02;
        return (root);
     }
    for (int i = 0; root->children[i]; i++)
    {
        cur = find_it(root->children[i], firstSpecies, secondSpecies, found);
        if (cur)
        {
            tmp = cur;
            match++;
        }
    }
    return (match == 2 ? root : tmp);
}

struct s_node 
*findParent(struct s_node *root, char *firstSpecies, char *secondSpecies)
{
    int found = 0;
    t_node *parent;

    parent = find_it(root, firstSpecies, secondSpecies, &found);
    return ( found == 0x03 ? parent : NULL );
}
