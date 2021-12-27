
#include "header.h"

int leftmostCar(unsigned int parkingRow)
{
	return ((!parkingRow) ? -1 : leftmostCar(parkingRow >> 1) + 1);
}
