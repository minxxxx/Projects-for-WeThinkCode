/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_aggr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:34:14 by jcamhi            #+#    #+#             */
/*   Updated: 2016/09/01 17:34:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh21.h>

static void	aggr_without_number_before(t_aggr *aggr, char *str, size_t *i)
{
	aggr->chevron = str[*i];
	(*i) += 2;
	if (str[*i] == '-')
		aggr->apres = -2;
	else
		aggr->apres = ft_atoi(str + *i);
	while (ft_isdigit(str[*i]) || str[*i] == '-')
		(*i)++;
}

static void	aggr_with_number_before(t_aggr *aggr, char *str, size_t *i)
{
	aggr->avant = str[*i] - '0';
	aggr->chevron = str[*i + 1];
	(*i) += 3;
	if (str[*i] == '-')
		aggr->apres = -2;
	else
		aggr->apres = ft_atoi(str + *i);
	while (ft_isdigit(str[*i]) || str[*i] == '-')
		(*i)++;
}

static int	find_av_ap_chev(t_aggr *aggr, char *str, size_t *i, int jump)
{
	size_t tmp;

	tmp = *i;
	if ((str[*i] == '>' || str[*i] == '<') && str[*i + 1] == '&'
		&& (ft_isdigit(str[*i + 2]) || str[*i + 2] == '-'))
	{
		aggr_without_number_before(aggr, str, i);
		if (!jump)
			*i = tmp;
	}
	else if (ft_isdigit(str[*i]) && (str[*i + 1] == '>' || str[*i + 1] == '<')
		&& str[*i + 2] == '&' && (ft_isdigit(str[*i + 3])
		|| str[*i + 3] == '-'))
	{
		aggr_with_number_before(aggr, str, i);
		if (!jump)
			*i = tmp;
	}
	else
		return (0);
	return (1);
}

static void	find_fd_av_ap(t_fd ***fd_avant, t_fd ***fd_apres,
	t_cmd *cmd, t_aggr aggr)
{
	if (aggr.avant == 0)
		*fd_avant = &(cmd->fd_in);
	else if (aggr.avant == 1)
		*fd_avant = &(cmd->fd_out);
	else if (aggr.avant == 2)
		*fd_avant = &(cmd->fd_err);
	if (aggr.apres == 0)
		*fd_apres = &(cmd->fd_in);
	else if (aggr.apres == 1)
		*fd_apres = &(cmd->fd_out);
	else
		*fd_apres = &(cmd->fd_err);
}

int			handle_aggr(size_t *i, char *str, int jump, t_cmd *cmd)
{
	t_aggr		aggr;
	t_fd		**fd_avant;
	t_fd		**fd_apres;

	aggr.avant = 1;
	if (!find_av_ap_chev(&aggr, str, i, jump))
		return (0);
	find_fd_av_ap(&fd_avant, &fd_apres, cmd, aggr);
	if (aggr.chevron == '>')
	{
		if ((*fd_apres)->fd == -1 && aggr.apres != -2)
			*fd_avant = add_fd_elem(*fd_avant,
				create_fd(dup(aggr.apres), aggr.apres));
		else if (aggr.apres != -2)
			*fd_avant = add_fd_elem(*fd_avant, copy_fd(*fd_apres));
		else
			*fd_avant = add_fd_elem(*fd_avant, create_fd(-2, -2));
	}
	else if (aggr.apres == -2)
		*fd_avant = add_fd_elem(*fd_avant, create_fd(-2, -2));
	return (1);
}
