#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "header.h"

struct s_string		*stringInit(void)
{
	t_string *s = calloc(1, sizeof(t_string));
	s->capacity = 1024;
	s->content = calloc(s->capacity, sizeof(char));
	return s;
}

int stringAppend(struct s_string *s, char *add)
{
	int len;
	int	capacity;

	len = strlen(add);
	capacity = 1;
	while (capacity < len + s->length + 1)
		capacity *= 2;
	if (capacity > s->capacity) {
		s->capacity = capacity;
		s->content = realloc(s->content, s->capacity);
		if (!s->content)
			return 0;
		bzero(s->content + s->length, s->capacity - s->length);
	}
	strcpy(s->content + s->length, add);
	s->length += len;
	return 1;
}

int count_words(char *s, char c)
{
	int words;

	words = 0;
	while (*s)
	{
		if (*s == c)
			words++;
		s++;
	}
	return (words + 1);
}

char		**get_words_array(char *header)
{
	int		i;
	int		words;
	char	**res;
	char	*word;

	words = count_words(header, ',');
	res = calloc(words + 1, sizeof(char *));
	word = strtok(header, ",");
	i = 0;
	while (word)
	{
		res[i++] = strdup(word);
		word = strtok(NULL, ",");
	}
	return (res);
}

char 		*decompress(char *cBook)
{
	int	i;
	int j;
	char *tmp;
	char **words_array;
	char *header;
	t_string *str;

	cBook++;
	i = 0;
	while (cBook[i] != '>')
		i++;
	header = strndup(cBook, i);
	words_array = get_words_array(header);
	str = stringInit();
	cBook += i + 1;
	i = 0;
	while (cBook[i])
	{
		j = 0;
		while (cBook[i + j] && cBook[i + j] != '@')
			j++;
		tmp = strndup(cBook + i, j);
		stringAppend(str, tmp);
		free(tmp);
		i += j;
		if (cBook[i] == '@')
		{
			i++;
			stringAppend(str, words_array[cBook[i] - 1]);
		}
		i++;
	}
	free(header);
	i = 0;
	while (words_array[i])
	{
		free(words_array[i]);
		i++;
	}
	free(words_array);
	tmp = str->content;
	free(str);
	return (tmp);
 }
