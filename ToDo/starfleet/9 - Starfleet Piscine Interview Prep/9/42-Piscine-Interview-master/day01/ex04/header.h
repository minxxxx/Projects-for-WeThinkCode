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

/*
	Queue
*/

struct s_node {
	char          *message;
	struct s_node *next;
};

struct s_queue {
  struct s_node *first;
	struct s_node *last;
};


struct s_queue *queueInit(void);

char *dequeue(struct s_queue *queue);

void enqueue(struct s_queue *queue, char *message);

char *peek(struct s_queue *queue);

int isEmpty(struct s_queue *queue);


/*--------------------------------
  ?? test function used in main 
  --------------------------------*/

/*--------------------------------
  &  your own other function
  --------------------------------*/

typedef struct s_node t_node;
typedef struct s_queue t_q;
#endif
