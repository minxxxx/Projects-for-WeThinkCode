/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:14:07 by rzarate           #+#    #+#             */
/*   Updated: 2018/04/25 17:07:25 by rzarate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define TRUE 1

ssize_t readline(char **lineptr, FILE *stream)
{
  size_t len = 0;  // Size of the buffer, ignored.

  ssize_t chars = getline(lineptr, &len, stream);
  if((*lineptr)[--chars] == '\n')
    (*lineptr)[chars] = '\0';
  return chars;
}

struct s_stack	*stackInit(void)
{
	struct s_stack *new_stack;
	
	new_stack = calloc(1, sizeof(struct s_stack));
	new_stack->item = NULL;
	return (new_stack);
}

int				pop(struct s_stack *stack)
{
	struct s_item *top;
	top = stack->item;
	stack->item = stack->item->next;
	return (top->idx);
}

void			push(struct s_stack *stack, int	n)
{
	struct s_item *new_item;

	new_item = calloc(1, sizeof(struct s_item));
	new_item->idx = n;
	new_item->next = stack->item;
	stack->item = new_item;
}

char			*console(void)
{
	char			*line;
	int				line_len;
	char			message[255];
	int				current_len;
	int				old_idx;
	struct s_stack	*stack;

	stack = stackInit();
	current_len = 0;
	line_len = 0;
	line = calloc(256, sizeof(char));
	while (TRUE)
	{
		write(1, "tIpe ur msg: ", 13);
		line_len = readline(&line, stdin);
		if (strcmp(line, "SEND") == 0)
			break ;
		else if (strcmp(line, "UNDO") == 0)
		{
			if (!stack->item)
				printf("Q is empty, dumbass!\n");
			else
			{
				old_idx = pop(stack);
				printf("%d---%d\n", old_idx, current_len);
				while (old_idx < current_len)
				{
					message[old_idx] = '\0';
					old_idx++;
				}
				if (!stack->item)
					current_len = 0;
				else
					current_len = strlen(message);
				printf("%s\n", message);
			}
		}
		else
		{
			if (current_len + strlen(line) > 255)
			{
				printf("Damn, get your shit together man, ugh\n");
				exit(EXIT_FAILURE);
			}
			push(stack, current_len);
			current_len += strlen(line);
			strcat(message, line);
			printf("%s\n", message);
		}
	}
	free(line);
	while(stack->item)
		pop(stack);
	return (strdup(message));
}
