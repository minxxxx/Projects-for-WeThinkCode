#include "header.h"
int longestSequence(unsigned int parkingRow)
{
	int count;
	for(count = 0; parkingRow; parkingRow &= parkingRow << 1, count++);
	return count;
}