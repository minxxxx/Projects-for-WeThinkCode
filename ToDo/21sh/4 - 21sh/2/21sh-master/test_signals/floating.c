#include <stdio.h>
int main(void)
{
	int i = 5;

	i = i / (i - 5);
	printf("%d", i);
	return (0);
}
