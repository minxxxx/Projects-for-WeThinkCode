
#include "header.h"

int rightmostCar(unsigned int parkingRow)
{
	return ((!parkingRow) ? -1 : (rightmostCar(parkingRow & 1) ? 1 : rightmostCar(parkingRow << 1)));
}
