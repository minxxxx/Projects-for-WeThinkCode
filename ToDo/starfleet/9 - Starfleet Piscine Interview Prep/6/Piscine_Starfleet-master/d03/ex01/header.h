#ifndef HEADER_H
# define HEADER_H
# include <stdlib.h>
# include <stdio.h>
/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_node {
	int value;
	struct s_node *right;
	struct s_node *left;
};


/*--------------------------------
  :) function you must implement
  --------------------------------*/
struct s_node *createBST(int *arr, int n);


/*--------------------------------
  ?? test function used in main 
  --------------------------------*/
void printBinaryTree(struct s_node * t); //print a binary tree
struct s_node *make_empty(struct s_node *t);

/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
