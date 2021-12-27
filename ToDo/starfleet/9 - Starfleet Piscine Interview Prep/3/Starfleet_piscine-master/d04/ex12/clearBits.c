unsigned int clearBits(unsigned int parkingRow, int n)
{
	parkingRow >>= n;
	parkingRow <<= n;
	return parkingRow;
}
