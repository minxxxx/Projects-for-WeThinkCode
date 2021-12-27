/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxSW.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 01:20:15 by smonroe           #+#    #+#             */
/*   Updated: 2019/01/18 21:38:38 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int max2(int a, int b) { return a > b ? a : b; }

struct s_deque *dequeInit(void) { return calloc(1, sizeof(struct s_deque)); }

void pushFront(struct s_deque *deque, int value)
{
	if (!deque) return ;
	struct s_dequeNode *new = calloc(1, sizeof *new);
	new->value = value;
	new->prev = deque->first;
	if (deque->first)
		deque->first->next = new;
	deque->first = new;
	if (!deque->last)
	{
		deque->last = new;
		new->prev = 0;
	}
}

void pushBack(struct s_deque *deque, int value)
{
	if (!deque) return ;
	struct s_dequeNode *new = calloc(1, sizeof *new);
	new->value = value;
	new->next = deque->last;
	if (deque->last)
		deque->last->prev = new;
	deque->last = new;
	if (!deque->first)
	{
		deque->first = new;
		new->next = 0;
	}
}

int popFront(struct s_deque *deque)
{
	if (!deque || !deque->first) return 0;
	struct s_dequeNode *fr = deque->first;
	int ret = fr->value;
	if (deque->first == deque->last)
		deque->last = deque->first = 0;
	else
		deque->first = deque->first->prev;
	free(fr);
	return ret;
}

int popBack(struct s_deque *deque)
{
	if (!deque || !deque->last) return 0;
	struct s_dequeNode *fr = deque->last;
	int ret = fr->value;
	if (deque->last == deque->first)
		deque->first = deque->last = 0;
	else
		deque->last = deque->last->next;
	free(fr);
	return ret;
}

int maxWin(struct s_deque *dq, int k)
{
	if (!dq || !dq->first) return INT_MIN;
	int max = INT_MIN;
	struct s_dequeNode *ptr = dq->first;
	for (int i = 0; ptr && i < k; i++)
	{
		max = max2(max, ptr->value);
		ptr = ptr->prev;
	}
	return max;
}
// MAX SLIDING WINDOW

struct s_max *maxSlidingWindow(int *arr, int n, int k)
{
	if (k > n) return 0;
	struct s_max *ret = calloc(1, sizeof *ret);
	if (!ret)
		return 0;
	ret->max = calloc(1 + n - k, sizeof(int));
	struct s_deque *dq = dequeInit();
	for (int i = 0; i < n; i++)
		pushBack(dq, arr[i]);
	for (ret->length = 0; ret->length < 1 + n - k; ret->length++)
	{
		ret->max[ret->length] = maxWin(dq, k);
		popFront(dq);
	}
	return ret;
}
