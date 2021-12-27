#include "header.h"
#include <string.h>
#include <stdio.h>

size_t hash(char *input)
{
	size_t hash = 5381;
	int i = 0;
	int c;

	while (input[i])
	{
		c = input[i];
		hash = ((hash << 5) + hash) + c;
		i++;
	}
	return hash;
}

struct s_dict *dictInit(int capacity)
{
	struct s_dict *ret;
	int i = 0;

	ret = (struct s_dict*)malloc(sizeof(struct s_item*));
	ret->items = (struct s_item**)malloc(sizeof(struct s_item*) * capacity);
	ret->capacity = capacity;
	while (i < capacity)
	{
		ret->items[i] = NULL;
		i++;
	}
	return (ret);
}

int	dictInsert(struct s_dict *dict, char *key, struct s_art *value)
{
	struct s_item *curr;

	if (!dict->items[hash(key) % dict->capacity])
	{
		dict->items[hash(key) % dict->capacity] = (struct s_item*)malloc(sizeof(struct s_item));
		curr = dict->items[hash(key) % dict->capacity];
		if (!curr)
			return 0;
		curr->value = value;
		curr->key = strdup(key);
		curr->next = NULL;
		return 1;
	}
	curr = dict->items[hash(key) % dict->capacity];
	while (curr)
	{
		if (strcmp(curr->key, key) == 0)
		{
			curr->value = value;
			return 1;
		}
		if (curr->next)
			curr = curr->next;
		else
			break;
	}
	curr->next = (struct s_item*)malloc(sizeof(struct s_item));
	curr = curr->next;
	if (!curr)
		return 0;
	curr->value = value;
	curr->key = strdup(key);
	curr->next = NULL;
	return 1;
}

struct s_art *dictSearch(struct s_dict *dict, char *key)
{
	struct s_item *curr;

	curr = dict->items[hash(key) % dict->capacity];
	while (curr)
	{
		if (strcmp(curr->key, key) == 0)
			return curr->value;
		curr = curr->next;
	}
	return NULL;
}

int searchPrice(struct s_dict *dict, char *name)
{
	struct s_item *curr;

	curr = dict->items[hash(name) % dict->capacity];
	while (curr)
	{
		if (strcmp(curr->key, name) == 0)
			return curr->value->price;
		curr = curr->next;
	}
	return -1;
}
