/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 15:27:58 by jcamhi            #+#    #+#             */
/*   Updated: 2017/08/30 15:30:11 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

static char	*get_cwd_in_str(const char *str)
{
	int	i;
	int	len;

	i = 0;
	while (str[i] != '\"' && str[i])
		i++;
	if (!str[i])
		return (NULL);
	i++;
	len = 0;
	while (str[i + len] != '\"' && str[i + len])
		len++;
	return (ft_strsub(str, i, len));
}

void		func_pwd(t_data *data)
{
	char		*send;
	t_answer	answer;
	char		*cwd;

	send = build_request(NAME_RFC_PWD, "");
	write(data->socket, send, ft_strlen(send));
	free(send);
	answer = get_answer(data);
	if (answer.error <= 0)
		error_connection(data);
	if (answer.code == 257)
	{
		cwd = get_cwd_in_str(answer.commentaire);
		ft_printf("Remote directory: %s\n", cwd);
		free(cwd);
	}
	else
	{
		if (answer.code == 530)
			data->error = 1;
		ft_printf("%s\n", answer.str);
		data->error = 1;
	}
	free_answer(answer);
}
