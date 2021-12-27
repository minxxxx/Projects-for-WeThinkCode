/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 04:15:59 by amontano          #+#    #+#             */
/*   Updated: 2019/01/09 04:16:00 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_stack *stackInit(void)
{
	t_stack	*s = (t_stack *)malloc(sizeof(t_stack));
	if (s)
		s->item = NULL;
	else
		return (NULL);
	return (s);
}

int pop(struct s_stack *stack)
{
	t_item  *tmp;

    tmp = stack->item;
    stack->item = tmp->next;
	return (tmp->idx);
}

t_item	*new_item(int n)
{
	t_item *new = malloc(sizeof(t_item));

    if (new)
    {
	    new->idx = n;
	    new->next = NULL;
    }
	return (new);
}

void push(struct s_stack *stack, int idx)
{
	t_item	*push = new_item(idx);

    if (push)
    {
        push->idx = idx;
	    push->next = stack->item;
	    stack->item = push;
    }
}

char *console(void)
{
    char    *out = malloc(sizeof(char) * 256);
    char    in[256];
    int     idx = 0;
    t_stack *stack = stackInit();

    bzero(out, 256);
    while (1)
    {
        bzero(in, 256);
        printf("<msg:>: ");
        fgets(in, 256, stdin);
        in[strlen(in) - 1] = '\0';
        if (!strcmp(in, "SEND"))
            break ;
        else if (!strcmp(in, "UNDO") )
        {
            if (stack->item)
                idx = pop(stack);
            bzero(out + idx, 256 - idx);
        }
        else
        {
            push(stack,idx);
            memmove(out + idx, in, strlen(in));
            idx += strlen(in);
        }
        printf("%s\n\n", out);
    }
    return (strdup(out));

}

