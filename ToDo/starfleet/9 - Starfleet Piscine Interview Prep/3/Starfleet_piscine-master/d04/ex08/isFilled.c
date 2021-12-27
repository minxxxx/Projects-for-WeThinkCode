#include "header.h"

int isFilled(unsigned int parkingRow)
{
	unsigned int i = parkingRow;
	i = i + 1;
	if (parkingRow & i)
		return 0;
	else
		return 1;
}
