/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   howManyJesus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 10:23:57 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/31 10:23:57 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <string.h>

# define Q	(31)
# define D	(256)

static int	getHash(size_t len)
{
	int	 	hash;

	hash = 1;
	for (size_t i = 0; i < len - 1; i += 1)
		hash = (hash * D) % Q;
	return (hash);
}

static int	getHashValue(size_t len, char *str)
{
	int		hashValue;

	hashValue = 0;
	for (size_t i = 0; i < len; i += 1)
		hashValue = (D * hashValue + str[i]) % Q;
	return (hashValue);
}

static int	getTotalRepeatedWords(size_t file_len, size_t word_len, \
									char *file_str, char *word_str)
{
	int		total;
	int		hash;
	int		text_hash;
	int		pattern_hash;

	total = 0;
	hash = getHash(word_len);
	text_hash = getHashValue(word_len, file_str);
	pattern_hash = getHashValue(word_len, word_str);
	for (size_t i = 0; i < (file_len - word_len) - 1; i += 1)
	{
		if (text_hash == pattern_hash)
		{
			size_t j;
			for (j = 0; j < word_len; j += 1)
				if (file_str[i + j] != word_str[j])
					break ;
			total += (j < word_len) ? 0 : 1;
		}
		if (i < (file_len - word_len))
		{
			text_hash = (D * (text_hash - file_str[i] * hash) \
						+ file_str[i + word_len]) % Q;
			text_hash += (text_hash < 0) ? Q : 0;
		}
	}
	return (total);
}

int			howManyJesus(char *bible, char *jesus)
{
	size_t	file_len;
	size_t	word_len;

	file_len = strlen(bible);
	word_len = strlen(jesus);
	return (getTotalRepeatedWords(file_len, word_len, bible, jesus));
}
