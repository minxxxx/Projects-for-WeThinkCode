# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#              #
#    Updated: 1970/01/01 00:00:42 by alucas-          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq (,$(OUTLIB_DIR))
  $(error Must precise OUTLIB_DIR)
endif

# Configuration
FT_P_LISTEN_QUEUE := 6

LIBFT_ROOT_DIR := libft
include $(LIBFT_ROOT_DIR)/makefile.mk
include src/makefile.mk
