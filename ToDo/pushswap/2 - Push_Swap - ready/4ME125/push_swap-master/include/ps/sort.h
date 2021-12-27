/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps/sort.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:15:51 by alucas-           #+#    #+#             */
/*   Updated: 2018/03/12 18:15:53 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_SORT_H
# define PS_SORT_H

# include <libft.h>

struct s_ps;

/*
** Sort the `stack`.
** @param ps    The ps env
** @param stack The id of stack to sort
** @param n     The size to sort
*/
extern void	ps_sort(struct s_ps *ps, uint8_t stack, uint32_t n);

/*
** Sort the `stack` using the quick sort algorithm.
** Sort from 20 to INF
** @param ps    The ps env
** @param stack The id of stack to sort
** @param n     The size to sort
*/
extern void	ps_quicksort(struct s_ps *ps, uint8_t stack, uint32_t n);

/*
** Sort the `stack` using the selection sort algorithm.
** Sort from 3 to 20.
** @param ps    The ps env
** @param stack The id of stack to sort
** @param n     The size to sort
*/
extern void	ps_selectsort(struct s_ps *ps, uint8_t stack);

/*
** Sort the `stack` using custom algorithm.
** Sort from 0 to 3.
** @param ps    The ps env
** @param stack The id of stack to sort
** @param n     The size to sort
*/
extern void	ps_minisort(struct s_ps *ps, uint8_t stack, uint32_t n);

#endif
