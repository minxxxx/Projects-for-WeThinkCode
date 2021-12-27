/*
** Returns the number of characters before the first occurrence of a char in a
** string. If char is not found, returns -1.
*/

int	ft_strchlen(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
