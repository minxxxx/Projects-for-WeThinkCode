/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 12:12:28 by tfleming          #+#    #+#             */
/*   Updated: 2014/11/09 19:04:09 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
** Note: memory leaks possible if malloc breaks: oops!
*/

static char		*find_word_end(const char *original, char split_on)
{
	char	*end;

	end = ft_strchr(original, split_on);
	if (end)
		return (end);
	return (ft_strchr(original, '\0'));
}

static char		*get_next_word(const char **original, char split_on)
{
	char	*new;
	size_t	length;
	size_t	i;

	while (**original == split_on)
		(*original)++;
	length = find_word_end(*original, split_on) - *original;
	new = malloc(sizeof(char) * (length + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (i < length)
	{
		new[i] = (*original)[i];
		i++;
	}
	*original += length + 1;
	return (new);
}

static size_t	count_words(const char *original, char split_on)
{
	size_t	count;

	while (*original && *original == split_on)
		original++;
	count = 0;
	while (*original)
	{
		while (*original && *original != split_on)
			original++;
		count++;
		while (*original && *original == split_on)
			original++;
	}
	return (count);
}

char			**ft_strsplit(const char *original, char split_on)
{
	char	**new;
	size_t	num;
	size_t	i;

	num = count_words(original, split_on);
	new = malloc(sizeof(char*) * (num + 1));
	i = 0;
	while (i < num)
	{
		new[i] = get_next_word(&original, split_on);
		i++;
	}
	new[i] = NULL;
	return (new);
}
