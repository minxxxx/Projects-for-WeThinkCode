/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 14:00:46 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/26 14:15:03 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define WCHAR_MASK_1 "0xxxxxxx"
#define WCHAR_MASK_2 "110xxxxx 10xxxxxx"
#define WCHAR_MASK_3 "1110xxxx 10xxxxxx 10xxxxxx"
#define WCHAR_MASK_4 "11110xxx 10xxxxxx 10xxxxxx 10xxxxxx"

char	**apply_mask(char *bin, char *m)
{
	int		length_bin;
	int		length_mask;
	char	*mask;
	size_t	i;

	mask = ft_strdup(m);
	length_bin = ft_strlen(bin) - 1;
	length_mask = ft_strlen(mask) - 1;
	while (length_mask >= 0 && length_bin >= 0)
	{
		if (mask[length_mask] == 'x')
		{
			mask[length_mask] = bin[length_bin];
			length_bin--;
		}
		length_mask--;
	}
	i = 0;
	while (i < ft_strlen(mask))
	{
		if (mask[i] == 'x')
			mask[i] = '0';
		i++;
	}
	return (ft_strsplit(mask, ' '));
}

void	ft_putwchar(wchar_t c)
{
	int		character;
	char	*bin;
	char	**mask;
	int		to_print;
	int		i;

	character = (int)c;
	bin = ft_itoa_base(character, 2, 0);
	if (ft_strlen(bin) <= 7)
		mask = apply_mask(bin, WCHAR_MASK_1);
	else if (ft_strlen(bin) <= 11)
		mask = apply_mask(bin, WCHAR_MASK_2);
	else if (ft_strlen(bin) <= 16)
		mask = apply_mask(bin, WCHAR_MASK_3);
	else
		mask = apply_mask(bin, WCHAR_MASK_4);
	ft_memdel((void **)&bin);
	i = 0;
	while (mask[i])
	{
		to_print = ft_atoi_base(mask[i], 2);
		write(1, &to_print, 1);
		i++;
	}
	ft_memdel((void **)mask);
}
