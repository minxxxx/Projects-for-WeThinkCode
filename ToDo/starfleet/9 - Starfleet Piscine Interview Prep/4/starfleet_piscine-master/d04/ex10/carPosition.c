#include "header.h"

int carPosition(unsigned int parkingRow)
{
	int i;
	int pos;

	if (!parkingRow || (parkingRow & (parkingRow - 1)))
		return (-1);
	i = 1;
	pos = 0;
	while (!(i & parkingRow))
	{
		i <<= 1;
		pos++;
	}
	return (pos);
}