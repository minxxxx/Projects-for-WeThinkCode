
#include "header.h"

unsigned int clearBits(unsigned int parkingRow, int n)
{
	return ((parkingRow >> n) << n);
}
