/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 16:53:20 by jaleman           #+#    #+#             */
/*   Updated: 2017/08/02 16:53:21 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <stdio.h>

void	reverseWords(struct s_node *lst)
{
	if (lst->next != NULL)
	{
		reverseWords(lst->next);
		putchar(' ');
	}
	printf("%s", lst->word);
	return ;
}

void	printReverse(struct s_node *lst)
{
	reverseWords(lst);
	putchar('\n');
	return ;
}
