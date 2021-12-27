int	ft_in_tab(int search, int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tab[i] == search)
			return (1);
		++i;
	}
	return (0);
}
