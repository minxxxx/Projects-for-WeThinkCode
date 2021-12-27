/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:45:42 by smonroe           #+#    #+#             */
/*   Updated: 2019/01/08 16:52:38 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	print(struct s_node *lst)
{	
	if (!lst)
		return ;
	print(lst->next);
	printf("%s ", lst->word);
}

void	printReverse(struct s_node *lst)
{	
	if (!lst)
		return ;
	print(lst->next);
	printf("%s", lst->word);
}
