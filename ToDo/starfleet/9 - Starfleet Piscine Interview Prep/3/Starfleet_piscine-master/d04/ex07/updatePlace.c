#include "header.h"

unsigned int updatePlace(unsigned int parkingRow, int pos, int value)
{
	int save = value << pos;
	save = ~save;
	save = parkingRow & save;
	return (save ^ 1 << pos);
}
