#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"
#include "console.h"

int main()
{

	/*-------------------
	launch your test here
	--------------------*/
	t_q		*q = queueInit();
	char 	*buf;
	char	in[256];

	while (1)
	{
		printf("<QUEUE> ");
		fgets(in, 256, stdin);
		in[strlen(in) - 1] = '\0';
		if (!strcmp(in, "ADD"))
		{
			buf = console();
			enqueue(q, buf);
			printf("Added %s\n", buf);
		}
		else if (!strcmp(in, "DONE"))
			break ;
		else
			printf("avaiable commands: ADD, DONE\n");
	}
	while (!isEmpty(q))
		printf("%s\n", dequeue(q));
	return (0);
}



// Function used for the test
// Don't go further :)

#include "console.h"

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

