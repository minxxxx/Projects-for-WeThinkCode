/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 07:57:33 by wide-aze          #+#    #+#             */
/*   Updated: 2014/11/13 17:03:30 by wide-aze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_is_unnecessary(char c)
{
	if (c == ' ' || c == '\f' || c == '\n')
		return (1);
	if (c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int		i;
	int		nb;
	int		is_negative;

	i = 0;
	nb = 0;
	is_negative = 1;
	while (ft_is_unnecessary(str[i]) == 1)
		i++;
	if (str[i] == '-')
		is_negative *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	nb *= is_negative;
	return (nb);
}
