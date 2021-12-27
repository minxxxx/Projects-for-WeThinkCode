/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 09:46:31 by pbondoer          #+#    #+#             */
/*   Updated: 2016/12/24 13:07:36 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"
#include "libft.h"
#include "colors.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;

	t_stack *a;

	a = ps_new_stack(10, 0, 0);
	ps_print_stack(a, -1, -1);

	int n[5] = {1, 2, 3, 4, 5};
	a = ps_new_stack(5, 5, n);
	int i = 0;
	while (i < 5)
	{
		printf(C_YELLOW "rotate:\n");
		ps_rotate(a, 1);
		ps_print_stack(a, 0, 0);
		ps_debug(a);
		printf(C_GREEN "pop: %d\n", ps_pop(a));
		ps_print_stack(a, 0, 0);
		ps_debug(a);
		i++;
	}
}
