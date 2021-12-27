#include <math.h>
#include <stdio.h>
#include <stdlib.h> //malloc, free, exit...
#include "header.h"


int get_size(struct s_node *root)
{
	if (!root)
		return (0);
	return (get_size(root->left) + get_size(root->right) + 1);
}

int	get_height(struct s_node *root)
{
	if (!root)
		return 0;
	return(fmax(get_height(root->left), get_height(root->right)) + 1);
}


int isEmpty(struct s_queue *queue)
{
	return(queue->last == NULL || queue->first == NULL);
}

struct s_queue *queueInit(void)
{
	struct s_queue *queue = malloc(sizeof(struct s_queue));
	if(!queue)
		return NULL;
	queue->first = NULL;
	queue->last = NULL;
	return queue;
}

void *dequeue(struct s_queue *queue)
{
	struct s_item *node = queue->first;
	void *content;
	if(!node)
		return NULL;
	queue->first = node->next;
	if(!(queue->first))
		queue->last = NULL;
	content = node->content;
	free(node);
	return content;
}

void enqueue(struct s_queue *queue, void *content)
{
	struct s_item *node = malloc(sizeof(struct s_item));
	node->content = content;
	node->next = NULL;
	if(!isEmpty(queue))
		queue->last->next = node;
	else
		queue->first = node;
	queue->last = node;
}


struct s_node **convert_to_array(struct s_node *root, int size)
{
	int height;
	struct s_node **array;
	struct s_node **next;
	struct s_queue *queue;

	height = get_height(root);
	array = (struct s_node**)malloc(sizeof(struct s_node*) * size);
	next = array;
	queue = queueInit();
	enqueue(queue, root);
	while(!isEmpty(queue))
	{
		root = dequeue(queue);
		*(next++) = root;
		if(root->left)
			enqueue(queue, root->left);
		if(root->right)
			enqueue(queue, root->right);
	}
	free(queue);
	return (array);
}

void pull_max_up(struct s_node **array, int i, int n)
{
	if (i == 0)
		return;
	int parent = (i - 1) / 2;
	struct s_node *temp;
	if (array[i]->value > array[parent]->value)
	{
		temp = array[i];
		array[i] = array[parent];
		array[parent] = temp;
		pull_max_up(array, parent, n);
	}
}

void convert_to_heap(struct s_node **array, int size)
{
	for(int i = 0; i < size; i++)
	{
		if(i * 2 + 1 < size)
			array[i]->left = array[i * 2 + 1];
		else
			array[i]->left = NULL;
		if(i * 2 + 2 < size)
			array[i]->right = array[i * 2 + 2];
		else
			array[i]->right = NULL;
	}
}

void insertMonkey(struct s_node **root, struct s_node *monkey)
{
	int size = get_size(*root);
	struct s_node **array = convert_to_array(*root, size + 1);
	array[size] = monkey;
	pull_max_up(array, size, size + 1);
	convert_to_heap(array, size + 1);
	*root = array[0];
	free(array);
}