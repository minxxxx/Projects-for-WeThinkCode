#ifndef HEADER_H
# define HEADER_H

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_art {
	char *name;
	int price;
};

/*--------------------------------
  :) function you must implement
  --------------------------------*/
void heapSort(struct s_art **masterpiece, int n);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/
struct s_art **getArts(void);

/*--------------------------------
  &  your own other function
  --------------------------------*/
typedef struct s_art t_art;

#endif
