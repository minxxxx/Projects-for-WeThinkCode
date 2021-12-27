/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadenho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 02:04:57 by jbadenho          #+#    #+#             */
/*   Updated: 2017/11/24 02:05:12 by jbadenho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 ** Static int hides makes it so that the funct cant be called in another file.
 ** This function will check first if its a valid digit.
*/
/*
 ** If it is a valid digit it will check if its a neg or pos value.
 ** If its not a valid number it will return value of the input.
*/

static int	numbers_part(const char *str, long long number, int negative)
{
	while (*str <= '9' && *str >= '0')
	{
		number = number * 10 + *str - '0';
		str++;
		if (number < 0)
		{
			if (negative == 1)
				return (0);
			return (-1);
		}
	}
	if (negative)
		number = -number;
	return (number);
}

/*
 ** ft_atoi turns ascii values into intergers.
 ** this funtion will first check for any spaces and increment to the next one.
*/
/*
 ** it then checks if its a negative value and if it has value after the '-'.
 ** if it does it makes negative = 1.
*/
/*
 ** then it checks if it is a postive and if it is it incrm to the nxt val.
 ** if the str value = '0' it then carries on incrementing str to carry on.
*/
/*
 ** it then returns the value of the numbers_part funt with the input values.
*/

int			ft_atoi(const char *str)
{
	long long	number;
	int			negative;

	negative = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' && str++)
		negative = 1;
	else if (*str == '+')
		str++;
	while (*str == '0')
		str++;
	number = 0;
	return (numbers_part(str, number, negative));
}
