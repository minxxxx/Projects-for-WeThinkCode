#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{

	/*-------------------
	launch your test here
	--------------------*/	

	struct s_queue *q = queueInit();
	printf("is empty: %d\n", isEmpty(q));
	printf("msg: %s\n", dequeue(q));
	enqueue(q, "first");
	enqueue(q, "second");
	enqueue(q, "third");
	printf("msg: %s\n", peek(q));
	printf("msg: %s\n", dequeue(q));
	printf("msg: %s\n", dequeue(q));
	printf("msg: %s\n", dequeue(q));
	printf("msg: %s\n", dequeue(q));
	return (0);
}



// Function used for the test
// Don't go further :)

