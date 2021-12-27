/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   junkFood.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 07:32:06 by smonroe           #+#    #+#             */
/*   Updated: 2019/01/18 23:34:08 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h> //REMOVE
void	setZero(struct s_node **p)
{
	if (!p)
		return ;
	for (int i = 0; p[i]; i++)
	{
		if (p[i]->visited)
		{
			p[i]->visited = 0;
			setZero(p[i]->connectedPlaces);
		}
	}
}

void	getQ(struct s_node **p, struct s_queue *q, int min, int *count)
{
	if (!p)
		return ;
	for (int i = 0; p[i]; i++)
	{
		if (p[i]->visited)
		{
			if (p[i]->visited == min && p[i]->hasCerealBar)
			{
				*count += 1;
				enqueue(q, p[i]);
			}
			p[i]->visited = 0;
			getQ(p[i]->connectedPlaces, q, min, count);
		}
	}
}

void	getDist(struct s_node **p, int d, int *min)
{
	if (!p)
		return ;
	for (int i = 0; p[i]; i++)
	{
		if (!p[i]->visited)
		{
			p[i]->visited = d;
			getDist(p[i]->connectedPlaces, d + 1, min);
		}
		else if (p[i]->visited > d)
			p[i]->visited = d;
		if (p[i]->hasCerealBar && *min > p[i]->visited)
			*min = p[i]->visited;
	}
}

void	getPos(struct s_node **p, struct s_node **me, char *name)
{
	if (!p || !name)
		return ;
	for (int i = 0; p[i]; i++)
	{
		if (!p[i]->visited)
		{
			if (!strcmp(p[i]->name, name))
				*me = p[i];
			p[i]->visited = 1;
			getPos(p[i]->connectedPlaces, me, name);
		}
	}
}

struct s_sellers *closestSellers(struct s_graph *graph, char *youAreHere)
{
	struct s_node *me = 0;
	getPos(graph->places, &me, youAreHere);
	setZero(graph->places);

	if (!me) {
		printf("{%s} could not be found in this graph.\n", youAreHere);
		return 0; }
	if (me->hasCerealBar) {
		printf("{%s} already has a cereal Bar!\n", youAreHere);
		return 0;
		}
	struct s_queue *q = queueInit();
	int min = INT_MAX;
	int count = 0;
	getDist(me->connectedPlaces, 1, &min);
	getQ(me->connectedPlaces, q, min, &count);

	struct s_sellers *ret = calloc(1, sizeof(*ret));
	if (!ret) return 0;

	ret->distance = min;
	ret->placeNames = calloc(count + 1, sizeof(*(ret->placeNames)));
	if (!ret->placeNames) return 0;

	struct s_node *tmp = 0;
	int i = 0;
	while ((tmp = dequeue(q)))
		ret->placeNames[i++] = strdup(tmp->name);
	ret->placeNames[i] = 0;
	return ret;
}
/*
void BFS(struct s_node *p, struct s_queue *queue)
{ 
	setZero(p->connectedPlaces);
    // Create a queue for BFS 
 
    // Mark the current node as visited and enqueue it 
    p->visited = 1;
    enqueue(queue, p);
  
    // 'i' will be used to get all adjacent 
    // vertices of a vertex 
    int i = 0; 
  
    while(queue->first) 
    { 
        // Dequeue a vertex from queue and print it 
        struct s_node *t = dequeue(queue); 
        // Get all adjacent vertices of the dequeued 
        // vertex s. If a adjacent has not been visited,  
        // then mark it visited and enqueue it 
        for (i = 0; t->connectedPlaces[i]; ++i) 
        { 
            if (!t->connectedPlaces[i]->visited) 
            { 
                t->connectedPlaces[i]->visited = 1; 
                enqueue(queue, t->connectedPlaces[i]); 
            } 
        } 
    } 
} 

void	setZero(struct s_node **p)
{
	if (!p)
		return ;
	for (int i = 0; p[i]; i++)
	{
		if (p[i]->visited)
		{
			p[i]->visited = 0;
			setZero(p[i]->connectedPlaces);
		}
	}
}

void	getQ(struct s_node **p, struct s_queue *q, int min, int *count)
{
	if (!p)
		return ;
	for (int i = 0; p[i]; i++)
	{
		if (p[i]->visited)
		{
			if (p[i]->visited == min && p[i]->hasCerealBar)
			{
				*count += 1;
				enqueue(q, p[i]);
			}
			p[i]->visited = 0;
			getQ(p[i]->connectedPlaces, q, min, count);
		}
	}
}

void	getDist(struct s_node **p, int d, int *min)
{
	if (!p)
		return ;
	for (int i = 0; p[i]; i++)
	{
		if (!p[i]->visited)
		{
			p[i]->visited = d;
			getDist(p[i]->connectedPlaces, d + 1, min);
		}
		else if (p[i]->visited > d)
			p[i]->visited = d;
		if (p[i]->hasCerealBar && *min > p[i]->visited)
			*min = p[i]->visited;
	}
}

void	getPos(struct s_node **p, struct s_node **me, char *name)
{
	if (!p || !name)
		return ;
	for (int i = 0; p[i]; i++)
	{
		if (!p[i]->visited)
		{
			if (!strcmp(p[i]->name, name))
				*me = p[i];
			p[i]->visited = 1;
			getPos(p[i]->connectedPlaces, me, name);
		}
	}
}

struct s_sellers *closestSellers(struct s_graph *graph, char *youAreHere)
{
	struct s_node *me = 0;
	getPos(graph->places, &me, youAreHere);
	setZero(graph->places);

	if (!me) {
		printf("{%s} could not be found in this graph.\n", youAreHere);
		return 0; }
	if (me->hasCerealBar) {
		printf("{%s} already has a cereal Bar!\n", youAreHere);
		return 0;
		}

	struct s_queue *q = queueInit();
	int min = INT_MAX;
	int count = 0;
	getDist(me->connectedPlaces, 1, &min);
	getQ(me->connectedPlaces, q, min, &count);

	struct s_sellers *ret = calloc(1, sizeof(*ret));
	if (!ret) return 0;

	ret->distance = min;
	ret->placeNames = calloc(count + 1, sizeof(*(ret->placeNames)));
	if (!ret->placeNames) return 0;

	struct s_node *tmp = 0;
	int i = 0;
	while ((tmp = dequeue(q)))
		ret->placeNames[i++] = strdup(tmp->name);
	ret->placeNames[i] = 0;
	return ret;
}
*/
