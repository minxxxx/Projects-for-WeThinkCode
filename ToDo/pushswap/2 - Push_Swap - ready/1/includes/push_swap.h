/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtouffet <vtouffet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 19:11:45 by vtouffet          #+#    #+#             */
/*   Updated: 2018/04/22 13:53:19 by vtouffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "checker.h"

void	ft_push_swap_process(t_env *env);
void	ft_display_operations(t_env env);
void	ft_replace_as_simple_numbers(t_env *env);
int		ft_checker_check_b(t_env env);

#endif

