#ifndef HEADER_H
# define HEADER_H
# define NUM_STACK 10
# define CAPACITY 1000
# include <stdlib.h>
# include <stdio.h>
/*--------------------------------
  !! required structure
  --------------------------------*/

/*--------------------------------
  :) function you must implement
  --------------------------------*/

// Tank

struct s_elem {
    int energy;
    struct s_elem *next;
};

struct s_stack {
    struct s_elem *elem;
    int sum;
};

struct s_tank {
    struct s_stack **stacks;
    int n;
};

struct s_tank *initTank(void);

void tankPush(struct s_tank *tank, int energy);

int tankPop(struct s_tank *tank);

/*--------------------------------
  ?? test function used in main
  --------------------------------*/


/*--------------------------------
  &  your own other function
  --------------------------------*/

struct s_stack *stackInit();
void push(struct s_stack *stack, int idx);
int pop(struct s_stack *stack);
struct s_elem *new_elem(int energy);

#endif
