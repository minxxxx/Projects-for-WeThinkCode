/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_passive_mode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <jcamhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 16:08:06 by jcamhi            #+#    #+#             */
/*   Updated: 2017/08/30 16:10:19 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

static char					*find_sub(const char *str, int *error)
{
	int		i;
	int		len;
	char	*sub;

	i = 0;
	while (str[i] != '(' && str[i])
		i++;
	if (!str[i])
	{
		*error = 1;
		return (NULL);
	}
	i++;
	len = 0;
	while (str[i + len] != ')' && str[i + len])
		len++;
	sub = ft_strsub(str, i, len);
	if (!sub)
		*error = 1;
	return (sub);
}

static char					*get_ip(char **str)
{
	char	*ret;

	ret = ft_strdup(str[0]);
	ret = ft_strjoinaf1(ret, ".");
	ret = ft_strjoinaf1(ret, str[1]);
	ret = ft_strjoinaf1(ret, ".");
	ret = ft_strjoinaf1(ret, str[2]);
	ret = ft_strjoinaf1(ret, ".");
	ret = ft_strjoinaf1(ret, str[3]);
	return (ret);
}

static struct sockaddr_in	get_passive_port(t_data *data,
	const char *str, int *error, int i)
{
	char				*sub;
	char				**tab;
	char				*ip;
	struct sockaddr_in	addr;

	addr.sin_family = AF_INET;
	sub = find_sub(str, error);
	if (*error)
		return (addr);
	tab = ft_strsplit(sub, ',');
	i = 0;
	while (tab[i])
		i++;
	if (i != 6)
	{
		*error = 1;
		return (addr);
	}
	ip = get_ip(tab);
	addr.sin_addr.s_addr = inet_addr(data->machine);
	free(ip);
	addr.sin_port = htons(ft_atoi(tab[4]) * 256 + ft_atoi(tab[5]));
	free(sub);
	free_double_tab(tab);
	return (addr);
}

int							create_data_socket(struct sockaddr_in addr)
{
	struct protoent		*proto;
	int					ret;

	proto = getprotobyname("tcp");
	if (!proto)
		return (-1);
	if ((ret = socket(PF_INET, SOCK_STREAM, proto->p_proto)) == -1)
		return (-1);
	addr.sin_family = AF_INET;
	if (connect(ret,
		(struct sockaddr*)(&addr), sizeof(struct sockaddr_in)) == -1)
		return (-1);
	return (ret);
}

int							set_passive_mode(t_data *data)
{
	char				*send;
	t_answer			answer;
	struct sockaddr_in	addr;
	int					error;
	int					socket;

	send = build_request(NAME_RFC_PASSIVE, (data->cmd).cmd_tab[1]);
	write(data->socket, send, ft_strlen(send));
	free(send);
	answer = get_answer(data);
	if (answer.error <= 0)
		error_connection(data);
	ft_printf("%s\n", answer.str);
	if (answer.code / 100 > 2)
		data->error = 1;
	error = 0;
	addr = get_passive_port(data, answer.str, &error, 0);
	free_answer(answer);
	if (error || ((socket = create_data_socket(addr)) == -1))
	{
		data->error = 1;
		return (-1);
	}
	return (socket);
}
