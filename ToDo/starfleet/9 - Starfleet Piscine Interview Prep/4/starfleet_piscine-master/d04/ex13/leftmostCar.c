#include "header.h"

int leftmostCar(unsigned int parkingRow)
{
	int pos;
	if (!parkingRow)
		return -1;
	for(pos = 0; parkingRow; parkingRow>>=1, pos++);
	return pos - 1;
}