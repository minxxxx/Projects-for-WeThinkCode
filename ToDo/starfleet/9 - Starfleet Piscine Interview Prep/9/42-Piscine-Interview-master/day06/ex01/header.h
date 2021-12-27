#ifndef HEADER_H
# define HEADER_H

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...


/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_hotspot {
	int pos;
	int radius;
};

/*--------------------------------
  :) function you must implement
  --------------------------------*/
int selectHotspots(struct s_hotspot **hotspots);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/
struct s_hotspot **readHotspots(char *filename);

/*--------------------------------
  &  your own other function
  --------------------------------*/

typedef struct s_hotspot t_hotspot;
#endif
