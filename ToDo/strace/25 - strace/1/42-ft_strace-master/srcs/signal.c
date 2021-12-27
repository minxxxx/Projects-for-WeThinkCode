/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 15:35:20 by jtranchi          #+#    #+#             */
/*   Updated: 2018/08/17 15:35:21 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_strace.h"

char *get_signal_name(int key)
{
	switch (key){
		case (SIGHUP):
			return "SIGHUP";
		case (SIGINT):
			return "SIGINT";
		case (SIGQUIT):
			return "SIGQUIT";
		case (SIGILL):
			return "SIGILL";
		case (SIGTRAP):
			return "SIGTRAP";
		case (SIGABRT):
			return "SIGABRT";
		case (SIGBUS):
			return "SIGBUS";
		case (SIGFPE):
			return "SIGFPE";
		case (SIGKILL):
			return "SIGKILL";
		case (SIGUSR1):
			return "SIGUSR1";
		case (SIGSEGV):
			return "SIGSEGV";
		case (SIGUSR2):
			return "SIGUSR2";
		case (SIGPIPE):
			return "SIGPIPE";
		case (SIGALRM):
			return "SIGALRM";
		case (SIGTERM):
			return "SIGTERM";
		case (SIGCHLD):
			return "SIGCHLD";
		case (SIGCONT):
			return "SIGCONT";
		case (SIGSTOP):
			return "SIGSTOP";
		case (SIGTSTP):
			return "SIGTSTP";
		case (SIGTTIN):
			return "SIGTTIN";
		case (SIGTTOU):
			return "SIGTTOU";
		case (SIGURG):
			return "SIGURG";
		case (SIGXCPU):
			return "SIGXCPU";
		case (SIGVTALRM):
			return "SIGVTALRM";
		case (SIGPROF):
			return "SIGPROF";
		case (SIGWINCH):
			return "SIGWINCH";
		case (SIGPOLL):
			return "SIGPOLL";
		case (SIGPWR):
			return "SIGPWR";
		case (SIGSYS):
			return "SIGSYS";
		default:
			return "unknown signal";
	}
}
