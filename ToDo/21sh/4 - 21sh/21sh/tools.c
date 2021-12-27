/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 21:53:51 by sasiedu           #+#    #+#             */
/*   Updated: 2016/08/02 01:16:24 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "shell.h"

int		ft_shell_putchar(int c)
{
	return (write(1, &c, 1));
}

void	ft_remove_terminal_char(void)
{
	tputs(tgetstr("le", 0), 1, ft_shell_putchar);
	tputs(tgetstr("dc", 0), 1, ft_shell_putchar);
}
