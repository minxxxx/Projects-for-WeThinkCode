/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precious.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 12:23:18 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/24 14:43:37 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#define CS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 !?:;,.$&<>()+*-_="

void			add_node(struct s_node **list, char c)
{
	struct s_node	*node;
	
	node = new_node(c);
	if (*list == NULL)
	{
		node->next = node;
		node->prev = node;
		*list = node;
	}
	else
	{
		struct s_node	*last = (*list)->prev;
		node->next = *list;
		(*list)->prev = node;
		node->prev = last;
		last->next = node;
	}
}

struct s_node	*new_node(char c)
{
	struct s_node	*new_node;

	new_node = calloc(1, sizeof(struct s_node));
	new_node->c = c;
	return (new_node);
}

struct s_node	*populate_list(char *s)
{
	int 			i;
	struct s_node	*list = NULL;

	i = -1;
	while (s[++i])
		add_node(&list, s[i]);
	return (list);
}

char	*crack(struct s_node *list, int *n, int size)
{
	int				i;
	char			*s;
	struct s_node	*tmp;

	i = -1;
	tmp = list;
	s = calloc(size + 1, sizeof(char));
	while (++i < size)
	{
		
		if (n[i] >= 0)
		{
			while (--n[i] > -1)
				tmp = tmp->next;
		}
		else if (n[i] < 0)
		{
			while (++n[i] < 1)
				tmp = tmp->prev;
		}
		s[i] = tmp->c;
	}
	s[i] = '\0';
	return (s);
}

char	*precious(int *text, int size)
{
	struct s_node	*cs;
	char			*ret;
	int				i;
	
	cs = populate_list(CS);
	i = 0;
	ret = crack (cs, text, size);
	return (ret);
}