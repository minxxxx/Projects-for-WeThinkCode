#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{
	struct s_tank *tank = initTank();

	/*-------------------
	launch your test here
	--------------------*/
	tankPush(tank, 900);
	printf("norm: %d\n", tank->stacks[0]->sum);
	tankPush(tank, 90);
	printf("norm: %d\n", tank->stacks[0]->sum);
	tankPush(tank, 100);
	printf("norm: %d && nitro1: %d\n", tank->stacks[0]->sum, tank->stacks[1]->sum);
	tankPush(tank, 10);
	printf("norm: %d && nitro1: %d\n", tank->stacks[0]->sum, tank->stacks[1]->sum);
	printf("%d - pop\n", tankPop(tank));
	printf("%d - pop\n", tankPop(tank));
	printf("norm: %d && nitro1: %d\n", tank->stacks[0]->sum, tank->stacks[1]->sum);
	printf("%d - pop\n", tankPop(tank));
	printf("norm: %d && nitro1: %d\n", tank->stacks[0]->sum, tank->stacks[1]->sum);
	printf("%d - pop\n", tankPop(tank));
	printf("norm: %d && nitro1: %d\n", tank->stacks[0]->sum, tank->stacks[1]->sum);
	printf("%d - pop\n", tankPop(tank));
	printf("norm: %d && nitro1: %d\n", tank->stacks[0]->sum, tank->stacks[1]->sum);
	printf("%d - pop\n", tankPop(tank));
	printf("norm: %d && nitro1: %d\n", tank->stacks[0]->sum, tank->stacks[1]->sum);
	return (0);
}



// Function used for the test
// Don't go further :)
