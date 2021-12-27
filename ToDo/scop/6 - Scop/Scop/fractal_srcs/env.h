/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 13:38:31 by ggroener          #+#    #+#             */
/*   Updated: 2016/09/30 13:38:33 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "window.h"
# include "position.h"

typedef struct		s_env
{
	t_window		*window;
	t_position		*position;
	char			fractal;
	char			*arg;
	char			cap_mouse;
}					t_env;

#endif
