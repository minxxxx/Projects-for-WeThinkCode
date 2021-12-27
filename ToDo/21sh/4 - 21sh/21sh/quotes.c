/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 12:09:38 by sasiedu           #+#    #+#             */
/*   Updated: 2016/08/07 14:25:57 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_exec_quotes(t_term **sh)
{
	ft_putstr((*sh)->prt);
	(*sh)->std_cur = ft_strlen((*sh)->prt);
	ft_memset((*sh)->line, 0, MAX_LEN);
	tputs(tgetstr("sc", 0), 0, ft_shell_putchar);
}
