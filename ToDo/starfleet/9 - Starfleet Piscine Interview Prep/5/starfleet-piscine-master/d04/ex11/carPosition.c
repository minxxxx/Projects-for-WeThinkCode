
#include "header.h"

unsigned int log2n(unsigned int n)
{
   return (!(n > 1) ? 0 : log2n(n / 2) + 1);
}
 
int isPowerOfTwo(unsigned n)
{
	long	x;
    for (x = 1; x < n; x *= 2) {}
	return ((x == n) ? 1 : 0);
}
 
int carPosition(unsigned n)
{
    if (!isPowerOfTwo(n))
        return (-1);
    return (log2n(n));
}
