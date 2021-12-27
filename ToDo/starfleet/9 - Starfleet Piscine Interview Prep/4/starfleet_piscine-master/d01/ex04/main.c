#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{
	struct s_queue *queue;
	/*-------------------
	launch your test here
	--------------------*/
	
	queue = queueInit();
	puts("**************************************");
	enqueue(queue, "1st element");
	printf("After 1st enqueue: \n%s\n", queue->last->message);
	printf("%s\n", queue->first->message);
	enqueue(queue, "2nd element");
	printf("After 2nd enqueue: \n%s\n", queue->last->message);
	printf("%s\n", queue->first->message);
	enqueue(queue, "3rd element");
	printf("After 3rd enqueue: \n%s\n", queue->last->message);
	printf("%s\n", queue->first->message);
	enqueue(queue, "4th element");
	printf("After 4th enqueue: \n%s\n", queue->last->message);
	printf("%s\n", queue->first->message);
	enqueue(queue, "5th element");
	printf("After 5th enqueue: \n%s\n", queue->last->message);
	printf("%s\n", queue->first->message);
	enqueue(queue, "6th element");
	printf("After 6th enqueue: \n%s\n", queue->last->message);
	printf("%s\n", queue->first->message);
	enqueue(queue, "last element");
	printf("After last enqueue: \n%s\n", queue->last->message);
	printf("%s\n", queue->first->message);
	puts("**************************************");
	char *ch = peek(queue);
	printf("Peaking: %s\n", ch);
	puts("**************************************");
	printf("1st dequeue: %s\n", dequeue(queue));
	printf("2nd dequeue: %s\n", dequeue(queue));
	printf("3rd dequeue: %s\n", dequeue(queue));
	printf("4th dequeue: %s\n", dequeue(queue));
	printf("5th dequeue: %s\n", dequeue(queue));
	printf("6th dequeue: %s\n", dequeue(queue));
	printf("7th dequeue: %s\n", dequeue(queue));
	puts("**************************************");

	
	return (0);
}



// Function used for the test
// Don't go further :)

