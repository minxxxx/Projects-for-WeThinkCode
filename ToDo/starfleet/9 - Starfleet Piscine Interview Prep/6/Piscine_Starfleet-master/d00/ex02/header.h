#ifndef HEADER_H
# define HEADER_H
# include <string.h>
# include <stdio.h>
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

int searchPrice(struct s_art **arts, int n, char *name);


/*--------------------------------
  ?? test function used in main 
  --------------------------------*/

struct s_art **getArts(int *n);


/*--------------------------------
  &  your own other function
  --------------------------------*/

int binary_search(struct s_art **arts, int s, int n, char *name);

#endif
