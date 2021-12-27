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
char *rightShift(char *bin, int k);
char *leftShift(char *bin, int k);
int toInt(char *bits);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/
int checkBinary(char *str);

/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
