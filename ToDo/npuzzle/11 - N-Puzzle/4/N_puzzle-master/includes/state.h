/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 09:44:20 by ggroener          #+#    #+#             */
/*   Updated: 2016/11/10 09:44:21 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_H

# include <env.h>
# include <tree.h>

typedef struct s_state_list t_state_list;
typedef struct s_state t_state;

typedef struct		s_state_list
{
	t_state 		*state;
 	t_state_list	*next;
}					t_state_list;
 
typedef struct		s_state
{

	t_state			*pred;
 	int 			**puzzle;
	int				f;
	int				g;
	int				h;
}					t_state;

#endif
