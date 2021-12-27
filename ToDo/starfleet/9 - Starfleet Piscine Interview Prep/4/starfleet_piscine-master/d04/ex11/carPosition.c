#include <math.h>
#include "header.h"

int carPosition(unsigned int parkingRow)
{
	if (!parkingRow || (parkingRow & (parkingRow - 1)))
		return (-1);
	return log2(parkingRow);
}
