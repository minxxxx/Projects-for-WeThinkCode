
#include "header.h"

int occupiedPlaces(unsigned int parkingRow)
{
	return ((!parkingRow) ? 0 : occupiedPlaces(parkingRow & parkingRow - 1) + 1);
}