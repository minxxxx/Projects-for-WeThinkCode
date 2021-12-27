int longestSequence(unsigned int parkingRow)
{
	int i;

	i = 0;
	while (parkingRow)
	{
		parkingRow = (parkingRow & (parkingRow << 1));
		i++;
	}
	return i;
}
