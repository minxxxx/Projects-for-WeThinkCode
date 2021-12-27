#include <stdio.h> //printf, scanf, ...
#include <stdlib.h> //malloc, free, exit...
#include "header.h"

int LENGTH = 0;

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

struct s_criminal *dequeue(struct s_queue *queue)
{
	struct s_node *node = queue->first;
	struct s_criminal *criminal;
	if(!node)
		return NULL;
	queue->first = node->next;
	if(!(queue->first))
		queue->last = NULL;
	criminal = node->criminal;
	free(node);
	return criminal;
}

void enqueue(struct s_queue *queue, struct s_criminal *criminal)
{
	struct s_node *node = malloc(sizeof(struct s_node));
	node->criminal = criminal;
	node->next = NULL;
	if(!isEmpty(queue))
		queue->last->next = node;
	else
		queue->first = node;
	queue->last = node;
}

int getDescription(struct s_info *info)
{
	int description =
	  info->gender * 1000000
	+ info->height * 100000
	+ info->hairColor * 10000
	+ info->eyeColor * 1000
	+ info->glasses * 100
	+ info->tattoo * 10
	+ info->piercing;
	return description;
}

void bucketSort(struct s_criminal **criminals, int n, int exp)
{
	int i;
	struct s_queue *count[10];
	for(int i = 0; i < 10; i++)
		count[i] = queueInit();
	i = 0;
	while (i < n)
	{
	  enqueue(count[(criminals[i]->description / exp) % 10], criminals[i]);
	  i++;
	}
	i = 0;
	while (i < 10)
	{
		while(!isEmpty(count[i]))
			*(criminals++) = dequeue(count[i]);
		i++;
	}
	for(int i = 0; i < 10; i++)
		free(count[i]);
}

void sortCriminals(struct s_criminal **criminals)
{
	LENGTH = 0;
	while(criminals[LENGTH])
		LENGTH++;
	for (int exp = 1; exp < 10000000; exp *= 10)
       bucketSort(criminals, LENGTH, exp);
}

int bSearch(struct s_criminal **criminals, int left, int right, int description)
{
	if (right > left)
	{
		int mid = (left + right) / 2;
		if(criminals[mid]->description == description)
			return mid;
		else if(description < criminals[mid]->description)
			return bSearch(criminals, left, mid - 1, description);
		else
			return bSearch(criminals, mid + 1, right, description);
	}
	return -1;
}

struct s_criminal **findPotentialCriminals(struct s_criminal **criminals, struct s_info *info)
{
	int description = getDescription(info);
	int index = bSearch(criminals, 0, LENGTH - 1, description);
	int left = index;
	int right = index;
	while(criminals[left - 1]->description == description)
		left--;
	while(criminals[right + 1]->description == description)
		right++;
	criminals[right + 1] = NULL;
	return &criminals[left];
}