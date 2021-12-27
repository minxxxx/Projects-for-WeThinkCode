SERVER_OBJ += src/ftp.o src/ush.o src/server.o \
              src/server/ls.o \
              src/server/cd.o \
              src/server/pwd.o

$(call set_config,src/server.o,FT_P_LISTEN_QUEUE)

$(eval $(call target_bin,server,SERVER_OBJ,SERVER_BIN))
$(SERVER_BIN): $(LIBFT_LIB)
$(SERVER_BIN): CFLAGS  +=  $(LIBFT_CFLAGS)
$(SERVER_BIN): INCLUDE +=  src

CLIENT_OBJ += src/ush.o src/client.o

$(eval $(call target_bin,client,CLIENT_OBJ,CLIENT_BIN))
$(CLIENT_BIN): $(LIBFT_LIB)
$(CLIENT_BIN): CFLAGS  +=  $(LIBFT_CFLAGS)
$(CLIENT_BIN): INCLUDE +=  src
