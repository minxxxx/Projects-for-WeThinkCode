/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addlink.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftait <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 11:16:07 by ftait             #+#    #+#             */
/*   Updated: 2017/11/24 02:51:52 by ftait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"

void	addlink(t_list **head, char *str)
{
	t_list *newnode;
	t_list *temp;

	newnode = (t_list *)malloc(sizeof(t_list));
	newnode->content = str;
	newnode->next = NULL;
	temp = *head;
	if (*head == NULL)
		*head = newnode;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = newnode;
	}
}
