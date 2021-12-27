#ifndef CONSOLE_H
# define CONSOLE_H

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

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

typedef struct s_stack t_stack;
typedef struct s_item t_item;
#endif
