#include "header.h"

unsigned int setPlace(unsigned int parkingRow, int pos)
{
	unsigned int save = 1 << pos;
	return (parkingRow | save);
}
