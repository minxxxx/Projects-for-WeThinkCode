/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 13:04:03 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/26 17:10:54 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			set_result(char *result
								, size_t num_strings
								, size_t lengths[num_strings]
								, va_list arguments)
{
	size_t			i;

	i = 0;
	while (i < num_strings)
	{
		ft_memcpy(result, va_arg(arguments, char*), lengths[i]);
		result += lengths[i];
		i++;
	}
}

static size_t		calculate_length(size_t num_strings
										, size_t lengths[num_strings]
										, va_list arguments)
{
	size_t			i;
	size_t			total;

	i = 0;
	total = 0;
	while (i < num_strings)
	{
		lengths[i] = ft_strlen(va_arg(arguments, char*));
		total += lengths[i];
		i++;
	}
	return (total);
}

static void			free_strings(void (*free_str)(), size_t num_strings
									, va_list arguments)
{
	size_t			i;

	i = 0;
	while (i < num_strings)
	{
		free_str(va_arg(arguments, char*));
		i++;
	}
}

char				*ft_strjoinn(size_t num_strings, void (*free_str)(), ...)
{
	va_list			lengthening;
	va_list			concatenating;
	va_list			freeing;
	size_t			lengths[num_strings];
	char			*result;

	va_start(lengthening, free_str);
	va_copy(concatenating, lengthening);
	va_copy(freeing, lengthening);
	result = ft_strnew(calculate_length(num_strings, lengths, lengthening));
	set_result(result, num_strings, lengths, concatenating);
	if (free_str)
		free_strings(free_str, num_strings, freeing);
	va_end(lengthening);
	va_end(concatenating);
	va_end(freeing);
	return (result);
}
