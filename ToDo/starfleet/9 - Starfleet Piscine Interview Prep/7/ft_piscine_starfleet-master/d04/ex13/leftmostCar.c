#include "header.h"

int leftmostCar(unsigned int parkingRow)
{
	int l;
	int r;
	int m;

	r = 0;
	l = (sizeof(parkingRow) << 3) - 1;
	while (r <= l)
	{
		m = (l + r) >> 1;
		if (parkingRow & (1 << m) && (parkingRow >> m) == 1)
			return m;
		else if ((parkingRow >> m) == 0)
			l = m - 1;
		else 
			r = m + 1;
	}
	return (-1);
}
