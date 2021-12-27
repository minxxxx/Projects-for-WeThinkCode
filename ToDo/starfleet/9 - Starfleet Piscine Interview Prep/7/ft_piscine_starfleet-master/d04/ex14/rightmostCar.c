#include "header.h"

int rightmostCar(unsigned int parkingRow)
{
	if (parkingRow == 0)
		return (-1);
	parkingRow = parkingRow & -parkingRow;
	return (log2(parkingRow));
}
