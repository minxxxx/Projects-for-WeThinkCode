#include "header.h"

int carPosition(unsigned int parkingRow)
{
	int i;
	int pos;

	if (parkingRow == 0 || (parkingRow & (parkingRow - 1)) != 0)
		return (-1);
	i = 1;
	pos = 0;
	while ((i & parkingRow) == 0)
	{
		i <<= 1;
		pos++;
	}
	return (pos);
}
