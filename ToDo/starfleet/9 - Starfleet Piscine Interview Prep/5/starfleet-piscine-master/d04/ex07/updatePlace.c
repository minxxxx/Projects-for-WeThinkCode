
#include "header.h"

unsigned int updatePlace(unsigned int parkingRow, int pos, int value)
{
	return ((value == 1) ? parkingRow | (value << pos) : parkingRow & ~(value << pos));
}