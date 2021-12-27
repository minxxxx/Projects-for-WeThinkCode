/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objmodel.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 16:15:35 by ngoguey           #+#    #+#             */
/*   Updated: 2015/09/03 18:23:58 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJMODEL_H
# define OBJMODEL_H

# include "ft_vector.h"
# include "ft_set.h"
# include "meshes/vao.h"

typedef struct	s_objmodel
{
	t_ftvector	coords;
	t_ftvector	textures;
	t_ftvector	normals;
	t_ftvector	faces;
	size_t		width;
	t_ftset		vertices;
}				t_objmodel;

int				op_parse_obj(t_objmodel *m, char const *filepath);
void			sp_clean_objmodel(t_objmodel *m);
void			op_retreive_data(t_objmodel *m, t_vao_basic *v);

#endif
