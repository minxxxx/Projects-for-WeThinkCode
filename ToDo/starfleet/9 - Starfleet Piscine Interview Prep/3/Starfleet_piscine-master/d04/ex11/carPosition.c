#include <math.h>

int carPosition(unsigned int parkingRow)
{
	if (parkingRow & (parkingRow - 1))
		return -1;
	return log2(parkingRow);
}
