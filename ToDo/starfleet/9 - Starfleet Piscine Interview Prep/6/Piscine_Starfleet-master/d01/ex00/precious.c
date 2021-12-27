/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precious.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:16:45 by smonroe           #+#    #+#             */
/*   Updated: 2019/01/10 20:11:27 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static struct s_node *new(char c)
{
	struct s_node *tmp = malloc(sizeof(*tmp));
	tmp->c = c;
	tmp->prev = tmp->next = 0;
	return tmp;
}

static struct s_node *init(void)
{
	struct s_node *head = new((char *){CS}[0]);
	struct s_node *tail = head;
	int i = 0;

	while (++i < LEN)
	{
		tail->next = new((char *){CS}[i]);
		tail->next->prev = tail;
		tail = tail->next;
	}
	head->prev = tail;
	tail->next = head;
	return head;
}

char	*precious(int *text, int size)
{
	static struct s_node *ptr;
	int i = -1;
	char *ret = malloc(sizeof(*ret) * (size + 1));
	ret[size] = 0;

	if (!ptr)
		ptr = init();
	while (++i < size)
	{
		if (text[i] < 0) {
			for (int n = -text[i]; n; n--)
				ptr = ptr->prev;
		}
		else {
			for (int n = text[i]; n; n--)
				ptr = ptr->next;
		}
		ret[i] = ptr->c;
	}
	return ret;
}
