/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 17:42:02 by smonroe           #+#    #+#             */
/*   Updated: 2019/01/10 20:19:29 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
struct s_info   getInfo(struct s_node *root)  // TIME O(n) SPACE O(1) 
{
	struct s_info info = {INT_MAX, INT_MIN, 0, 0, 0, 0};
	min_max_count(root, &info.min, &info.max, &info.elements);
	info.isBST = is_bst(root);
	info.isBalanced = is_balanced(root, &info.height);//wtf);
	return info;
}

void	min_max_count(struct s_node *root, int *min, int *max, int *count)
{
	if (!root) return ;
	*count += 1;
	if (root->value < *min)
		*min = root->value;
	if (root->value > *max)
		*max = root->value;
	min_max_count(root->left, min, max, count);
	min_max_count(root->right, min, max, count);
}

int is_bst(struct s_node *root)  // TIME O(n) SPACE O(1) DFT
{
	static struct s_node *prev = 0;
	if (!root) return 1;
	if (!is_bst(root->left)) return 0;
	if (prev && root->value <= prev->value) return 0;
	prev = root;
	return is_bst(root->right);
}

int is_balanced(struct s_node *root, int *height)
{
	int lh = 0, rh = 0, l = 0, r = 0;
	if (!root)
	{
		*height = 0;
		return 1;
	}
	l = is_balanced(root->left, &lh);
	r = is_balanced(root->right, &rh);
	*height = (lh > rh ? lh : rh) + 1;
	if (lh - rh > 1 || rh - lh > 1)
		return 0;
	return l && r;
}
