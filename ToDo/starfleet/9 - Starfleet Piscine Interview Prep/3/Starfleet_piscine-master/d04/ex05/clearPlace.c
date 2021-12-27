#include "header.h"

unsigned int clearPlace(unsigned int parkingRow, int pos)
{
	unsigned int save = 1 << pos;
	save = ~save;
	return(parkingRow & save);
}
