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

	enqueue(queue, "FIRST");
	enqueue(queue, "HII");
	enqueue(queue, "My");
	enqueue(queue, "name");
	enqueue(queue, "is");
	enqueue(queue, "rob");
	enqueue(queue, "LAST");

	while (!isEmpty(queue))
		printf("%s\n", dequeue(queue));
	printf("%s\n", peek(queue));
	return (0);
}



// Function used for the test
// Don't go further :)
