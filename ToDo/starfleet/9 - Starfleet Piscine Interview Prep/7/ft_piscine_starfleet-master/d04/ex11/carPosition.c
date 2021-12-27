#include "header.h"

int carPosition(unsigned int parkingRow)
{
	int pos;

	if (parkingRow == 0)
		return (-1);
	pos = log2(parkingRow);
	if (pow(2, pos) == parkingRow)
		return (pos);
	else
		return (-1);
}
