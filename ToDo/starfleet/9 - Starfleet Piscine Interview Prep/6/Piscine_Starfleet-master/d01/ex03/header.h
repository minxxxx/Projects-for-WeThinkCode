#ifndef HEADER_H
# define HEADER_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# define MAX 255
//# define PRINT(s, x) (printf(s, x) && fflush(stdout))
# define PRINT(s) (printf(s) && fflush(stdout))
# define SCAN(s, x) (scanf(s, x) && fflush(stdin))
/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_item {
	int idx;
	struct s_item *next;
};

struct s_stack {
	struct s_item *item;
};

/*--------------------------------
  :) function you must implement
  --------------------------------*/
struct s_stack *initStack();
void push(struct s_stack *stack, int idx);
int pop(struct s_stack *stack);

char *console(void);

/*--------------------------------
  ?? test function used in main
  --------------------------------*/


/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
