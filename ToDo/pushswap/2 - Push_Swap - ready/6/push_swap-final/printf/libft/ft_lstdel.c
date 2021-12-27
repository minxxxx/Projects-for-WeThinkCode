/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfavero <cfavero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:00:01 by cfavero           #+#    #+#             */
/*   Updated: 2018/05/09 14:07:17 by mmanley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(char **))
{
	t_list *temp;

	if (alst == NULL || del == NULL)
		return ;
	temp = *alst;
	while (temp)
	{
		del(temp->content);
		free(temp);
		temp = temp->next;
	}
	*alst = NULL;
}
