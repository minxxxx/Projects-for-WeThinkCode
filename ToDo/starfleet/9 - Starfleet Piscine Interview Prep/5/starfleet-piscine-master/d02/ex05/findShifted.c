/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findShifted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 02:18:23 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/26 06:08:33 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <unistd.h>
#include <stdio.h>

int	getPivot(int *arr, int start, int end)
{
	if (end < start)
		return (-1);
	else if (end == start)
		return (end);
	else
	{
		int	middle;
		
		middle = (start + end) / 2;
		if (middle < end && arr[middle] > arr[middle + 1])
			return (middle);
		else if (middle > start && arr[middle] < arr[middle - 1])
			return (middle - 1);
		else if (arr[middle] < arr[start])
			return (getPivot(arr, start, middle - 1));
		else
			return (getPivot(arr, middle + 1, end));
	}
}

int	binarySearch(int *arr, int start, int end, int value)
{
	int middle;

	if (end < start)
		return (-1);
	middle = (end + start) / 2;
	if (value == arr[middle])
		return (middle);
	else if (value < arr[middle])
		return (binarySearch(arr, start, middle - 1, value));
	return (binarySearch(arr, middle + 1, end, value));
}


int	searchShifted(int *rocks, int length, int value)
{
	int pivot;
	
	pivot = getPivot(rocks, 0, length - 1);
	printf("pivot: %d\n", pivot);
	if (pivot == -1)
		return binarySearch(rocks, 0, length - 1, value);
	else if (value == rocks[pivot])
		return (pivot);
	else if (value < rocks[0])
		return (binarySearch(rocks, pivot + 1, length - 1, value));
	else
		return (binarySearch(rocks, 0, pivot - 1, value));
}