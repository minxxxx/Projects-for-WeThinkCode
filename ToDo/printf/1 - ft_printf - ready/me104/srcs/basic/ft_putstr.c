/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:23:13 by juspende          #+#    #+#             */
/*   Updated: 2017/12/06 09:03:51 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"
#include <unistd.h>

void	ft_putstr(char const *s, t_flag *flag)
{
	int		i;
	int		c;
	char	*tmp;

	i = 0;
	c = 0;
	if (!s)
		return (ft_putstr("(null)", flag));
	c = ft_strlen(flag->printed);
	i = ft_strlen((char *)s);
	if (flag->comma == 1 && flag->point <= 0)
		return ;
	if ((tmp = malloc(sizeof(char) * (i + c + 2))) == NULL)
		return ;
	tmp[0] = '\0';
	ft_strcat(tmp, flag->printed);
	ft_strcat(tmp, (char *)s);
	flag->charn = flag->charn + i;
	free(flag->printed);
	flag->printed = ft_strdup(tmp);
	free(tmp);
}

void	ft_putoctal(char const *s, t_flag *flag)
{
	int		i;
	int		c;
	char	*tmp;

	i = 0;
	c = 0;
	if (!s)
		return (ft_putstr("(null)", flag));
	i = ft_strlen((char *)s);
	c = ft_strlen(flag->printed);
	if (flag->comma && !flag->point && !flag->diez)
		return ;
	if ((tmp = malloc(sizeof(char) * (i + c) + 96)) == NULL)
		return ;
	tmp[0] = '\0';
	ft_strcat(tmp, flag->printed);
	ft_strcat(tmp, (char *)s);
	flag->charn = flag->charn + i;
	free(flag->printed);
	flag->printed = ft_strdup(tmp);
	free(tmp);
}

void	ft_puts(char *str, t_flag *flag)
{
	empty_buffer(flag);
	if (!str)
		return ;
	write(1, str, ft_strlen(str));
	flag->charn += ft_strlen(str);
}

void	ft_putnstr_free(void *str, t_flag *flag, int *c)
{
	size_t	i;
	size_t	n;
	char	*tmp;

	i = ft_strlen(flag->printed);
	n = ft_strchr(str, 37);
	if ((tmp = malloc(sizeof(char) * (i + n + 2))) == NULL)
		return ;
	tmp[0] = '\0';
	ft_strcat(tmp, flag->printed);
	ft_strncat(tmp, str, n);
	free(flag->printed);
	flag->printed = ft_strdup(tmp);
	free(tmp);
	flag->charn += n;
	if (*c != -1)
		*c += (n - 1);
	free(str);
	return ;
}

int		ft_putsterr(char *str)
{
	if (!str)
		return (-1);
	write(2, str, ft_strlen(str));
	return (ERROR);
}
