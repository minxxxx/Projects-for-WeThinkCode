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
	printf("pk: %s | dq: %s | is: %d\n", peek(q), dequeue(q), isEmpty(q));
	enqueue(q, "R");
	enqueue(q, "A");
	enqueue(q, "C");
	enqueue(q, "E");
	enqueue(q, "C");
	enqueue(q, "A");
	enqueue(q, "R");
	enqueue(q, "!");
	for (int i = 0; i < 4; i++)
		printf("pk: %s | dq: %s | is: %d\n", peek(q), dequeue(q), isEmpty(q));
	enqueue(q, "F");
	enqueue(q, "L");
	enqueue(q, "A");
	enqueue(q, "T");
	enqueue(q, "L");
	enqueue(q, "A");
	enqueue(q, "N");
	enqueue(q, "D");
	for (int i = 0; i < 16; i++)
		printf("pk: %s | dq: %s | is: %d\n", peek(q), dequeue(q), isEmpty(q));
	return (0);
}



// Function used for the test
// Don't go further :)

