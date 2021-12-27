int getPlace(unsigned int parkingRow, int pos)
{
	int ret = parkingRow >> pos;
	return(ret & 1);
}
