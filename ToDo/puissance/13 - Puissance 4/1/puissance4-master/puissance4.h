/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance4.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <telain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 20:22:14 by telain            #+#    #+#             */
/*   Updated: 2016/02/27 16:17:08 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE4_H
# define PUISSANCE4_H

# include <stdlib.h>
# include "libft/libft.h"

typedef struct	s_value
{
	int			size_x;
	int			size_y;
	int			color;
	int			**grid;
}				t_value;

t_value		*play(int col, int player, t_value *value);
t_value		*create_grid(t_value *value);
t_value		*create_value(int size_x, int size_y);
void		display_grid(t_value *value);
char		*read_input(t_value *value);

#endif
