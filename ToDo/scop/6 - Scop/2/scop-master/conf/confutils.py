# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    confutils.py                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/10 13:13:28 by ngoguey           #+#    #+#              #
#    Updated: 2016/03/02 11:54:31 by ngoguey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import cog
import math

ENUMS_INDENT_COLUMN = int(28)
ENUMS_INDENT_TABCOLUMN = int(ENUMS_INDENT_COLUMN / 4)
assert ENUMS_INDENT_TABCOLUMN * 4 == ENUMS_INDENT_COLUMN

def output_enums_indent_2str(lhs, rhs):
	num_tabs = ENUMS_INDENT_TABCOLUMN - int(math.floor(float(len(lhs)) / 4.))
	assert num_tabs > 0
	cog.outl(lhs + ('\t' * num_tabs) + rhs)

PROTO_INDENT_COLUMN = int(8)
PROTO_INDENT_TABCOLUMN = int(PROTO_INDENT_COLUMN / 4)
assert PROTO_INDENT_TABCOLUMN * 4 == PROTO_INDENT_COLUMN

def output_proto_indent_2str(lhs, rhs):
	num_tabs = PROTO_INDENT_TABCOLUMN - int(math.floor(float(len(lhs)) / 4.))
	assert num_tabs > 0
	cog.outl(lhs + ('\t' * num_tabs) + rhs)

DOTC_INDENT_COLUMN = int(16)
DOTC_INDENT_TABCOLUMN = int(DOTC_INDENT_COLUMN / 4)
assert DOTC_INDENT_TABCOLUMN * 4 == DOTC_INDENT_COLUMN

def output_dotc_indent_2str(lhs, rhs):
	num_tabs = DOTC_INDENT_TABCOLUMN - int(math.ceil(float(len(lhs)) / 4.))
	assert num_tabs > 0
	cog.outl(lhs + ('\t' * num_tabs) + rhs)

def output_cconf_start(singular, plural):
	output_dotc_indent_2str("int", "sp_loadconf_" + plural + "(t_env *e)")
	cog.outl("{\n\tt_" + singular + " const\t\ttmp[sp_num_"
		+ plural + "] = {\n")

def output_cconf_end(plural):
	cog.outl("""\t};
	memcpy(&e->""" + plural + """, &tmp, sizeof(tmp));
	return (0);\n}""")
