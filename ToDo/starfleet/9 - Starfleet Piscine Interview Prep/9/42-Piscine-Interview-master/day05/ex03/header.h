#ifndef HEADER_H
# define HEADER_H

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

/*--------------------------------
  !! required structure
  --------------------------------*/


/*--------------------------------
  :) function you must implement
  --------------------------------*/
void sinkIsland(int **map, int row, int col);


/*--------------------------------
  ?? test function used in main 
  --------------------------------*/

void	printMap(int **map);

//PARSER
int **readMap(char *filename);

/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
