#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

void	print_tank(struct s_tank *t)
{
	if (t->n == 0)
		printf("No energy in the tanks\n");
	for (int i = 0; i < t->n; i++)
		printf("stack %d: %d\n", i, t->stacks[i]->sum);
	printf("\n");
}

int main(void)
{
	struct s_tank *tank = initTank();

	/*-------------------
	launch your test here
	--------------------*/

	tankPop(tank);
	print_tank(tank);

	tankPush(tank, 10);
	print_tank(tank);
	
	tankPush(tank, 50);
	print_tank(tank);

	tankPop(tank);
	print_tank(tank);

	tankPush(tank, 950);
	print_tank(tank);

	tankPush(tank, 100);
	print_tank(tank);

	tankPush(tank, 20);
	print_tank(tank);

	tankPop(tank);
	print_tank(tank);

	tankPop(tank);
	print_tank(tank);

	tankPop(tank);
	print_tank(tank);

	tankPop(tank);
	print_tank(tank);

	tankPop(tank);
	print_tank(tank);

	tankPop(tank);
	print_tank(tank);






	return (0);

}



// Function used for the test
// Don't go further :)
