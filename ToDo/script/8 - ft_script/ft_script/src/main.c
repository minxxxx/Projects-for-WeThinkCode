/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wide-aze <wide-aze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 09:09:05 by wide-aze          #+#    #+#             */
/*   Updated: 2015/10/19 07:17:43 by dw31             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_script.h>

int		main(int ac, char **av)
{
	t_env	env;

	init_env(&env);
	if (analyze_av_ac(&env, ac - 1, &av[1]))
		return (0);
	print_debug(&env);
	if (open_outfile(&env))
		return (0);
	if (launch_scripted_shell(&env, "-c"))
		return (0);
	close_outfile(&env);
	return (0);
}
