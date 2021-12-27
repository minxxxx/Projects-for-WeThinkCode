/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 13:42:04 by ggroener          #+#    #+#             */
/*   Updated: 2016/11/15 13:42:05 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

# include <state.h>
typedef struct s_state t_state;
//# include <env.h>

typedef struct s_closed_tree t_closed_tree;

typedef struct		s_closed_tree 
{
	t_state			*state;
	t_closed_tree	**child;	
}					t_closed_tree;

#endif
