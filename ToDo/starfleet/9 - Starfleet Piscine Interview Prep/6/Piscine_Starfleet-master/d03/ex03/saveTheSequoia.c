/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saveTheSequoia.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 06:27:14 by smonroe           #+#    #+#             */
/*   Updated: 2019/01/11 07:47:21 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
struct s_node *small(struct s_node *root)
{
	if (!root) return 0;
	if (root->left && root->value < root->left->value)
		return root->left;
	if (root->right && root->value < root->right->value)
		return root->right;
	return root;
}

void ft_swap(struct s_node **a, struct s_node **b)
{
	printf("a: %d --- b: %d\n", (*a)->value, (*b)->value);
	struct s_node *tmp = *a;
	*a = *b;
	*b = tmp;
}

/*
void saveTheSequoia(struct s_node **root)
{
	struct s_node *smallest = 0;
	smallest = (root->right && root->right->value > root->value) ? root->right : (root->left && root->left->value > root->value) ? root->left : root;
	if (smallest->value != (*root)->value) {
		swap(root, &smallest);
		saveTheSequoia(root);
	}
}
*/

//array implementation with indexes :

void saveTheSequoia(struct s_node **root)
{
/*
fiund smallest of root left right
if root is not smallest, swap root with smallest
recurse to the smaller child
*/
	// get left and right child of node at index i
//	struct s_node **left = &((*root)->left);
//	struct s_node **right = &((*root)->right);
 
	struct s_node *swap = *root;

	printf("l: %d | m: %d | r: %d\n", (*root)->left->value, (*root)->value, (*root)->right->value); 
	if ((*root)->left && (*root)->left->value > (*root)->value) {
		printf("left < root\n");
		swap = (*root)->left;
	}
	if ((*root)->right && (*root)->right->value > swap->value) {
		printf("right < swap\n");
		swap = (*root)->right;
	}
	printf("swap: %d\n", swap->value);
	if (swap->value != (*root)->value)
	{
		ft_swap(&swap, root);
		saveTheSequoia(&swap);
	}
/*	// compare A[i] with its left and right child
	// and find smallest value
	if (left < size && A[left] < A[i]) {
		smallest = left;
	}
 
	if (right < size && A[right] < A[smallest]) {
		smallest = right;
	}
 
	// swap with child having lesser value and
	// call heapify-down on the child
	if (smallest != i) {
		swap(A[i], A[smallest]);
		HEAP(A, smallest, size);
		}*/
}
