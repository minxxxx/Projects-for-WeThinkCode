void	ft_reverse_tab(int **tab, int size)
{
	int		i;
	int		tmp;

	i = 0;
	while (i < size / 2)
	{
		tmp = (*tab)[i];
		(*tab)[i] = (*tab)[size - i - 1];
		(*tab)[size - i - 1] = tmp;
		++i;
	}
}
