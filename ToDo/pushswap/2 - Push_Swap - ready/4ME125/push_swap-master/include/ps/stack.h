/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps/stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:15:51 by alucas-           #+#    #+#             */
/*   Updated: 2018/03/12 18:15:53 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_STACK_H
# define PS_STACK_H

# include <libft.h>

# define STACK_A 0
# define STACK_B 1
# define STACK_BOTH 2

struct s_ps;
struct s_psnode;

typedef struct		s_psnode
{
	struct s_psnode	*prev;
	struct s_psnode	*next;
	uint32_t		val;
}					t_psnode;

/*
** Get the head node of the desired `stack`.
** @param ps    The ps env
** @param stack The id of stack to retrieve head
** @return      The stack head or `NULL` if empty
*/
extern t_psnode		*ps_head(struct s_ps *ps, uint8_t stack);

/*
** Check whatever `stack` is sorted on a `n` range.
** @param ps    The ps env
** @param stack The id of stack to check
** @param n     The `n` range to check if sorted
**              If lower than 0, `n` become the length of `stack`
** @return      If the `stack` is sorted
*/
extern int			ps_issort(struct s_ps *ps, uint8_t stack, int64_t n);

/*
** Dump the `stack` to `output` ps file descriptor.
** @param ps    The ps env
** @param stack The id of stack to retrieve tail
*/
extern void			ps_dump(struct s_ps *ps, uint8_t stack);

typedef struct		s_nval
{
	int				val;
	uint32_t		idx;
}					t_nval;

/*
** Normalize a stack.
** ex: [5 2 1 4 0] became [4 2 1 3 0]
** @param ps    The ps env
** @param stack The stack to normalize
*/
extern void			ps_norm(struct s_ps *ps, uint8_t stack);

#endif
