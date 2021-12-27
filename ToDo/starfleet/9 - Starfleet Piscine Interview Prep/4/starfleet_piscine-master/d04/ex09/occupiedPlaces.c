#include "header.h"

int occupiedPlaces(unsigned int parkingRow)
{
	int count;
    for (count = 0; parkingRow; count++, parkingRow &= parkingRow - 1);
    return count;
}
