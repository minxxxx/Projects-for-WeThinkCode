#include "header.h"
 int leftmostCar(unsigned int parkingRow)
 {
	int ret;
	ret = -1;
	while (parkingRow)
	{
		ret++;
		parkingRow >>= 1;
	}
	return ret;
}
