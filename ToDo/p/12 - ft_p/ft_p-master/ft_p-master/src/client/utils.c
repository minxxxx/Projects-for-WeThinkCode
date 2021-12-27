/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 16:13:46 by jcamhi            #+#    #+#             */
/*   Updated: 2017/08/30 16:14:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

void	remove_cr(char *str)
{
	size_t	n;

	if (!str)
		return ;
	n = ft_strlen(str);
	if (n < 1)
		return ;
	if (str[n - 1] == 13)
	{
		str[n - 1] = '\0';
		return ;
	}
}

char	*build_request(const char *prefix, const char *suffix)
{
	char	*request;

	request = ft_strdup(prefix);
	request = ft_strjoinaf1(request, " ");
	if (suffix)
		request = ft_strjoinaf1(request, suffix);
	request = ft_strjoinaf1(request, "\r\n");
	return (request);
}

void	free_double_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
