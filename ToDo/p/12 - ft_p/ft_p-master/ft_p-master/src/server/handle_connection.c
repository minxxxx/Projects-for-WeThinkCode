/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_connection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 13:04:38 by jcamhi            #+#    #+#             */
/*   Updated: 2017/08/31 13:04:39 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

static void	init_tab(t_command_func *tab)
{
	tab[VALUE_USER] = &func_user;
	tab[VALUE_PASS] = &func_pass;
	tab[VALUE_SYST] = &func_syst;
	tab[VALUE_FEAT] = &func_feat;
	tab[VALUE_CWD] = &func_cwd;
	tab[VALUE_PWD] = &func_pwd;
	tab[VALUE_CDUP] = &func_cdup;
	tab[VALUE_PASV] = &func_pasv;
	tab[VALUE_LIST] = &func_list;
	tab[VALUE_TYPE] = &func_type;
	tab[VALUE_SIZE] = &func_size;
	tab[VALUE_MDTM] = &func_mdtm;
	tab[VALUE_RETR] = &func_retr;
	tab[VALUE_STOR] = &func_stor;
	tab[VALUE_QUIT] = &func_quit;
}

static void	call_good_func(t_data *data)
{
	t_command_func	*tab;
	t_command		cmd;

	tab = data->tab;
	cmd = parse_cmd(data->str, data);
	if (cmd.nbr_commande == -1 || data->error)
	{
		data->return_code = 500;
		data->commentaire = " Command unkown";
		return ;
	}
	data->cmd = &cmd;
	tab[cmd.nbr_commande](data);
}

static void	init_data(t_data *data, t_command_func tab[50], int cs)
{
	data->tab = tab;
	data->usr = NULL;
	data->logged_in = 0;
	data->free_commentaire = 0;
	data->pi_socket = cs;
	data->type = TYPE_BINARY;
}

static void	reinit_data(t_data *data, char *str)
{
	if (data->free_commentaire)
		free(data->commentaire);
	data->free_commentaire = 0;
	data->str = str;
	data->error = 0;
	data->return_code = 220;
	data->commentaire = NULL;
}

void		handle_connection(int cs, t_data *data)
{
	char				*str;
	t_command_func		tab[50];
	socklen_t			len;
	struct sockaddr_in	addr;

	len = sizeof(struct sockaddr_in);
	getsockname(cs, (struct sockaddr*)(&addr), &len);
	data->local_addr = addr.sin_addr;
	data->data_connection_on = 0;
	init_tab(tab);
	ft_putstr_fd("220 (ft_p 0.1)\r\n", cs);
	init_data(data, tab, cs);
	while (get_next_line(cs, &str) > 0)
	{
		remove_cr(str);
		reinit_data(data, str);
		call_good_func(data);
		ft_putnbr_fd(data->return_code, cs);
		if (data->commentaire)
			ft_putstr_fd(data->commentaire, cs);
		ft_putstr_fd("\r\n", cs);
	}
	close(cs);
}
