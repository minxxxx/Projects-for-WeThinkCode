#ifndef HEADER_H
# define HEADER_H
# include <limits.h>
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
void	min_max_count(struct s_node *root, int *min, int *max, int *count);
int		height(struct s_node *root);
int		is_bst(struct s_node *root);
int		is_balanced(struct s_node *root, int *height);
#endif
