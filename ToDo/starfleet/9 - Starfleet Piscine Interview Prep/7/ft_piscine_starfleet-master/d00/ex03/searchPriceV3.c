#include "header.h"

size_t hash(char *input)
{
	int				multiplier = 37;
	unsigned char	*u_input;
	size_t			i;

	u_input = (unsigned char*)input;
	i = 0;
	while (*u_input)
	{
		i = i * multiplier + *u_input;
		u_input++;
	}
	return (i);
}

struct s_dict	*dictInit(int capacity)
{
	struct s_dict	*d;
	size_t			size;

	d = (struct s_dict*)malloc(sizeof(struct s_dict));
	if (!d)
		return NULL;
	d->capacity = capacity;
	size = sizeof(struct s_item*) * capacity;
	d->items = (struct s_item**)malloc(size);
	if (!d->items)
		return NULL;
	bzero(d->items, size);
	return (d);
}

static void		listAdd(struct s_item **head, struct s_item *new)
{
	struct s_item *list_iter;

	if (*head == NULL)
		*head = new;
	else
	{
		list_iter = *head;
		while (list_iter->next)
			list_iter = list_iter->next;
		list_iter->next = new;
	}
}

int				dictInsert(struct s_dict *d, char *key, struct s_art *value)
{
	size_t 			i;
	struct s_item	*item;

	item = (struct s_item*)malloc(sizeof(struct s_item));
	if (!item)
		return (0);
	item->key = key;
	item->value = value;
	item->next = NULL;
	i = hash(key) % d->capacity;
	listAdd(&(d->items[i]), item);
	return (1);
}

struct s_art	*dictSearch(struct s_dict *d, char *key)
{
	size_t			i;
	struct s_item	*list_iter;

	i = hash(key) % d->capacity;
	list_iter = d->items[i];
	while (list_iter)
	{
		if (strcmp(list_iter->value->name, key) == 0)
			return (list_iter->value);
		list_iter = list_iter->next;
	}
	return (NULL);
}

int 			searchPrice(struct s_dict *d, char *name)
{
	struct s_art *art;

	art = dictSearch(d, name);
	if (art == NULL)
		return (-1);
	return (art->price);
}
