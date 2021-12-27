# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    confloader.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/10 13:13:20 by ngoguey           #+#    #+#              #
#    Updated: 2015/09/12 13:08:16 by ngoguey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import cog
from conf import *

cstructs1 = [vshaders, fshaders, gshaders, tcshaders, teshaders]
cstructs2 = [programs, textures, meshes, models]
cstructs = cstructs1 + cstructs2

def output_enums():
	for cstruct in cstructs:
		if len(cstruct) == 0:
			continue
		cstruct[0].output_enum_start()
		for elt in cstruct:
			elt.output_enum_line()
		cstruct[0].output_enum_end()
		cog.outl("")

def output_meshfill_prototypes():        
	for mesh in meshes:
		output_proto_indent_2str("int", "sp_meshfill_" + mesh.name
                + "(t_mesh *me, t_vao_basic *vao);")

def output_cconf1():
	for cstruct in cstructs1:
		assert len(cstruct) > 0
		cstruct[0].output_cconf_start()
		for elt in cstruct:
			elt.output_cconf_entry()
		cstruct[0].output_cconf_end()
		cog.outl("")

def output_cconf2():
	for cstruct in cstructs2:
		assert len(cstruct) > 0
		cstruct[0].output_cconf_start()
		for elt in cstruct:
			elt.output_cconf_entry()
		cstruct[0].output_cconf_end()
		cog.outl("")

def output_meshfill(first_index):
	cog.outl("")
	for mesh in meshes:
		mesh.output_meshfill(first_index)
