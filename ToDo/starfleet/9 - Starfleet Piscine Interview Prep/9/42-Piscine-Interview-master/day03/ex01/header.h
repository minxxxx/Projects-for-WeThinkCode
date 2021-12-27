#ifndef HEADER_H
# define HEADER_H

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

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


/*--------------------------------
  &  your own other function
  --------------------------------*/

typedef struct s_node t_node;

t_node *new_node(int val);
#endif
