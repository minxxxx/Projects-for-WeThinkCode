#include "header.h"

int isFilled(unsigned int parkingRow)
{
	return (parkingRow & (parkingRow + 1)) ? 0 : 1;
}