# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    confclasses.py                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/10 13:13:13 by ngoguey           #+#    #+#              #
#    Updated: 2015/09/19 11:39:59 by ngoguey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import cog
from confutils import *

class Cstruct:
	def __init__(self):
		pass
	def printstr(self, s):
		if len(s) + self.col > self.maxcol:
			cog.out('\n\t')
			self.col = 4
		cog.out(s)
		self.col += len(s)
	@staticmethod
	def output_enum_start():
		raise NotImplementedError("Subclass must implement abstract method")
	@staticmethod
	def output_enum_end():
		raise NotImplementedError("Subclass must implement abstract method")
	def output_enum_line(self):
		raise NotImplementedError("Subclass must implement abstract method")
	@staticmethod
	def output_cconf_start():
		raise NotImplementedError("Subclass must implement abstract method")
	@staticmethod
	def output_cconf_end():
		raise NotImplementedError("Subclass must implement abstract method")
	def output_cconf_entry(self):
		raise NotImplementedError("Subclass must implement abstract method")

class Vshader(Cstruct):
	def __init__(self, name, filename, unif_funname, *args):
		self.name = name
		self.filename = filename
		self.unif_funname = unif_funname
		self.locations = args
	@staticmethod
	def output_enum_start():
		output_enums_indent_2str("typedef enum", "e_vshader_index\n{")
	@staticmethod
	def output_enum_end():
		cog.outl("\t" + "sp_" + "num" + "_vshaders")
		output_enums_indent_2str("}", "t_vshader_index;")
	def output_enum_line(self):
		cog.outl("\t" + "sp_" + self.name + "_vshader,")
	@staticmethod
	def output_cconf_start():
		output_cconf_start("vshader", "vshaders")
	@staticmethod
	def output_cconf_end():
		output_cconf_end("vshaders")
	def output_cconf_entry(self):
		cog.out("\tVSHADER(\"" + self.filename
			+ "\", ")
		if self.unif_funname != "":
			cog.out("&sp_unif_" + self.unif_funname + ",\n\t")
		else:
			cog.out("NULL,\n\t")
		for loc in self.locations[0:-1]:
			cog.out("LOC(sp_" + loc[0] + "_loc, " + str(loc[1]) + "), ")
		loc = self.locations[-1]
		cog.out("LOC(sp_" + loc[0] + "_loc, " + str(loc[1]) + ")")
		cog.outl("),")

class Fshader(Cstruct):
	def __init__(self, name, filename, unif_funname):
		self.name = name
		self.filename = filename
		self.unif_funname = unif_funname
	@staticmethod
	def output_enum_start():
		output_enums_indent_2str("typedef enum", "e_fshader_index\n{")
	@staticmethod
	def output_enum_end():
		cog.outl("\t" + "sp_" + "num" + "_fshaders")
		output_enums_indent_2str("}", "t_fshader_index;")
	def output_enum_line(self):
		cog.outl("\t" + "sp_" + self.name + "_fshader,")
	@staticmethod
	def output_cconf_start():
		output_cconf_start("fshader", "fshaders")
	@staticmethod
	def output_cconf_end():
		output_cconf_end("fshaders")
	def output_cconf_entry(self):
		cog.out("\tFSHADER(\"" + self.filename + "\", ")
		if self.unif_funname != "":
			cog.out("&sp_unif_" + self.unif_funname + "),\n")
		else:
			cog.out("NULL" + "),\n")

class Gshader(Cstruct):
	def __init__(self, name, filename, unif_funname):
		self.name = name
		self.filename = filename
		self.unif_funname = unif_funname
	@staticmethod
	def output_enum_start():
		output_enums_indent_2str("typedef enum", "e_gshader_index\n{")
	@staticmethod
	def output_enum_end():
		cog.outl("\t" + "sp_" + "num" + "_gshaders,")
		cog.outl("\t" + "sp_" + "no" + "_gshader")
		output_enums_indent_2str("}", "t_gshader_index;")
	def output_enum_line(self):
		cog.outl("\t" + "sp_" + self.name + "_gshader,")
	@staticmethod
	def output_cconf_start():
		output_cconf_start("gshader", "gshaders")
	@staticmethod
	def output_cconf_end():
		output_cconf_end("gshaders")
	def output_cconf_entry(self):
		cog.out("\tGSHADER(\"" + self.filename + "\", ")
		if self.unif_funname != "":
			cog.out("&sp_unif_" + self.unif_funname + "),\n")
		else:
			cog.out("NULL" + "),\n")

class Tcshader(Cstruct):
	def __init__(self, name, filename, unif_funname):
		self.name = name
		self.filename = filename
		self.unif_funname = unif_funname
	@staticmethod
	def output_enum_start():
		output_enums_indent_2str("typedef enum", "e_tcshader_index\n{")
	@staticmethod
	def output_enum_end():
		cog.outl("\t" + "sp_" + "num" + "_tcshaders,")
		cog.outl("\t" + "sp_" + "no" + "_tcshader")
		output_enums_indent_2str("}", "t_tcshader_index;")
	def output_enum_line(self):
		cog.outl("\t" + "sp_" + self.name + "_tcshader,")
	@staticmethod
	def output_cconf_start():
		output_cconf_start("tcshader", "tcshaders")
	@staticmethod
	def output_cconf_end():
		output_cconf_end("tcshaders")
	def output_cconf_entry(self):
		cog.out("\tTCSHADER(\"" + self.filename + "\", ")
		if self.unif_funname != "":
			cog.out("&sp_unif_" + self.unif_funname + "),\n")
		else:
			cog.out("NULL" + "),\n")

class Teshader(Cstruct):
	def __init__(self, name, filename, unif_funname):
		self.name = name
		self.filename = filename
		self.unif_funname = unif_funname
	@staticmethod
	def output_enum_start():
		output_enums_indent_2str("typedef enum", "e_teshader_index\n{")
	@staticmethod
	def output_enum_end():
		cog.outl("\t" + "sp_" + "num" + "_teshaders,")
		cog.outl("\t" + "sp_" + "no" + "_teshader")
		output_enums_indent_2str("}", "t_teshader_index;")
	def output_enum_line(self):
		cog.outl("\t" + "sp_" + self.name + "_teshader,")
	@staticmethod
	def output_cconf_start():
		output_cconf_start("teshader", "teshaders")
	@staticmethod
	def output_cconf_end():
		output_cconf_end("teshaders")
	def output_cconf_entry(self):
		cog.out("\tTESHADER(\"" + self.filename + "\", ")
		if self.unif_funname != "":
			cog.out("&sp_unif_" + self.unif_funname + "),\n")
		else:
			cog.out("NULL" + "),\n")

class Program(Cstruct):
	def __init__(self, name, vsname, fsname
				 , gsname = "no"
				 , tcsname = "no"
				 , tesname = "no"
				 , sboxprog = "pointshadow"
				 , img1=-1
				 , img2=-1
				 , img3=-1
				 , sbox=-1):
		self.name = name
		self.vsname = vsname
		self.fsname = fsname
		self.gsname = gsname
		self.tcsname = tcsname
		self.tesname = tesname
		self.sboxprog = sboxprog
		self.img1 = img1
		self.img2 = img2
		self.img3 = img3
		self.sbox = sbox
	@staticmethod
	def output_enum_start():
		output_enums_indent_2str("typedef enum", "e_program_index\n{")
	@staticmethod
	def output_enum_end():
		cog.outl("\t" + "sp_" + "num" + "_programs")
		output_enums_indent_2str("}", "t_program_index;")
	def output_enum_line(self):
		cog.outl("\t" + "sp_" + self.name + "_program,")
	@staticmethod
	def output_cconf_start():
		output_cconf_start("program", "programs")
	@staticmethod
	def output_cconf_end():
		output_cconf_end("programs")
	def output_cconf_entry(self):
		self.col = 3
		self.maxcol = 80
		self.printstr("\tPROG(sp_" + self.vsname + "_vshader")
		self.printstr(", sp_" + self.fsname + "_fshader")
		self.printstr(", sp_" + self.gsname + "_gshader")
		self.printstr(", sp_" + self.tcsname + "_tcshader")
		self.printstr(", sp_" + self.tesname + "_teshader")
		self.printstr(", sp_" + self.sboxprog + "_program")
		self.printstr(", TEXI(")
		self.printstr(str(self.img1))
		self.printstr(", " + str(self.img2))
		self.printstr(", " + str(self.img3))
		self.maxcol = 78
		self.printstr(", " + str(self.sbox) + ")")
		cog.outl("),");

class Texture(Cstruct):
	def __init__(self, name, filename):
		self.name = name
		self.filename = filename
	@staticmethod
	def output_enum_start():
		output_enums_indent_2str("typedef enum", "e_texture_index\n{")
	@staticmethod
	def output_enum_end():
		cog.outl("\t" + "sp_" + "num" + "_textures,")
		cog.outl("\t" + "sp_" + "no" + "_texture")
		output_enums_indent_2str("}", "t_texture_index;")
	def output_enum_line(self):
		cog.outl("\t" + "sp_" + self.name + "_texture,")
	@staticmethod
	def output_cconf_start():
		output_cconf_start("texture", "textures")
	@staticmethod
	def output_cconf_end():
		output_cconf_end("textures")
	def output_cconf_entry(self):
		cog.outl("\tTEXTURE(\"" + self.filename + "\"),")

class Mesh(Cstruct):
	g_index = 0
	def __init__(self, name, program
			, objfile_enum = "ft"
			, usage="GL_STATIC_DRAW"
			, grp_enum = "no"
			, tex_enum = "spherical"
			, vert_before="false"
			, recenter="false"
			, texscale = (1., 1.)
			, fill_funbody = """{\n\treturn (sp_meshfillbumb_objmodel(me, vao));\n}"""):
		self.name = name
		self.program = program
		self.usage = usage
		self.objfile_enum = objfile_enum
		self.grp_enum = grp_enum
		self.tex_enum = tex_enum
		self.vert_before = vert_before
		self.recenter = recenter
		self.texscale = texscale
		self.fill_funbody = fill_funbody
		self.index = Mesh.g_index
		Mesh.g_index += 1
	@staticmethod
	def output_enum_start():
		output_enums_indent_2str("typedef enum", "e_mesh_index\n{")
	@staticmethod
	def output_enum_end():
		cog.outl("\t" + "sp_" + "num" + "_meshes")
		output_enums_indent_2str("}", "t_mesh_index;")
	def output_enum_line(self):
		cog.outl("\t" + "sp_" + self.name + "_mesh,")
	@staticmethod
	def output_cconf_start():
		output_cconf_start("mesh", "meshes")
	@staticmethod
	def output_cconf_end():
		output_cconf_end("meshes")
	def output_cconf_entry(self):
		self.col = 3
		self.maxcol = 80
		self.printstr("\tMESH(")
		self.printstr(self.usage) #usage
		self.printstr(", " + "sp_" + self.program + "_program") #prog
		self.printstr(", " + "sp_" + self.objfile_enum + "_objfile")
		self.printstr(", " + "&sp_meshfill_" + self.name) #primary_fill
		self.printstr(", " + self.recenter)
		self.printstr(", " + "sp_" + self.grp_enum + "_ebogrouping")
		self.printstr(", " + self.vert_before)
		self.printstr(", " + "sp_" + self.tex_enum + "_texwrapping")
		self.maxcol = 78
		self.printstr(", " + "{" + str(self.texscale[0]) + "f, "
					  + str(self.texscale[1]) + "f}")
		cog.outl('),')
		
	def output_meshfill(self, index_first):
		if self.index >= index_first and self.index < index_first + 5:
			output_dotc_indent_2str("int", "sp_meshfill_" + self.name
			+ "(t_mesh *me, t_vao_basic *vao)")
			cog.outl(self.fill_funbody + "\n")

class Model(Cstruct):
	def __init__(self, name, mename, tename, unif_funname):
		self.name = name
		self.mename = mename
		self.tename = tename
		self.unif_funname = unif_funname
	@staticmethod
	def output_enum_start():
		output_enums_indent_2str("typedef enum", "e_model_index\n{")
	@staticmethod
	def output_enum_end():
		cog.outl("\t" + "sp_" + "num" + "_models")
		output_enums_indent_2str("}", "t_model_index;")
	def output_enum_line(self):
		cog.outl("\t" + "sp_" + self.name + "_model,")
	@staticmethod
	def output_cconf_start():
		output_cconf_start("model", "models")
	@staticmethod
	def output_cconf_end():
		output_cconf_end("models")
	def output_cconf_entry(self):
		cog.outl("\tMODEL(sp_" + self.mename + "_mesh, sp_"
		+ self.tename + "_texture, "
		+ ("NULL" if not self.unif_funname else "&sp_unif_" + self.unif_funname)
		+ "),")

class Ob(Cstruct):
	def __init__(self, model, **kwargs):
		self.model = model
		self.kwargs = kwargs
	@staticmethod
	def output_cconf_start():
		output_dotc_indent_2str("int", "sp_loadconf_obs(t_env *e)\n{")
	@staticmethod
	def output_cconf_end():
		cog.outl("\treturn (0);\n}")

	def output_cconf_entry(self):
		self.col = 3
		self.maxcol = 78
		self.printstr("\tOB(sp_" + self.model + "_model")
		for k, v in self.kwargs:
			if k == sca:
				s = str(float(v)) + 'f'
				self.printstr(', ob_sca, OTOV3(' + s+', '+s+', '+s + ')')
			# printstr("ob_" + str(k) + ', ')
		cog.outl(');')
			
