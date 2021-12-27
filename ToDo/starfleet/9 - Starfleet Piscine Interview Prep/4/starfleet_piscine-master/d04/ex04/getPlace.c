#include <stdlib.h> //malloc, free, exit...

int getPlace(unsigned int parkingRow, int pos)
{
	return parkingRow & (1 << pos);
}