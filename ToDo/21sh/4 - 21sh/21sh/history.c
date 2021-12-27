/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 01:36:43 by sasiedu           #+#    #+#             */
/*   Updated: 2016/08/07 01:43:33 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*ft_history_tower(char *access, char *line)
{
	static t_list	*lst = NULL;
	static size_t	size = 0;
	static int		ptr = 0;

	if (ft_memcmp(access, "reset", 5) == 0 && ft_strlen(line) > 0)
	{
		size++;
		ptr = 0;
		ft_lstadd(&lst, ft_lstnew(ft_strdup(line), sizeof(char) * \
					ft_strlen(line)));
	}
	else if (ft_memcmp(access, "UP", 2) == 0 && ptr < (int)size)
		return (ft_history_line(&lst, ++ptr));
	else if (ft_memcmp(access, "DOWN", 4) == 0 && ptr > 0)
		if (--ptr > 0)
			return (ft_history_line(&lst, ptr));
	return (NULL);
}

char	*ft_history_line(t_list **lst, int ptr)
{
	char	*line;

	if (ptr > 1 && *lst != NULL)
		return (ft_history_line(&(*lst)->next, ptr - 1));
	if (*lst == NULL)
		return (NULL);
	line = ft_strsub((char *)(*lst)->content, 0, (*lst)->content_size);
	return (line);
}
