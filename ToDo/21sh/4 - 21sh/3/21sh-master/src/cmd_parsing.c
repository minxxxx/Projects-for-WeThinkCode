/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 14:13:19 by fkoehler          #+#    #+#             */
/*   Updated: 2016/09/21 17:23:00 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	check_input_form(t_shell *shell)
{
	char			c;
	t_input			*tmp;

	c = 0;
	if (shell->input_save)
	{
		shell->input_len += lst_len(shell->input_save);
		tmp = get_last_elem(shell->input_save);
		tmp->next = shell->input;
		if (shell->input)
			shell->input->prev = tmp;
		shell->input = shell->input_save;
	}
	if ((c = valid_input(shell->input, c)) > 0)
	{
		c == '\\' ? delete_input(&(shell->input), shell->curs_pos, shell, 0)
		: store_input(shell, '\n');
		shell->input_save = shell->input;
		shell->input = NULL;
		shell->input_len = 0;
		shell->curs_pos = NULL;
	}
	else
		shell->input_save = NULL;
	return ((int)c);
}

char		**parse_cmd(t_btree *link)
{
	int		i;
	char	*tmp;
	char	**cmd_tab;

	i = 0;
	if ((strchr_redir(link)) == -1)
		return (NULL);
	tmp = remove_cmd_redir(ft_strtrim(link->str), link->redir);
	free(link->str);
	link->str = tmp;
	cmd_tab = strsplit_args(link->str);
	if (!cmd_tab[0])
	{
		free_tab(cmd_tab);
		return (NULL);
	}
	while (cmd_tab[i])
	{
		cmd_tab[i] = interpret_cmd_arg(cmd_tab[i]);
		i++;
	}
	return (cmd_tab);
}

static int	free_and_return(t_shell *shell, int ret, char *s)
{
	if (ret == 0)
		free_tmp_inputs(shell, 1);
	else
		free_tmp_inputs(shell, 0);
	if (s)
		free(s);
	return (ret);
}

int			handle_input(t_shell *shell)
{
	int		ret;
	char	*cmd_str;

	ret = 0;
	cmd_str = NULL;
	move_line_end(shell);
	tputs(tgetstr("do", NULL), shell->fd[3], &putchar);
	if (!shell->input && !shell->input_save)
		return (0);
	if ((check_pipes(shell->input, 1) == -1) && cmd_error(0, '|', NULL))
		return (free_and_return(shell, ret, cmd_str));
	if (((ret = check_input_form(shell)) > 0) ||
		(ft_str_isempty(cmd_str = lst_to_str(shell->input))))
		return (free_and_return(shell, ret, cmd_str));
	shell->hist = store_hist(shell);
	shell->tree = store_cmd(cmd_str);
	free_tmp_inputs(shell, 1);
	restore_term(shell);
	signal(SIGTSTP, SIG_DFL);
	handle_btree(shell, shell->tree);
	free_btree(shell->tree);
	shell->tree = NULL;
	reload_term(shell);
	signal(SIGTSTP, &sig_handler);
	return (ret);
}
