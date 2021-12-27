#ifndef HEADER_H
# define HEADER_H
#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <time.h>
/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_node {
	int value;
	struct s_node *right;
	struct s_node *left;
};

struct s_info {
	int min;        // the minimum value in the tree
	int max;        // the max value in the tree
	int elements;   // the number of nodes in the tree
	int height;     // the height of the tree
	int isBST;      // 0 = FALSE, 1 = TRUE
	int isBalanced; // 0 = FALSE, 1 = TRUE
};

/*--------------------------------
  :) function you must implement
  --------------------------------*/
struct s_info   getInfo(struct s_node *root);


/*--------------------------------
  ?? test function used in main
  --------------------------------*/
void printBinaryTree(struct s_node * t); //print a binary tree
struct s_node *genRandomBinaryTree(unsigned seed); //gen a random binary tree
void    printTreeInfo(struct s_info info); //print the info from a binary tree


/*--------------------------------
  &  your own other stuff
  --------------------------------*/
typedef struct s_node t_node;
typedef struct s_info t_info;
void traverse_tree(t_node *root, t_info *info, int h);
int height_tree(t_node *root, int h);
#endif
