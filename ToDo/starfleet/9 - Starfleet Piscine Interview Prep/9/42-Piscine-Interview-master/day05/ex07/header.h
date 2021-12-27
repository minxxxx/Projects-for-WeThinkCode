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
char *findPalindrome(char *sequence, int nDelete);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/


/*--------------------------------
  &  your own other function
  --------------------------------*/

int isPalindrome(char *l, char *r, int status);
#endif
