
#include "header.h"

int isFilled(unsigned int parkingRow)
{
	return !((parkingRow + 1) & parkingRow);
}
