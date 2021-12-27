#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <string.h>
# define UTENSIL_CNT 15

/*--------------------------------
  !! required structure
  --------------------------------*/


/*--------------------------------
  :) function you must implement
  --------------------------------*/
void countSort(unsigned char *utensils, int n);


/*--------------------------------
  ?? test function used in main
  --------------------------------*/
unsigned char *genRandomUstensils(int *n);
void printUtensils(unsigned char *utensils, int n);

/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
