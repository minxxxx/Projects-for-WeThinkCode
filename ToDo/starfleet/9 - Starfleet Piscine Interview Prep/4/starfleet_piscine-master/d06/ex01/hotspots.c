#include "header.h"

int selectHotspots(struct s_hotspot **hotspots)
{
	for (int i = 1 ; hotspots[i]; i++)
	{
		if((hotspots[i]->pos - hotspots[i]->radius) < (hotspots[i - 1]->pos + hotspots[i - 1]->radius)
		{
			if(hotspots[i]->radius > hotspots[i - 1])
		}
	}
}
