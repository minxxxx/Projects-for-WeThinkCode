#ifndef HEADER_H
# define HEADER_H

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_prices
{
	double *items;
	int length;
};

/*--------------------------------
  :) function you must implement
  --------------------------------*/
double optimizedBestPrice(int pizzaSize, double *prices);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/

// PARSING

struct s_prices *readList();

/*--------------------------------
  &  your own other function
  --------------------------------*/

typedef struct s_prices t_prices;
#endif
