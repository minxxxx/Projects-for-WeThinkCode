#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_node {
	int value;
	int isFinal;
	struct s_node *random;
	struct s_node *next;
};

struct s_item {
  int level;
  struct s_node *node;
  struct s_item *next;
};

struct s_queue {
  struct s_item *first;
  struct s_item *last;
};

/*--------------------------------
  :) function you must implement
  --------------------------------*/
int	minimumMoves(struct s_node *begin); //you must return the minimum number of strokes to access to the final

/*--------------------------------
  ?? test function used in main
  --------------------------------*/
struct s_node *getBoardFromFile(char *file);

/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
