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

	struct s_queue *queue;

	queue = queueInit();
	enqueue(queue, "4");
	enqueue(queue, "8");
	enqueue(queue, "15");
	enqueue(queue, "16");
	enqueue(queue, "23");
	enqueue(queue, "42");
	printf("%s\n", peek(queue));
	while (!isEmpty(queue))
		printf("%s\n", dequeue(queue));
	return (0);
}



// Function used for the test
// Don't go further :)
