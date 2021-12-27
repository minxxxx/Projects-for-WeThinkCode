/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 01:13:35 by amontano          #+#    #+#             */
/*   Updated: 2019/01/08 01:13:38 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

size_t			hash(char *input, size_t len)
{
	size_t  hash	= 0x1337;
	size_t  i		= 0;
	while (input[i] != '\0' && i < len)
	{
		hash += (hash << 5) - input[i];
		hash -= (hash >> 2) + input[i];
		i++;
	}
	return (hash);
}

struct s_dict *dictInit(int capacity)
{
	t_dict	*dict;

	dict = (t_dict *)malloc(sizeof(t_dict));
	dict->capacity = capacity;
	if (!(dict->items = (t_item **)malloc(sizeof(t_item *) * capacity)))
		return (NULL);
	for (int i = 0; i < capacity; i++)
		dict->items[i] = NULL;
	return (dict);
}

int			dictInsert(struct s_dict *dict, char *key, int value)
{
	size_t	index;
	t_item	*cursor;

	index = hash(key, strlen(key)) % dict->capacity;
	if (!(dict->items[index]))
	{
		if (!(dict->items[index] = (t_item *)malloc(sizeof(t_item))))
			return (0);
		cursor = dict->items[index];
	}
	else
	{	
		cursor = dict->items[index];
		while (cursor->next)
		{
			if (!strcmp(cursor->key, key))
			{
				cursor->value = value;
				return (1);
			}
			cursor = cursor->next;
		}
		if (!(cursor->next = (t_item *)malloc(sizeof(t_item))))
			return (0);
		cursor = cursor->next;
	}
	cursor->key = strdup(key);
	cursor->value = value;
	cursor->next = NULL;
	return (1);
}

int	dictSearch(struct s_dict *dict, char *key)
{
	size_t	index;
	t_item	*cursor;

	index = hash(key, strlen(key)) % dict->capacity;
	if (!(cursor = dict->items[index]))
		return (-1);
	while (cursor)
	{
		if (!strcmp(cursor->key, key))
			return (cursor->value);
		cursor = cursor->next;
	}
	return (-1);
}
static char		*strjoin(char *dst, char *src)
{
	char *ret = malloc(sizeof(char) * strlen(dst) + strlen(src) + 1);
	strcat(ret, dst);
	strcat(ret, src);
	ret[strlen(ret)] = '\0';
 	free(dst);
	return (ret);
}

static char *make_header(struct s_dict *dict)
{
	char			*hdr;
	int 			i = 0;

	hdr = malloc(sizeof(char) * 2 + 1);
	hdr[0] = '<';
	while (i < dict->capacity)
	{
		if (dict->items[i] != NULL)
		{
			t_item *cursor = dict->items[i];
			while (cursor)
			{
				hdr = strjoin(hdr, cursor->key);
				hdr = strjoin(hdr, ",");
				cursor = cursor->next;
			}
		}
		i++;
	}
	hdr[strlen(hdr) - 1] = '>';
	return (hdr);
}

static size_t	get_index(char *book, char *find, size_t len)
{
    size_t      hsh     = hash(find, len);
	size_t		index	= 0;
    
    while (book[index])
    {
        if (hash(&book[index], len) == hsh)
			return (index);
		index++;
    }
    return (SIZE_T_MAX + 1);
}

char *compress(char *book, struct s_dict *dict)
{
	t_item			*cursor;
	char			*compress;
	char			*buf;
	size_t			index = 0;
	size_t			loc = 0;

	compress = make_header(dict);
	for (unsigned char i = 0; i < dict->capacity; i++)
	{
		cursor = dict->items[i];
		while (cursor) //for each element in the list
		{
			while ((index = get_index(&book[loc], cursor->key, strlen(cursor->key)) != SIZE_T_MAX + 1))
			{
				buf = strndup(&book[loc], index - loc);
				compress = strjoin(compress, buf);
				sprintf(buf, "@ %c", i);
				compress = strjoin(compress, buf);
				loc = index - 1;
			}
			cursor = cursor->next;
		}
	}
	return (compress);
}