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
	printf("%d\n", isEmpty(queue));
	enqueue(queue, "LOL");
	printf("%d\n", isEmpty(queue));
	enqueue(queue, "TEST1");
	printf("%s\n", peek(queue));
	enqueue(queue, "TEST2");
	printf("%s\n", dequeue(queue));
	enqueue(queue, "TEST3");
	printf("%s\n", peek(queue));
	printf("%d\n", isEmpty(queue));
	return (0);
}



// Function used for the test
// Don't go further :)

