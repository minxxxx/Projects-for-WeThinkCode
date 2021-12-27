/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:14:40 by ggroener          #+#    #+#             */
/*   Updated: 2016/11/09 11:47:53 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include <state.h>

typedef struct	s_env
{
	t_state		*start;
	t_state		*end;
	int			uniform;
	int			greedy;
	int			size;
	int			algo;
}				t_env;
#endif
