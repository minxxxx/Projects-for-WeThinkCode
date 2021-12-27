#include "header.h"

void aloneCans(int *arr, int n)
{
	int unique_bit;
	int xor;
	int xor2;

	xor = 0;
	for (int i = 0; i < n; i++)
		xor ^= arr[i];
	unique_bit = xor & (-xor);
	xor = 0;
	xor2 = 0;
	for (int i = 0; i < n; i++)
	{
		if (unique_bit & arr[i])
			xor ^= arr[i];
		else
			xor2 ^= arr[i];
	}
	printf("%d\n%d\n", xor, xor2);
}
