/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 16:53:20 by jaleman           #+#    #+#             */
/*   Updated: 2017/08/02 16:53:21 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

#define MSG_LEN		(255)
#define BUFF_SIZE	(4096)

struct s_stack		*initStack(void)
{
	struct s_stack	*stack;

	stack = (struct s_stack*)malloc(sizeof(struct s_stack));
	stack->item = NULL;
	return (stack);
}

void				push(struct s_stack *stack, int idx)
{
	struct s_item	*tmp;

	tmp = (struct s_item*)malloc(sizeof(struct s_item));
	tmp->idx = idx;
	tmp->next = stack->item;
	stack->item = tmp;
}

int					pop(struct s_stack *stack)
{
	struct s_item	*tmp;

	tmp = stack->item;
	stack->item = tmp->next;
	return (tmp->idx);
}

char				*console(void)
{
	int				curr;
	char			*input;
	char			msg[BUFF_SIZE];
	struct s_stack	*stack;

	curr = 0;
	if (!(input = (char *)malloc(sizeof(char) * MSG_LEN + 1)))
		return (NULL);
	stack = initStack();
	bzero(msg, BUFF_SIZE);
	while (1)
	{
		bzero(input, MSG_LEN);
		printf("?: ");
		fgets(input, MSG_LEN, stdin);
		input[strlen(input) - 1] = '\0';
		if (!strcmp(input, "UNDO"))
		{
			if (stack->item)
				curr = pop(stack);
			bzero(msg + curr, MSG_LEN - curr);
		}
		else if (!strcmp("SEND", input))
			break ;
		else
		{
			push(stack, curr);
			memmove(msg + curr, input, strlen(input));
			curr += strlen(input);
		}
		printf("%s\n\n", msg);
	}
	return (strdup(msg));
}
