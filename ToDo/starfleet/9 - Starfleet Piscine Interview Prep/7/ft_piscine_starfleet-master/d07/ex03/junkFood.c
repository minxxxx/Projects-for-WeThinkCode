#include "header.h"

struct s_node *getStartingPlace(char *name, struct s_node **places)
{
	for (int i = 0; places[i]; i++)
		if (strcmp(name, places[i]->name) == 0)
			return (places[i]);
	return (NULL);
}

struct s_sellers *closestSellers(struct s_graph *graph, char *youAreHere)
{
	struct s_sellers	*sellers;
	struct s_node		*start;
	struct s_node		*current;
	struct s_queue		*BFS;
	struct s_queue		*found;
	int					distance;
	int					found_cnt;

	start = getStartingPlace(youAreHere, graph->places);
	BFS = queueInit();
	found = queueInit();
	distance = 0;
	found_cnt = 0;

	enqueue(BFS, start);
	if (start == NULL)
		return (NULL);
	start->visited = 1;
	enqueue(BFS, NULL);

	while (found_cnt == 0 && BFS->first->place != NULL)
	{
		while ((current = dequeue(BFS)) != NULL)
		{
			current->visited = 1;
			if (current->hasCerealBar)
			{
				enqueue(found, current);
				found_cnt++;
			}
			else if (found_cnt == 0)
				for (int j = 0; current->connectedPlaces[j]; j++)
					if (current->connectedPlaces[j]->visited == 0)
					{
						current->connectedPlaces[j]->visited = 1;
						enqueue(BFS, current->connectedPlaces[j]);
					}
		}
		if (found_cnt == 0)
		{
			distance++;
			enqueue(BFS, NULL);
		}
	}

	if (found_cnt == 0)
		return (NULL);
	else
	{
		sellers = (struct s_sellers*)malloc(sizeof(struct s_sellers));
		sellers->distance = distance;
		sellers->placeNames = (char**)calloc(found_cnt + 1, sizeof(char*));
		for (int k = 0; k < found_cnt; k++)
			sellers->placeNames[k] = dequeue(found)->name;
	}
	return (sellers);
}
