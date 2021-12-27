/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_wchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 13:07:51 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/11 15:38:39 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*uint_to_binary(unsigned int n)
{
	int		i;
	char	*bits;

	if (!(bits = (char *)malloc((sizeof(char)) * 33)))
		return (NULL);
	ft_bzero((void *)bits, 33);
	i = 31;
	while (n > 0)
	{
		bits[i] = (n % 2) + '0';
		n = n / 2;
		i--;
	}
	return (bits);
}

int		binary_to_int(char *bits, int i)
{
	int	j;
	int	n;

	j = 1;
	n = 0;
	while (j <= 128)
	{
		n = n + ((bits[i] - '0') * j);
		i--;
		j = j * 2;
	}
	return (n);
}

char	*set_unicode_binary(char *bits, int i)
{
	char	*mask;
	int		j;

	if (i < 12)
		mask = ft_strdup("110xxxxx 10xxxxxx");
	else if (i < 17)
		mask = ft_strdup("1110xxxx 10xxxxxx 10xxxxxx");
	else
		mask = ft_strdup("11110xxx 10xxxxxx 10xxxxxx 10xxxxxx");
	i = 31;
	j = (ft_strlen(mask) - 1);
	while (j > 0)
	{
		if (bits[i] && mask[j] == 'x')
		{
			mask[j] = bits[i];
			i--;
		}
		else if (!bits[i] && (mask[j] == 'x'))
			mask[j] = '0';
		j--;
	}
	return (mask);
}

void	display_wchar(wchar_t c)
{
	char	*bits;
	int		i;

	i = 31;
	bits = uint_to_binary((unsigned int)c);
	while (bits[i])
		i--;
	i = 31 - i;
	if (i < 8)
	{
		ft_putchar(binary_to_int(bits, 31));
		free(bits);
	}
	else
		display_wchar1(bits, i);
}

void	display_wchar1(char *bits, int i)
{
	int		int_byte;
	char	*tmp;
	char	**bytes;

	int_byte = 0;
	tmp = set_unicode_binary(bits, i);
	free(bits);
	bytes = ft_strsplit(tmp, ' ');
	free(tmp);
	i = 0;
	while (bytes[i])
	{
		int_byte = binary_to_int(bytes[i], 7);
		write(1, &int_byte, 1);
		free(bytes[i]);
		i++;
	}
	free(bytes);
}
