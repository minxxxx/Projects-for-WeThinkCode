/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precious.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 22:13:40 by amontano          #+#    #+#             */
/*   Updated: 2019/01/08 22:14:45 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_list(t_node *boom)
{
	t_node	*survivor;

	while ((survivor = boom->next))
	{
		free(boom);
		boom = survivor;
	}
}

t_node  *new_node(char c)
{
	t_node *new = (t_node *)malloc(sizeof(t_node));
	new->c = c;
	new->next = NULL;
	new->prev = NULL;
	return (new ? new : NULL);
}

t_node *create_cir_dub_list()
{
	const char *cipher	= CS;
	int		i = 0;
	t_node	*cursor = new_node(*cipher);
	t_node	*tmp;
	t_node	*head		= cursor;

	while (cipher[++i] != '\0')
	{
		if (!cursor->next && cipher[i])
			cursor->next = new_node(cipher[i]);
		tmp = cursor;
		if (cursor->next)
			cursor = cursor->next;
		cursor->prev = tmp;
	}
	cursor->next = head;
	head->prev = cursor;
	return (head);
}

t_node	*rotate_lst(t_node *lst, int i)
{
	while (i != 0)
	{
		lst		= 	(i < 0) ? lst->prev : lst->next;
		i 		+= 	(i < 0) ? 1 		: -1;
	}
	return (lst);
}

char *precious(int *text, int size)
{
	static char message[512];
	t_node      *lst;
	int 		i = 0;

	lst = create_cir_dub_list();
	while ( i < size )
	{
		lst = rotate_lst(lst, text[i]);
		message[i] = lst->c;
		i++;
	}
	free_list(lst);
	return (message);
}
