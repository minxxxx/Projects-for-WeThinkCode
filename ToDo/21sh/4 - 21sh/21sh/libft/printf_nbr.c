/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 10:21:54 by sasiedu           #+#    #+#             */
/*   Updated: 2016/07/25 12:45:10 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_nbr_zero(char **str, t_flag **para)
{
	int		check;
	int		size;
	char	*temp;

	check = 0;
	size = (*para)->wid - ft_strlen(*str);
	if ((*str)[0] == '-')
		check = 1;
	if ((*para)->wid > (int)ft_strlen(*str))
	{
		temp = ft_strnew(size);
		ft_memset(temp, '0', size);
		if (check == 1)
			*str = ft_strjoin(temp, &(*str)[1]);
		else
			*str = ft_strjoin(temp, *str);
		if (check == 1)
			*str = ft_strjoin("-", *str);
		ft_memdel((void **)&temp);
	}
}

void	ft_printf_nbr_minus(char **str, t_flag **para)
{
	int		size;
	char	*temp;

	size = (*para)->wid - ft_strlen(*str);
	if ((*para)->wid > (int)ft_strlen(*str))
	{
		temp = ft_strnew(size);
		ft_memset(temp, ' ', size);
		*str = ft_strjoin(*str, temp);
		ft_memdel((void **)&temp);
	}
}

void	ft_printf_nbr_wid(char **str, t_flag **para)
{
	int		size;
	char	*temp;

	size = (*para)->wid - ft_strlen(*str);
	if ((*para)->wid > (int)ft_strlen(*str))
	{
		temp = ft_strnew(size);
		ft_memset(temp, ' ', size);
		*str = ft_strjoin(temp, *str);
		ft_memdel((void **)&temp);
	}
}
