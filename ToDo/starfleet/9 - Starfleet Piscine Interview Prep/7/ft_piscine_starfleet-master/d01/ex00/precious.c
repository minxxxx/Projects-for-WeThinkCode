#include "header.h"

struct s_node *new_node(char c, struct s_node *next, struct s_node *prev)
{
	struct s_node *node;

	node = (struct s_node*)malloc(sizeof(struct s_node));
	if (node == NULL)
		return (NULL);
	node->c = c;
	node->next = next;
	node->prev = prev;
	return (node);
}

struct s_node *create_list(char *s)
{
	struct s_node	*head;
	struct s_node	*new;
	struct s_node	*tmp;
	int				i;

	head = new_node(s[0], NULL, NULL);
	tmp = head;
	i = 0;
	while (s[++i])
	{
		new = new_node(s[i], NULL, tmp);
		tmp->next = new;
		tmp = new;
	}
	tmp->next = head;
	head->prev = tmp;
	return (head);
}

char *precious(int *text, int size)
{
	char			*decoded;
	struct s_node	*list_iter;
	int				list_size;
	int 			i;
	int 			n;

	list_iter = create_list(CS);
	list_size = strlen(CS);
	decoded = (char*)malloc(sizeof(char) * (size + 1));
	if (decoded == NULL)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		n = text[i];
		if (n > list_size / 2)
			n -= list_size;
		else if (n < -list_size / 2)
		 	n += list_size;
		if (n >= 0)
			while (n--)
				list_iter = list_iter->next;
		else
			while (n++)
				list_iter = list_iter->prev;
		decoded[i] = list_iter->c;
	}
	decoded[i] = '\0';
	return (decoded);
}
