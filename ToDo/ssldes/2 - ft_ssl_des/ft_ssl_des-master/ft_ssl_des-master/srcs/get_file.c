/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcamhi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:31:22 by jcamhi            #+#    #+#             */
/*   Updated: 2018/11/12 17:31:23 by jcamhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ssl.h>

static char	*in_else(char *ret, int *in_size, int r, char *buffer)
{
	char	*tmp;

	tmp = ret;
	if (!(ret = malloc(*in_size + r)))
		return (NULL);
	ft_memcpy(ret, tmp, *in_size);
	ft_memcpy(ret + *in_size, buffer, r);
	free(tmp);
	return (ret);
}

static void	end_of_func(int r, char **ret)
{
	if (r < 0)
		*ret = NULL;
	if (!*ret)
		*ret = ft_strdup("");
}

char		*get_file(int fd, int *in_size)
{
	char	buffer[4096];
	int		r;
	char	*ret;

	*in_size = 0;
	ret = NULL;
	while ((r = read(fd, buffer, 4095)) > 0)
	{
		buffer[r] = '\0';
		if (!ret)
		{
			if (!(ret = malloc(r)))
				return (NULL);
			ft_memcpy(ret, buffer, r);
		}
		else
		{
			if (!(ret = in_else(ret, in_size, r, buffer)))
				return (NULL);
		}
		*in_size += r;
	}
	end_of_func(r, &ret);
	return (ret);
}
