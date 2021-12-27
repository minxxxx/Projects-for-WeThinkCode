
#include "header.h"

unsigned int log2n(unsigned int n)
{
   return (!(n > 1) ? 0 : log2n(n >> 1) + 1);
}
 
int isPowerOfTwo(unsigned n)
{
    return (n && !(n & (n-1)));
}
 
int carPosition(unsigned n)
{
    if (!isPowerOfTwo(n))
        return (-1);
    return (log2n(n));
}
