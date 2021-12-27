/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 13:58:47 by mnaidoo           #+#    #+#             */
/*   Updated: 2017/11/24 02:49:26 by mnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"
#define GNL	(get_next_line(0, &c) == 0) ? (a = 0) : (a = 42)
#define FLAG (ft_strncmp(s, "echo -n ", 8) == 0)?(i=8):(i=5)

/*
 ** This prints out the dqoute array appropriately
*/

int		ft_print_dqoute_array(char **dqoute, char *first, char sym)
{
	int		i;

	i = 0;
	ft_print_echo(first, sym);
	while (dqoute[++i])
		ft_putendl(dqoute[i]);
	ft_putendl("");
	return (0);
}

/*
** Set array will return a 2d array that is either null at temp[0] or has a str
** value. this is for printing out what's giving in echo if it has anything
** when opening the qoutes before dqoutes
*/

char	**set_array(char *s, char c)
{
	static int		i = 0;
	char			**temp;

	while (s[i] != c)
		i++;
	if (s[i + 1] != '\0')
	{
		temp = (char **)malloc(sizeof(char *) * 2);
		temp[0] = ft_strdup(s);
		temp[1] = NULL;
	}
	else
	{
		temp = (char **)malloc(sizeof(char *) * 2);
		temp[0] = ft_strdup("\n");
		temp[1] = NULL;
	}
	return (temp);
}

/*
 ** This will start the dqoute for echo if theres and uneven amount of qoutes
*/

void	ft_start_dqoute(char *s)
{
	int			a;
	char		*c;
	static int	i = 0;
	char		**array;

	a = 42;
	FLAG;
	array = (char **)malloc(sizeof(char *) * 2);
	array = set_array(s, s[i]);
	while (a)
	{
		ft_putstr(RED"dqoute > "RESET);
		GNL;
		if (ft_strcchr(c, s[i]) == NULL)
			array = ft_add_to_array(array, c);
		else
		{
			if (c[1] != '\0')
				array = ft_add_to_array(array, c);
			a = ft_print_dqoute_array(array, s, s[i]);
			ft_strdel(&c);
		}
		ft_strdel(&c);
	}
	ft_delarray(array);
}

/*
 ** This will check if the echo is printing single qoutes, double qoutes
 ** It will also check if it's printing and enviroment or not
*/

void	ft_echo_new(char *s, t_all *a)
{
	int		i;
	int		count;
	int		env;

	env = 0;
	i = -1;
	count = 0;
	while (s[++i])
		if (s[i] == 39 || s[i] == 34)
			count++;
	if (ft_strncmp(s, "echo $", 6) == 0)
	{
		ft_echoenv(s, a);
		env = 1;
	}
	else if (env != 1)
	{
		if (ft_is_even(count) == 1)
			ft_print_no_qoutes(s);
		else
			ft_start_dqoute(s);
	}
}
