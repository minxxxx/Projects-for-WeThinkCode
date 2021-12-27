#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/

/*--------------------------------
  :) function you must implement
  --------------------------------*/
void printPossibleSlices(int pizzaSize);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/

// DYNAMIC ARRAY

typedef struct s_array {
	int *content;
	int length;
	int sum;
	int capacity;
} t_arr;

struct s_array *arrayInit(void);
int     arrayAppend(struct s_array *arr, int number);
struct s_array *arrayClone(struct s_array *arr);
void    arrayPrint(struct s_array *arr);

/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
