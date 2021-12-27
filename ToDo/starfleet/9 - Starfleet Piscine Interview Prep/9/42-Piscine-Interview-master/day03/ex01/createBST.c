/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createBST.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 02:11:41 by amontano          #+#    #+#             */
/*   Updated: 2019/01/12 02:11:44 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_node *new_node(int val)
{
    t_node *new;

    if (!(new = (t_node *)malloc(sizeof(t_node))))
        return (NULL);
    new->value = val;
    new->left = NULL;
    new->right= NULL;
    return (new);
}

t_node *build_BST(int *arr, int init, int end, int n)
{
    int     mid;
    t_node  *cur;

    cur = NULL;
    if (init <= end)
    {
        mid = init + (end - init) / 2;
        cur = new_node(arr[mid]);
        if (mid - 1 > -1)
            cur->left = build_BST(arr, init, mid - 1, n);
        if (init != end && mid + 1 < n)
            cur->right = build_BST(arr, mid + 1, end, n);
    }
    return (cur);
}

struct s_node *createBST(int *arr, int n)
{
    return (build_BST(arr, 0, n, n));
}


