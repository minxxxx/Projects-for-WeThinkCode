#include "header.h"

int openTable(struct s_people *person, int from, int *tables, int nbTables)
{
	for (int i = from; i < nbTables; i++)
		if (tables[i] - person->time >= 0)
			return (i);
	return (-1);
}

int recurse(struct s_people **people, int *tables, int nbTable)
{
	int table = 0;

	while ((table = openTable(*people, table, tables, nbTable)) >= 0) {
		tables[table] -= (*people)->time;
		if (!(people[1]) || recurse(people + 1, tables, nbTable) == 1)
			return (1);
		else {
			tables[table] += (*people)->time;
			table++;
		}
	}
	return (0);
}
			
int isPossible(struct s_people **people, int nbTable, int totalTime)
{
	int *tables = (int*)malloc(sizeof(int) * nbTable);

	for (int i = 0; i < nbTable; i++)
		tables[i] = totalTime;
	return (recurse(people, tables, nbTable));
}
