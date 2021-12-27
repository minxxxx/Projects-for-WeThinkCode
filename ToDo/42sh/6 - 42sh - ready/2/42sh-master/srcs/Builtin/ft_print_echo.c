/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaidoo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 12:51:16 by mnaidoo           #+#    #+#             */
/*   Updated: 2017/11/24 02:50:45 by mnaidoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"
#define LINE write(1, "\n", 1),i+=2
#define N if(s[i]=='\\'&&s[i+1]=='n')LINE
#define CHECK_FLAG (ft_strncmp(s, "echo -n ", 8) == 0)?(i=8,n=1):(i=5)
#define FLAG (ft_strncmp(s, "echo -n ", 8) != 0)?(i=8):(i=5)

/*
 ** Prints echo while checking for the -n flag and for newline escapes
*/

void	ft_print_no_qoutes(char *s)
{
	int		i;
	int		n;
	int		pos;

	n = 0;
	CHECK_FLAG;
	pos = i;
	if (s[i] == 34 || s[i] == 39)
		while (s[i++] != '\0')
		{
			if (s[i] == s[pos])
				i = i + 1;
			N;
			write(1, &s[i], 1);
		}
	else
		while (s[i] != '\0')
		{
			write(1, &s[i], 1);
			i++;
		}
	(n == 1) ? write(1, "%\n", 2) : write(1, "\n", 1);
}

/*
 ** Print echo normally
*/

void	ft_print_echo(char *s, char c)
{
	int		i;

	i = 0;
	if (ft_strncmp("echo ", s, 5) == 0)
		i = 5;
	FLAG;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		write(1, &s[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

/*
 ** Print outs the 2d array if echo
*/

void	ft_print_dqoute(char **arr, char sym)
{
	int	i;

	(void)sym;
	i = 1;
	while (arr[i])
	{
		ft_print_echo(arr[i], sym);
		i++;
	}
	ft_putstr("\n");
}
