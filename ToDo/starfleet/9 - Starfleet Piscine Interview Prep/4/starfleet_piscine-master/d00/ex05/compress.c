#include <stdlib.h> //malloc, free, exit...
#include <string.h> //memcpy, strlen, ...
#include <stdio.h> //printf, scanf, ...
#include <ctype.h>

#include "header.h"

int simple_hash(char *str, int size)
{
	int value = 0;
	for(int i = 0; i < size; i++)
		value+=str[i];
	return value;
}

int howManyJesus(char *bible, char *jesus)
{
	int count = 0;
	int pattern_len = strlen(jesus);
	int len = (int)strlen(bible);
	int goal_hash = simple_hash(jesus, pattern_len);
	int roll_hash = simple_hash(bible, pattern_len);
	for(int i = 0; i <  len - pattern_len; i++)
	{
		if (roll_hash == goal_hash && !strncmp(bible + i, jesus, pattern_len))
			count++;
		roll_hash -= bible[i];
		roll_hash += bible[i + pattern_len];
	}
	return count;
}

size_t hash(char *input)
{
    size_t hashval;
    for (hashval = 0; *input != '\0'; input++)
      hashval = *input + 31 * hashval;
    return hashval;
}

struct s_dict *dictInit(int capacity)
{
	struct s_dict *dict = malloc(sizeof(struct s_dict));
	dict->capacity = capacity;
	dict->items = calloc(capacity, sizeof(struct s_item *));
	return dict;
}

int	dictInsert(struct s_dict *dict, char *key, int value)
{
	int index = hash(key) % dict->capacity;
	struct s_item *elem = dict->items[index];
	if (!elem)
	{
		elem = malloc(sizeof(struct s_item));
		elem->key = strdup(key);
		elem->value = value;
		elem->next = NULL;
		dict->items[index] = elem;
		return 1;
	}
	while(elem->next)
		elem = elem->next;
	elem->next = malloc(sizeof(struct s_item));
	if(!(elem->next))
		return 0;
	elem->next->key = strdup(key);
	elem->next->value = value;
	elem->next->next = NULL;
	return 1;
}

int dictSearch(struct s_dict *dict, char *key)
{
	int index = hash(key) % dict->capacity;
	struct s_item *elem = dict->items[index];
	while(elem)
	{
		if (!strncmp(elem->key, key, strlen(key)))
			return elem->value;
		elem = elem->next;
	}
	return -1;
}

char *create_header(struct s_dict *dict, int *header_size)
{
	char	**words;
	char	*header;
	struct s_item	*tmp;
	int		word_count = 0;
	int		j;
	int		word_len;

	for (int i = 0; i < dict->capacity; i++)
	{
		tmp = dict->items[i];
		while (tmp)
		{
			word_count++;
			*header_size += strlen(tmp->key) + 1;
			tmp = tmp->next;
		}
	}
	(*header_size)++;
	words = (char **)malloc(sizeof(char *) * word_count);
	for (int i = 0; i < dict->capacity; i++)
	{
		tmp = dict->items[i];
		while (tmp)
		{
			words[tmp->value] = strdup(tmp->key);
			tmp = tmp->next;
		}
	}
	header = (char *)calloc(*header_size + 1, 1);
	j = 0;
	header[j++] = '<';
	for (int i = 0; i < word_count; i++)
	{
		word_len = strlen(words[i]);
		strncpy(header + j, words[i], word_len);
		free(words[i]);
		j += word_len;
		header[j++] = ',';
	}
	free(words);
	header[--j] = '>';
	return (header);
}

char *get_next_word(char *str, int *word_len)
{
	int i = 0;
	char *word;
	while (str[i] && isalpha(str[i]))
		i++;
	word = strndup(str, i);
	*word_len = i;
	return word;
}

void replace_words(char *book, char *compressed_book, struct s_dict *dict)
{
	char *word;
	int word_len;
	int code;

	while (*book)
	{
		while (*book && !isalpha(*book))
			*(compressed_book++) = *(book++);

		if(!*(word = get_next_word(book, &word_len)))
			return ;

		if ((code = dictSearch(dict, word) + 1))
		{
			*(compressed_book++) = '@';
			*(compressed_book++) = (char) code;
		}
		else
		{
			strncpy(compressed_book, book, word_len);
			compressed_book += word_len;
		}
		book += word_len;
		free(word);
	}
}

char *compress(char *book, struct s_dict *dict)
{
	int header_size = 0;
	char *header = create_header(dict, &header_size);
	char *compressed_book = calloc(1, strlen(book) + header_size + 1);
	strncpy(compressed_book, header, header_size);
	free(header);
	replace_words(book, compressed_book + header_size, dict);
	printf("%s\n", book);
	return compressed_book;
}