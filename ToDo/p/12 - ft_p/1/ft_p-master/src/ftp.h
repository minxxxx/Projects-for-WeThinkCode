/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:42 by alucas-           #+#    #+#             */
/*   Updated: 1970/01/01 00:00:42 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FTP_H
# define __FTP_H

#include <fsm.h>

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define FTP_MAX_CLIENT (6)

enum ftp_type {
	FT_TYPE_ASCII = 0,
	FT_TYPE_NONPRINT,
};

enum ftp_mode {
	FTP_MODE_STREAM = 0
};

enum ftp_struct {
	FTP_STRUCTURE_FILE = 0,
	FTP_STRUCTURE_RECORD,
};

#define FTP_STR_TO_CMD(s) ((s)[0]+((s)[1]<<8)+((s)[1]<<16)+((s)[1]<<24))

enum ftp_cmd {
	FTP_CMD_USER = 1,
	FTP_CMD_PASS,
	FTP_CMD_QUIT,
	FTP_CMD_PORT,
	FTP_CMD_TYPE,
	FTP_CMD_MODE,
	FTP_CMD_STRU,
	FTP_CMD_RETR,
	FTP_CMD_STOR,
	FTP_CMD_NOOP,
};

struct ftp_usr {
	char const *user;
	char const *pswd;
};

typedef struct ftp_cli {
	struct ftp_srv *srv;
	int socket;
	struct sockaddr_in addr;
	struct timeval timeout;
	fsm_t fsm;
	struct ftp_usr *user;
	bool login;
} ftp_cli_t;

typedef struct ftp_srv {
	char const *root;
	fd_set *rfds;
	struct ftp_usr *users;
	int socket;
	struct sockaddr_in addr;
	struct timeval now;
	struct ftp_cli clients[FTP_MAX_CLIENT];
} ftp_srv_t;

int ftp_srv_open(int port, char const *root,
                 fd_set *rfds, struct ftp_usr *users, ftp_srv_t *srv);

int ftp_srv_start(ftp_srv_t *srv, const fd_set *rfds, struct timeval *timeout);

#endif /* !__FTP_ */
