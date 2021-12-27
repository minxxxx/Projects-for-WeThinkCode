/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 18:27:10 by smonroe           #+#    #+#             */
/*   Updated: 2019/01/09 18:50:49 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static struct s_item	*new(int idx)
{
	struct s_item *tmp = malloc(sizeof(*tmp));
	tmp->idx = idx;
	tmp->next = 0;
	return tmp;
}

struct s_stack			*stackInit(void)
{
	struct s_stack *tmp = malloc(sizeof(*tmp));
	tmp->item = 0;
	return tmp;
}

int		pop(struct s_stack *stack)
{
	if (!stack)
		return 0;
	if (!stack->item)
		return 0;
	struct s_item *tmp = stack->item;
	stack->item = stack->item->next;
	int r = tmp->idx;
	free(tmp);
	return r;
}

void	push(struct s_stack *stack, int idx)
{
	if (!stack)
		return ;
	if (!stack->item)
		stack->item = new(idx);
	else
	{
		struct s_item *tmp = new(idx);
		tmp->next = stack->item;
		stack->item = tmp;
	}
}

char *strjoin(char *a, char *b)
{
	int la = a ? strlen(a) : 0, lb = b ? strlen(b) : 0, lc = la + lb;
	char *ret = malloc(lc + 2);
	for (int i = 0; i < la; i++)
		ret[i] = a[i];
	for (int i = la; i < lc; i++)
		ret[i] = b[i - la];
	ret[lc] = 0;
	free(a);
	return ret;
}	

char	*console(void)
{
	struct s_stack *stack = stackInit();
	char *buf = 0;
	char *msg = 0;
	int ret = 0;
	size_t sz = 0;
	int send = 0;

	while (++send)
	{
		printf("<>:");
		fflush(stdout);
		if ((ret = getline(&buf, &sz, stdin)) < 1) 
			break ;
		buf[ret - 1] = 0;
		fflush(stdin);
		if (!strcmp("UNDO", buf))
			msg[pop(stack)] = 0;
		else if (!strcmp("SEND", buf))
			break ;
		else
		{
			if (!msg) {
				msg = strdup(buf);
				push(stack, 0);
			}
			else {
				push(stack, strlen(msg));
				msg = strjoin(msg, buf);
			}
		}
		printf(">>> %s\n", msg);
	}
	return msg;
}
