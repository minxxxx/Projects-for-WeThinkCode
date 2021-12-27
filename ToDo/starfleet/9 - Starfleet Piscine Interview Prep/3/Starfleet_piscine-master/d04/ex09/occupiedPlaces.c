#include "header.h"

int occupiedPlaces(unsigned int parkingRow)
{
	int c;

	c = 0;
	while (parkingRow)
	{
		c += 1 &parkingRow;
		parkingRow = parkingRow >> 1;
	}
	return c;
}
