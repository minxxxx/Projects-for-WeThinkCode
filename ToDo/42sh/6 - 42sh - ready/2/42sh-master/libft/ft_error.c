/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadenho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 02:07:01 by jbadenho          #+#    #+#             */
/*   Updated: 2017/11/24 02:07:05 by jbadenho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_cmd_unknown(char *cmd)
{
	ft_putstr(GREEN"shell🐚 : "YELLOW);
	ft_putstr("command not found: "RESET);
	ft_putendl(cmd);
}
