/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortStone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 23:15:02 by amontano          #+#    #+#             */
/*   Updated: 2019/01/09 23:15:03 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	count_stones(t_stone** stone)
{
	int i = 0;

	t_stone *cur = *stone;
	while (cur)
	{
		i++;
		cur = cur->next;
	}
	return (i);
}

static	void comb_sort_tab(t_stone **tab, int tablen)
{
	int i, k, gap, swap;

int passes = 0;
	swap = 0;
	gap = tablen;
	while (gap > 1 || swap)
	{
passes++;
		i = -1;
		gap = gap * 10 / 13;
		gap = (gap == 9) || (gap == 10) ? 11 : gap;
		gap = (gap < 1) ? 1 : gap;
		swap = 0;
		if (tablen < 11)
			gap = 1;
		while(++i < tablen - 1)
		{
			k = i + gap;
			//comparitor
			if (tab[i] && tab[k]	\
				&& tab[i]->size > tab[k]->size)
			{
				//swap function
				t_stone *tmp;

				tmp = tab[i];
				tab[i] = tab[k];
				tab[k] = tmp;
				swap = 1;
 			}
		}
	}
	printf("Number of comb-thrus : %d\n", passes);
}

static void lst_to_tab(t_stone **lst, t_stone **tab)
{
	int i = 0;
	t_stone *cur;

	cur = *lst;

	while (cur)
	{
		tab[i] = cur;
		i++;
		cur = cur->next;
	}
}

static void tab_to_lst(t_stone **tab, t_stone **stone, int len)
{
	t_stone *cur;
	int i = 0;

	*stone = tab[i];
	cur = *stone;
	while (i + 1 < len)
	{
		cur->next = tab[i + 1];
		cur = cur->next;
		i++;
	}
	cur->next = NULL;
}

void	sortStones(struct s_stone **stone)
{
	int			c;
	t_stone 	**tab;

	c = count_stones(stone);
	tab = (t_stone **)malloc(sizeof(t_stone *) * c);
	lst_to_tab(stone, tab);
	comb_sort_tab(tab, c);
	tab_to_lst(tab, stone, c);
	free(tab);
}

/*
**	My data table is structured like this
**		int *tab;
**		tab[index] = pointer;
*/

