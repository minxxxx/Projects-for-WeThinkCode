#include "header.h"

int occupiedPlaces(unsigned int parkingRow)
{
	int count;

	count = 0;
	while(parkingRow)
	{
		parkingRow &= (parkingRow - 1);
		count++;
	}
	return (count);
}
