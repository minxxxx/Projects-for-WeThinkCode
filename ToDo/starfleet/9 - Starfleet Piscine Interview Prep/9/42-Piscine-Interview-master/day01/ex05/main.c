#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"


static void display_fuel(t_tank *tank)
{
	for (int i = 0; i <= tank->n; i++)
	{
		if (i == 0)
			printf("[%d - stable]-[ %d ]\t", i, tank->stacks[i]->sum);
		else
			printf("[%d  - nitro]-[ %d ]\t", i, tank->stacks[i]->sum);
	}
	printf("\n");
}

int main(void)
{
	struct s_tank *tank = initTank();

	/*-------------------
	launch your test here
	--------------------*/
	printf("==========Push 100==========\n");
	while (tank->n < 2)
	{
		tankPush(tank, 100);
		display_fuel(tank);
	}
	printf("==========Push 50==========\n");
	while (tank->n < 4)
	{
		tankPush(tank, 50);
		display_fuel(tank);
	}
	printf("========== POP ==========\n");
	while (tank->n > -1)
	{
		display_fuel(tank);
		tankPop(tank);
	}
	return (0);
}



// Function used for the test
// Don't go further :)
