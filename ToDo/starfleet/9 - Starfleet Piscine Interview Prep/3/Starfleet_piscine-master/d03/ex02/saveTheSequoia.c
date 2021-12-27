#include <stdio.h>
#include "header.h"

// void saveTheSequoia(struct s_node **root)
// {
// 	struct s_node *curr;
// 	struct s_node *temp;
//
// 	curr = *root;
// 	// printf("%d\n", curr->value);
// 	if (curr->left)
// 	{
// 		saveTheSequoia(&curr->left);
// 		if (curr->value < curr->left->value)
// 		{
// 			temp = curr;
// 			curr = curr->left;
// 			curr->left = temp;
// 		}
// 	}
// 	if (curr->right)
// 	{
// 		saveTheSequoia(&curr->right);
// 		if (curr->value > curr->right->value)
// 		{
// 			printf("%s\n", "here");
// 			temp = curr;
// 			curr = curr->right;
// 			curr->right = temp;
// 		}
// 	}
// }

void util(struct s_node *p1, struct s_node *n1, struct s_node *p2,
struct s_node *n2)
{
	struct s_node temp;

	if (p1)
	{
		if (p1->left == n1)
			p1->left = n2;
		else
			p1->right = n2;
	}
	if (p2)
	{
		if (p2->left == n2)
			p2->left = n1;
		else
			p2->right = n1;
	}
	temp.left = n1->left;
	temp.right = n1->right;
	n1->left = n2->left;
	n1->right = n2->right;
	n2->left = temp.left;
	n2->right = temp.right;
}

void saveTheSequoia(struct s_node **root)
{
	static struct s_node *parent;
	struct s_node *this_parent;
	struct s_node *largest;

	if (!root || !*root)
		return;
	this_parent = parent;
	parent = *root;
	saveTheSequoia(&((*root)->right));
	saveTheSequoia(&((*root)->left));
	largest = *root;
	if ((*root)->left && (*root)->left->value > largest->value)
		largest = (*root)->left;
	if ((*root)->right && (*root)->right->value > largest->value)
		largest = (*root)->right;
	if (largest != *root)
	{
		util(this_parent, *root, *root, largest);
		saveTheSequoia(&largest);
	}
	*root = largest;
	parent = this_parent;
}
