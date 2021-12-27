/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps/ps.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:15:51 by alucas-           #+#    #+#             */
/*   Updated: 2018/03/12 18:15:53 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_PS_H
# define PS_PS_H

# include "op.h"
# include "stack.h"

# define OPTS "0123456789vsUio"

# define OPT_VERB (1 << 0)
# define OPT_OPTI (1 << 1)
# define OPT_STEP (1 << 2)
# define OPT_OPLOG (1 << 3)

typedef struct	s_ps
{
	char const	*prg;
	int			options;
	int			input;
	int			output;
	t_psnode	*nodes;
	t_lst		stacks[2];
	int			orders[2];
	t_vec		ops;
}				t_ps;

/*
** Initialize the push swap environment.
** @param ps    The ps env
** @param ac    The program argument list size
** @param av    The program argument list
*/
extern void		ps_init(t_ps *ps, int ac, char *av[]);

/*
** Exit the program and finalize the environment.
** @param ps    The ps env
** @param ecode The exit code
*/
extern void		ps_exit(t_ps *ps, int ecode);

#endif
