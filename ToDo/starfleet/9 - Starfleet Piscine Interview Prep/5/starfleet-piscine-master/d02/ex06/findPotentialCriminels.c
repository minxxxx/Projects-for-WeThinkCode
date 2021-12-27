/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findPotentialCriminels.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 06:12:34 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/26 09:07:59 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 1867111
#define DIGIT (criminals[i]->description/exp)%10

int			getDescription(struct s_info *info)
{
	int description = 0;

	description += (info->gender  * 1000000) +
					(info->height  * 100000) +
					(info->hairColor  * 10000) +
					(info->eyeColor  * 1000) +
					(info->glasses  * 100) +
					(info->tattoo  * 10) +
					(info->piercing);
	return (description);
}

static void	countSort(struct s_criminal **criminals, int len, int exp)
{
	int	count[10], i;
	struct s_criminal *output[len];

    bzero(&count, sizeof(count));
    for (i = 0; i < len; i++)
        count[DIGIT]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = len - 1; i >= 0; i--)
	{
		output[count[DIGIT] - 1] = criminals[i];
		count[DIGIT]--;
	}
	for (i = 0; i < len; i++)
		criminals[i] = output[i];
}

static int		arrLen(struct s_criminal **criminals)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	while (criminals[++i])
		len++;
	return (len);
}

void	sortCriminals(struct s_criminal **criminals)
{
	int	len;

	len = arrLen(criminals);
	for (int exp = 1; (MAX / exp) > 0; exp *= 10)
		countSort(criminals, len, exp);
}

static int	getLeftPos(struct s_criminal **criminals, int start, int end, int key)
{
	int	middle;

	while (end - start > 1)
	{
		middle = start + (end - start) / 2;
		if (criminals[middle]->description >= key)
			end = middle;
		else
			start = middle;
	}
	return (end);
}

static int	getRightPos(struct s_criminal **criminals, int start, int end, int key)
{
	int	middle;

	while (end - start > 1)
	{
		middle = start + (end - start) / 2;
		if (criminals[middle]->description <= key)
			end = middle;
		else
			start = middle;
	}
	return (start);
}

struct s_criminal **newArr(struct s_criminal **criminals, int left, int right)
{
	struct s_criminal	**new_arr;
	int					i;

	i = 0;
	new_arr = calloc(right - left + 1, sizeof(struct s_criminal *));
	while(left <= right)
		new_arr[i++] = criminals[left++];
	new_arr[left++] = NULL;
	return (new_arr);
}

struct s_criminal **findPotentialCriminals(struct s_criminal **criminals, struct s_info *info)
{
	int description;
	int	left;
	int	right;
	int	len;

	len = arrLen(criminals);
	description = getDescription(info);
	left = getLeftPos(criminals, 0, len -1, description);
	right = getRightPos(criminals, 0, len -1, description);
	return (newArr(criminals, left, right));
}