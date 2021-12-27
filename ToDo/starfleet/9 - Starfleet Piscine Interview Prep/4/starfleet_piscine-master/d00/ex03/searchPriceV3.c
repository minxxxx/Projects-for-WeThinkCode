#include <stdlib.h> //malloc, free, exit...
#include <string.h> //memcpy, strlen, ...
#include <stdio.h> //printf, scanf, ...
#include "header.h"

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
	printf("Allocated dictionary array...\n");
	return dict;
}

int	dictInsert(struct s_dict *dict, char *key, struct s_art *value)
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

struct s_art *dictSearch(struct s_dict *dict, char *key)
{
	int index = hash(key) % dict->capacity;
	struct s_item *elem = dict->items[index];
	while(elem)
	{
		if (!strcmp(elem->key, key))
			return elem->value;
		elem = elem->next;
	}
	return NULL;
}


int searchPrice(struct s_dict *dict, char *name)
{
	struct s_art *item = dictSearch(dict, name);
	if (item)
		return item->price;
	return -1;
}