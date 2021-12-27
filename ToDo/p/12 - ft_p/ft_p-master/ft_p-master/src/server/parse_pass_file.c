/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pass_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 13:04:50 by jcamhi            #+#    #+#             */
/*   Updated: 2017/08/31 13:04:51 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

char	*free_tab_except(char **tab, size_t nbr)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = NULL;
	while (tab && tab[i])
	{
		if (i == nbr)
			ptr = tab[i];
		else
			free(tab[i]);
		i++;
	}
	if (tab)
		free(tab);
	return (ptr);
}

char	*get_pass(char *username, t_data *data)
{
	char	*s;
	char	**tab;

	if (data->pass_fd == -1)
		return (NULL);
	close(data->pass_fd);
	data->pass_fd = open(".pass", O_RDONLY);
	while ((get_next_line(data->pass_fd, &s)) > 0)
	{
		tab = ft_strsplit(s, ',');
		if (tab[0] == NULL)
		{
			data->error = 1;
			data->commentaire = " Error in the password file.";
			return (NULL);
		}
		if (ft_strequ(tab[0], username))
			return (free_tab_except(tab, 1));
		free_tab_except(tab, 13);
	}
	data->error = 1;
	data->commentaire = " User not found";
	return (NULL);
}
