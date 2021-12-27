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
	char          *word;
	struct s_node *next;
};

/*--------------------------------
  :) function you must implement
  --------------------------------*/
void printReverse(struct s_node *lst);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/
struct s_node *createList(char **words, int n);

/*--------------------------------
  &  your own other function
  --------------------------------*/

typedef struct s_node t_node;
#endif
