/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 01:43:38 by amontano          #+#    #+#             */
/*   Updated: 2019/01/07 01:43:39 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"

size_t			hash(char *input)
{
	size_t  hash	= 0x1337;
	size_t  i		= 0;
	while (input[i] != '\0')
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

int			dictInsert(struct s_dict *dict, char *key, struct s_art *value)
{
	size_t	index;
	t_item	*cursor;

	index = hash(key) % dict->capacity;
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

struct s_art	*dictSearch(struct s_dict *dict, char *key)
{
	size_t	index;
	t_item	*cursor;

	index = hash(key) % dict->capacity;
	if (!(cursor = dict->items[index]))
		return (NULL);
	while (cursor)
	{
		if (!strcmp(cursor->key, key))
			return (cursor->value);
		cursor = cursor->next;
	}
	return (NULL);
}

int				searchPrice(struct s_dict *dict, char *name)
{
	t_art	*find;

	return ( (!(find = dictSearch(dict, name))) ? -1 : find->price);
}