#include "header.h"

int rightmostCar(unsigned int parkingRow)
{
	int pos;
	if (!parkingRow)
		return -1;
	for(pos = 0; !(parkingRow & 1); parkingRow>>=1, pos++);
	return pos;
}