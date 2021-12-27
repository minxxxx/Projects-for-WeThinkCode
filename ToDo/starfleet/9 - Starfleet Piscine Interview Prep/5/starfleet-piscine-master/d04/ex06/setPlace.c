
#include "header.h"

unsigned int setPlace(unsigned int parkingRow, int pos)
{
	return (parkingRow | (1 << pos));
}