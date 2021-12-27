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

#include "ftp.h"
#include "netbuf.h"
#include "fsm.h"

#include <assert.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#include <sys/time.h>
#include <ctype.h>

#define BUF_SIZE (4096)
#define SNS(s) (s),sizeof(s)-1

static char const *getcmd(unsigned const code, size_t *sz)
{
#define STR_(x) #x
#define STR(x) STR_(x)
#define CMD(C, MSG) case (C): \
	return (sz ? (*sz = sizeof(STR(C)" "MSG"\r\n")-1) : (void)0), STR(C)" "MSG"\r\n"

	switch (code) {
	CMD(200, "Command okay.");
	CMD(202, "Command not implemented, superfluous at this site.");
	CMD(211, "System status, or system help reply.");
	CMD(212, "Directory status.");
	CMD(213, "File status.");
	CMD(214, "Help message."
	         "On how to use the server or the meaning of a particular\n"
	         "non-standard command.  This reply is useful only to the\n"
	         "human user.");
	CMD(215, "NAME system type.\n"
	         "Where NAME is an official system name from the list in the\n"
	         "Assigned Numbers document.");
	CMD(220, "Service ready for new user.");
	CMD(221, "Service closing control connection.\n"
	         "Logged out if appropriate.");
	CMD(225, "Data connection open; no transfer in progress.\n");
	CMD(226, "Closing data connection.\n"
	         "Requested file action successful (for example, file\n"
	         "transfer or file abort).");
	CMD(227, "Entering Passive Mode (h1,h2,h3,h4,p1,p2).");
	CMD(230, "User logged in, proceed.");
	CMD(250, "Requested file action okay, completed.");
	CMD(257, "\"PATHNAME\" created.");
	CMD(331, "User name okay, need password.");
	CMD(332, "Need account for login.");
	CMD(350, "Requested file action pending further information.");
	CMD(421, "Service not available, closing control connection.\n"
	         "This may be a reply to any command if the service knows it\n"
	         "must shut down.");
	CMD(425, "Can't open data connection.");
	CMD(426, "Connection closed; transfer aborted.");
	CMD(450, "Requested file action not taken.\n"
	         "File unavailable (e.g., file busy).");
	CMD(451, "Requested action aborted: local error in processing.");
	CMD(452, "Requested action not taken."
	         "Insufficient storage space in system.");
	CMD(500, "Syntax error, command unrecognized."
	         "This may include errors such as command line too long.");
	CMD(501, "Syntax error in parameters or arguments.");
	CMD(502, "Command not implemented.");
	CMD(503, "Bad sequence of commands.");
	CMD(504, "Command not implemented for that parameter.");
	CMD(530, "Not logged in.");
	CMD(532, "Need account for storing files.");
	CMD(550, "Requested action not taken."
	         "File unavailable (e.g., file not found, no access).");
	CMD(551, "Requested action aborted: page type unknown.");
	CMD(552, "Requested file action aborted."
	         "Exceeded storage allocation (for current directory or"
	         "dataset).");
	CMD(553, "Requested action not taken."
	         "File name not allowed.");
	default: return NULL;
	}
}

struct netbuf
{
	char const *buf;
	uint16_t pos, size;
};

static __always_inline char const *netbuf_read(struct netbuf *buf, size_t n)
{
	if (buf->pos + n >= buf->size) return NULL;
	char const *const ret = buf->buf + buf->pos;
	buf->pos += n;
	return ret;
}

static __always_inline char const *netbuf_peek(struct netbuf *buf)
{
	if (buf->pos >= buf->size) return NULL;
	return buf->buf + buf->pos;
}

static __always_inline void cli_close(struct ftp_srv *srv, struct ftp_cli *cli)
{
	if (errno)
		fprintf(stderr, "connection error %s: %s\n",
		        inet_ntoa(cli->addr.sin_addr), strerror(errno));

	FD_CLR(cli->socket, srv->rfds);
	close(cli->socket);
	cli->socket = 0;
}

static __always_inline struct ftp_cli *cli_find(ftp_srv_t *srv, int fd)
{
	unsigned i;
	for (i = 0; i < FTP_MAX_CLIENT && srv->clients[i].socket != fd; ++i);
	return (i == FTP_MAX_CLIENT) ? NULL : srv->clients + i;
}

enum {
	E_OPEN,
	E_RECV,
	E_TIMEOUT,

	C_ERROR,
	C_WAIT,
	C_LOGIN,

	C_USER,
	C_PASS,
	C_QUIT,
	C_PORT,
	C_TYPE,
	C_MODE,
	C_STRU,
	C_RETR,
	C_STOR,
	C_NOOP,
	C_CMD_MAX,
};

enum {
	S_IDLE,
	S_WAIT_USER,
	S_WAIT_PASS,
	S_OPEN
};

#define IS_CMD(CMD) ((CMD) >= C_USER && (CMD) < C_CMD_MAX)

static int parsecmd(char const *cmd)
{
	char c[6] = { };

	for (unsigned i = 0; i < 5; ++i)
		c[i] = (char)toupper(cmd[i]);

	if (strncmp(c, SNS("USER ")) == 0) return C_USER;
	if (strncmp(c, SNS("PASS ")) == 0) return C_PASS;
	if (strncmp(c, SNS("QUIT ")) == 0) return C_QUIT;
	if (strncmp(c, SNS("PORT ")) == 0) return C_PORT;
	if (strncmp(c, SNS("TYPE ")) == 0) return C_TYPE;
	if (strncmp(c, SNS("MODE ")) == 0) return C_MODE;
	if (strncmp(c, SNS("STRU ")) == 0) return C_STRU;
	if (strncmp(c, SNS("RETR ")) == 0) return C_RETR;
	if (strncmp(c, SNS("STOR ")) == 0) return C_STOR;
	if (strncmp(c, SNS("NOOP ")) == 0) return C_NOOP;
	return C_CMD_MAX;
}

int on_open(fsm_t const *fsm, int ecode, void *arg)
{
	(void)ecode;
	(void)arg;

	struct ftp_cli *const cli = container_of(fsm, struct ftp_cli, fsm);
	return dprintf(cli->socket, "%s", getcmd(200, NULL)), 0;
}

int on_default(fsm_t const *fsm, int ecode, void *arg)
{
	(void)ecode;
	(void)arg;

	struct ftp_cli *const cli = container_of(fsm, struct ftp_cli, fsm);
	int const cmd = IS_CMD(ecode) ? 503 : 500;
	return dprintf(cli->socket, "%s", getcmd(cmd, NULL)), 0;
}

int on_recv(fsm_t const *fsm, int ecode, void *arg)
{
	(void)ecode;
	(void)fsm;
	struct netbuf *const buf = arg;

	char const *cmd = netbuf_read(buf, 5);
	if (cmd == NULL) return C_ERROR;
	return parsecmd(cmd);
}

int on_user(fsm_t const *fsm, int ecode, void *arg)
{
	(void)ecode;
	struct ftp_cli *const cli = container_of(fsm, struct ftp_cli, fsm);
	struct netbuf *const buf = arg;

	char const *username = netbuf_peek(buf);
	if (username == NULL) return C_ERROR;

	struct ftp_usr *usr;

	for (usr = cli->srv->users; usr->user; ++usr)
		if (strcmp(usr->user, username) == 0)
			break;
	if (usr->user == NULL)
		return dprintf(cli->socket, "%s", getcmd(332, NULL)), C_WAIT;
	cli->user = usr;
	if (usr->pswd != NULL)
		return dprintf(cli->socket, "%s", getcmd(331, NULL)), 0;
	cli->login = true;
	return dprintf(cli->socket, "%s", getcmd(230, NULL)), C_LOGIN;
}

int on_pass(fsm_t const *fsm, int ecode, void *arg)
{
	(void)ecode;
	struct ftp_cli *const cli = container_of(fsm, struct ftp_cli, fsm);
	struct netbuf *const buf = arg;

	char const *password = netbuf_peek(buf);
	if (password == NULL) return C_ERROR;

	if (strcmp(cli->user->pswd, password) != 0)
		return dprintf(cli->socket, "%s", getcmd(530, NULL)), C_WAIT;
	cli->login = true;
	return dprintf(cli->socket, "%s", getcmd(230, NULL)), 0;
}

static struct fsm_trans const *const stt[] = {
	[S_IDLE]      = (struct fsm_trans const[]){
		{ E_OPEN,        on_open, S_WAIT_USER },
		{ FSM_E_DEFAULT, NULL,    S_IDLE      },
	},

	[S_WAIT_USER] = (struct fsm_trans const[]){
		{ E_RECV,        on_recv,    S_WAIT_USER },
		{ C_USER,        on_user,    S_WAIT_PASS },
		{ C_WAIT,        NULL,       S_WAIT_USER },
		{ C_ERROR,       on_default, S_WAIT_USER },
		{ C_LOGIN,       NULL,       S_OPEN },
		{ FSM_E_DEFAULT, on_default, S_WAIT_USER },
	},

	[S_WAIT_PASS] = (struct fsm_trans const[]){
		{ E_RECV,        on_recv,    S_WAIT_PASS },
		{ C_PASS,        on_pass,    S_OPEN      },
		{ C_WAIT,        NULL,       S_WAIT_PASS },
		{ C_ERROR,       on_default, S_WAIT_PASS },
		{ FSM_E_DEFAULT, on_default, S_WAIT_PASS },
	},

	[S_OPEN]      = (struct fsm_trans const[]){
		{ E_RECV,        on_recv,    S_OPEN },
		{ FSM_E_DEFAULT, on_default, S_OPEN },
	},
};

int ftp_srv_open(int port, char const *root,
                 fd_set *rfds, struct ftp_usr *users, ftp_srv_t *srv)
{
	if (port <= 1024 || port > 9999)
		return (errno = EINVAL), -1;

	/* Open a network stream socket */
	int const sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0) goto abort;

	/* Faster server reload */
	if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int)))
		goto abort;

	struct sockaddr_in const addr = {
		.sin_family = AF_INET,
		.sin_port = htons((uint16_t)port),
		.sin_addr.s_addr = INADDR_ANY
	};

	/* Set socket local address */
	if (bind(sock, (struct sockaddr const *)&addr, sizeof addr))
		goto abort;

	/* Listen for up to `FTP_MAX_CLIENT` connections */
	if (listen(sock, FTP_MAX_CLIENT))
		goto abort;

	/* Everything goes well, set rfds and save data to server structure */
	FD_SET(sock, rfds);
	return (*srv = (struct ftp_srv){
		.root = root,
		.rfds = rfds, .users = users,
		.socket = sock, .addr = addr,}), 0;

abort:
	if (sock >= 0) close(sock);
	return -1;
}

int ftp_srv_start(ftp_srv_t *srv, const fd_set *rfds, struct timeval *timeout)
{
	int err = 0;

	memset(timeout, 0, sizeof *timeout);

	if (gettimeofday(&srv->now, NULL)) return -1;

	if (FD_ISSET(srv->socket, rfds)) {
		socklen_t sz = sizeof(struct sockaddr_in);
		struct sockaddr_in addr;

		int const sock = accept(srv->socket, (struct sockaddr *)&addr, &sz);
		if (sock < 0) return -1;

		struct ftp_cli *const cli = cli_find(srv, 0);
		if (cli == NULL) {
			err = dprintf(sock, "%s", getcmd(421, NULL));
			if (err < 0) return err;
		} else {
			cli->socket = sock;
			cli->addr = addr;
			cli->srv = srv;
			FD_SET(cli->socket, srv->rfds);
			fsm_init(&cli->fsm, S_IDLE, stt);
			err = fsm_trigger(&cli->fsm, E_OPEN, NULL);
			if (err) return err;
		}
	}

	struct timeval *to = NULL;

	for (struct ftp_cli *cli = srv->clients;
	     cli != srv->clients + FTP_MAX_CLIENT; ++cli) {

		if (!cli->socket)
			continue;

		if (cli->timeout.tv_sec || cli->timeout.tv_usec) {
			if (timercmp(&cli->timeout, &srv->now, >=) == 0) {
				memset(&cli->timeout, 0, sizeof cli->timeout);
				err = fsm_trigger(&cli->fsm, E_TIMEOUT, NULL);
				if (err) break;
			} else if (to == NULL || timercmp(&cli->timeout, to, <) == 0)
				to = &cli->timeout;
		}

		if (!FD_ISSET(cli->socket, rfds))
			continue;

		char data[BUF_SIZE + 1];
		ssize_t const rd = recv(cli->socket, data, sizeof data, 0);
		if (rd < 0) {
			cli_close(srv, cli);
			continue;
		}

		struct netbuf buf = {
			.buf = data,
			.size = (uint16_t)rd };

		data[rd] = '\0';
		char *cr = strchr(data, '\r');
		if (cr) *cr = 0;
		char *lf = strchr(data, '\n');
		if (lf) *lf = 0;
		err = fsm_trigger(&cli->fsm, E_RECV, &buf);
		if (err) {
			err = dprintf(cli->socket, "%s", getcmd(421, NULL));
			if (err < 0) return err;
			break;
		}
	}

	if (to) timersub(to, &srv->now, timeout);
	return err;
}
