#include "header.h"

unsigned int clearBits(unsigned int parkingRow, int n)
{
	return parkingRow & ~((1 << n) - 1);
}
