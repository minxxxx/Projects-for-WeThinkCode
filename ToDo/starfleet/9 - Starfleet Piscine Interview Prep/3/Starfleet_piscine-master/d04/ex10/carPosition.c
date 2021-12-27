#include "header.h"

int carPosition(unsigned int parkingRow)
{
	int ret = -1;
	if (parkingRow & (parkingRow - 1))
		return ret;
	while (parkingRow & -parkingRow)
	{
		parkingRow >>= 1;
		ret++;
	}
	return ret;
}
