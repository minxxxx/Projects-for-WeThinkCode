/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:46:08 by jcamhi            #+#    #+#             */
/*   Updated: 2018/07/04 16:46:11 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_script.h>

static int	get_next_pty_name(char current[11])
{
	char	*letter;
	char	*nbr;

	letter = current + 8;
	nbr = current + 9;
	if (*nbr != '9')
	{
		(*nbr)++;
		return (1);
	}
	else if (*letter != 'z' && *letter != 'e')
	{
		*nbr = '0';
		(*letter)++;
		return (1);
	}
	else if (*letter == 'z')
	{
		*nbr = '0';
		(*letter) = 'a';
		return (1);
	}
	else
		return (0);
}

int			open_ttys(char mbuffer[11], char sbuffer[11], int *mfd)
{
	ft_strcpy(mbuffer, "/dev/ptyp0");
	while ((*mfd = open(mbuffer, O_RDWR)) == -1)
	{
		if (get_next_pty_name(mbuffer) == 0)
		{
			ft_putstr_fd("Couldn't allocate a pseudo terminal pair.\n", 2);
			return (0);
		}
	}
	ft_strcpy(sbuffer, mbuffer);
	sbuffer[5] = 't';
	return (1);
}
