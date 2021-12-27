#include "header.h"

void aloneCan(int *arr, int n)
{
	int result;

	result = 0;
	for (int i = 0; i < n; i++)
		result ^= arr[i];
	printf("%d\n", result);
}
