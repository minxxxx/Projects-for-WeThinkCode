/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 18:24:02 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/24 20:29:04 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define CAPACITY 135587


size_t hash(char *input)
{
	size_t	hash = 5381;
	int		c;
	while ((c = *input++))
		hash = ((hash << 5) + hash) +  c;
	return (hash % CAPACITY);
}

struct s_dict	*dictInit(int capacity)
{
	struct s_dict *table;

	if (!(table = malloc(sizeof(struct s_dict))))
		return (NULL);
	if (!(table->items = calloc(capacity, sizeof(struct s_item *))))
		return (NULL);
	table->capacity = capacity;
	return (table);
}

int	dictInsert(struct s_dict *dict, char *key, struct s_art *value)
{
	size_t			tmp_hash;
	struct s_item	*new_item;

	tmp_hash = hash(key);
	if (!(new_item = malloc(sizeof(struct s_item))))
		return (0);
	new_item->key = key;
	new_item->value = value;
	new_item->next = dict->items[tmp_hash];
	dict->items[tmp_hash] = new_item;
	return (1);
}

struct	s_art *dictSearch(struct s_dict *dict, char *key)
{
	struct s_item	*tmp_item;

	tmp_item = dict->items[hash(key)];
	while (tmp_item && strcmp(tmp_item->key, key) != 0)
		tmp_item = tmp_item->next;
	return (tmp_item->value);
}

int searchPrice(struct s_dict *dict, char *name)
{
	return ((dictSearch(dict, name) == NULL) ? -1 : (dictSearch(dict, name)->price));
}