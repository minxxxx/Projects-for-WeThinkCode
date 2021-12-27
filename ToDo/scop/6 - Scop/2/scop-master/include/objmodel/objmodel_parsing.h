/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objmodel_parsing.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 08:49:22 by ngoguey           #+#    #+#             */
/*   Updated: 2015/09/15 12:59:03 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJMODEL_PARSING_H
# define OBJMODEL_PARSING_H

# include "libft.h"
# include "fterror.h"
# include "ft_vector.h"
# include "objmodel/objmodel.h"
# include <stdio.h>

# define sp_enomem ft_enomem //tofix

# define BFSZ 1024

typedef struct	s_token
{
	char		*str;
	size_t		len;
	int			(*fun)();
}				t_token;

# define SETNODE t_ftset_node

typedef struct	s_tmpface
{
	SETNODE		*ptr[3];
}				t_tmpface;

# undef SETNODE

int				op_match_f(t_objmodel *m, char const *buf);
int				op_match_v(t_objmodel *m, char const *buf);
int				op_match_vt(t_objmodel *m, char const *buf);
int				op_match_vn(t_objmodel *m, char const *buf);

int				op_match_comment(t_objmodel *m, char const *buf);
int				op_match_smooth(t_objmodel *m, char const *buf);

int				op_match_group(t_objmodel *m, char const *buf);
int				op_match_mtllib(t_objmodel *m, char const *buf);
int				op_match_usemtl(t_objmodel *m, char const *buf);
int				op_match_name(t_objmodel *m, char const *buf);

/*
** face parsing, specific prototypes
*/
void			op_init_meshvectors(t_objmodel *m);
void			op_insert_face(t_objmodel *m, t_ui const oldind[9]);

void			op_faces_decr_indices(t_ui b[9], int i, int end);
int				op_parse_uiblock(char const **buf, t_ui uibuf[9],
									int const *indices);
t_bool			op_faces_indices_valid(t_objmodel const *m, t_ui const b[9]);

#endif
