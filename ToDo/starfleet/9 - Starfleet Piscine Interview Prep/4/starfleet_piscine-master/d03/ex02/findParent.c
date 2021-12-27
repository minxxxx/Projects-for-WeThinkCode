#include <stdlib.h> //malloc, free, exit...
#include <string.h> //memcpy, strlen, ...

#include "header.h"


struct s_deque *deque(void)
{
	struct s_deque *deque;

	deque = (struct s_deque*)malloc(sizeof(struct s_deque));
	deque->first = NULL;
	deque->last = NULL;
	return deque;
}

void push_front(struct s_deque *deque, void *content)
{
	struct s_item *item = malloc(sizeof(struct s_item));
	item->content = content;
	item->prev = NULL;
	item->next = deque->first;
	if (deque->first)
		deque->first->prev = item;
	deque->first = item;
	if(!deque->last)
		deque->last = item;
}

void push_back(struct s_deque *deque, void *content)
{
	struct s_item *item = malloc(sizeof(struct s_item));
	item->content = content;
	item->prev = deque->last;
	item->next = NULL;
	if (deque->last)
		deque->last->next = item;
	deque->last = item;
	if(!deque->first)
		deque->first = item;
}

void *pop_front(struct s_deque *deque)
{
	struct s_item *item = deque->first;
	void *content;
	if (!item)
		return NULL;
	deque->first = item->next;
	if(!deque->first)
		deque->last = NULL;
	else
		deque->first->prev = NULL;
	content = item->content;
	free(item);
	return content;
}

void *pop_back(struct s_deque *deque)
{
	struct s_item *item = deque->last;
	void *content;
	if (!item)
		return NULL;
	deque->last = item->prev;
	if(!deque->last)
		deque->first = NULL;
	else
		deque->last->next = NULL;
	content = item->content;
	free(item);
	return content;
}

void *peek_front(struct s_deque *deque)
{
	struct s_item *item = deque->first;
	if(!item)
		return NULL;
	return item->content;
}

void *peek_back(struct s_deque *deque)
{
	struct s_item *item = deque->last;
	if(!item)
		return NULL;
	return item->content;
}

int isEmpty(struct s_deque *deque)
{
	return(!deque->first || !deque->last);
}

void clear(struct s_deque *deque)
{
	while(!isEmpty(deque))
		pop_front(deque);
	free(deque);
}


int findPath(struct s_node *root, struct s_deque *path, char *name)
{
	if (!root)
		return 0;
	push_back(path, root);
	if(!strcmp(root->name, name))
		return 1;
	struct s_node **child = root->children;
	while(*child)
	{
		if (findPath(*child, path, name))
			return 1;
		child++;
	}
	pop_back(path);
	return 0;
}

struct s_node *findParent(struct s_node *root, char *firstSpecies, char *secondSpecies)
{
	struct s_deque *path1, *path2;
	struct s_node *last = root;
	path1 = deque();
	path2 = deque();
	if (!findPath(root, path1, firstSpecies) || !findPath(root, path2, secondSpecies))
		return NULL;
	while(!isEmpty(path1) && !isEmpty(path2))
	{
		if(peek_front(path1)!=peek_front(path2))
			return last;
		pop_front(path1);
		last = pop_front(path2);
	}
	clear(path1);
	clear(path2);
	return last;
}