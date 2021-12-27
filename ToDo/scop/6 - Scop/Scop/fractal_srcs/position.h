/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 13:39:01 by ggroener          #+#    #+#             */
/*   Updated: 2016/09/30 13:39:02 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POSITION_H
# define POSITION_H

typedef struct		s_formula
{
	double			z_const;
	double			c_const;
	int				z_pow;
	int				c_pow;
	char			op;
	char			colour;
}					t_formula;

typedef struct		s_position
{
	double			julia_x_factor;
	double			julia_y_factor;
	double			offset_x;
	double			offset_y;
	double			density;
	double			min_x;
	double			max_x;
	double			min_y;
	double			max_y;
	double			zoom;
	double			x;
	double			y;
	t_formula		f;
}					t_position;

#endif
