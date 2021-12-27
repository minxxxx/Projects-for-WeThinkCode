#include "header.h"
#include <stdio.h>

int selectHotspots(struct s_hotspot **hotspots)
{
	int i;
	int over;
	int count = 0;
	i = 0;

	while (hotspots[i])
	{
		int j = 0;
		int range = hotspots[i]->pos + hotspots[i]->radius;
		over = 0;
		while (hotspots[j])
		{
			int compare = hotspots[j]->pos - hotspots[j]->radius;
			if (range <= compare)
			{
				over = 1;
				break;
			}
			// printf("pos=%d\tradius=%d\n", hotspots[i]->pos, hotspots[i]->radius);
			j++;
		}
		if (!over)
			count++;
		i++;
	}
	return count;
}
