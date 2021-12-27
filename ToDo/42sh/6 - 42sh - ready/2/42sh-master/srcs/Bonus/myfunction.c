/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myfunction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadenho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 18:43:55 by jbadenho          #+#    #+#             */
/*   Updated: 2017/11/24 02:47:54 by jbadenho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shell.h"
#define FIND split[(ft_arraylen(split) - 1)]
#define ONE if (split[0] != NULL)ft_delarray(split)
#define VAR t_autoc	this;char buff[4094];char *temp;char **split
#define TWO temp = ft_strjoin(tofind, "    ");split = ft_set_heredoc_arr()
#define O ft_strdel(&(split[ft_arraylen(split) - 1]))
#define N split[ft_arraylen(split)] = ft_strdup(this.dptr->d_name)
#define E O; N;	temp = ft_joinarr(split);ft_delarray(split);return (temp)
#define F if (NULL == this.dp)return (NULL)
#define CR if(NULL == this.curr_dir)return (NULL)
#define P CR;this.dp = opendir((const char*)this.curr_dir);F
#define VART char *temp;int len;int	i;int n
#define V ft_delarray(split);temp = ft_strdup(this.dptr->d_name);return (temp)
#define LL TWO; ONE
#define SPLT split[0] != NULL

static int		ft_ft_putchar(int c)
{
	return (write(1, &c, 1));
}

void			ft_tabbing(t_all *a)
{
	int		tmp;
	char	*temp;

	temp = findfile(a->c);
	tmp = ft_strlen(a->c);
	ft_strdel(&a->c);
	a->c = ft_strdup(temp);
	ft_strdel(&temp);
	ft_putstr("\r");
	tputs(tgetstr("dl", 0), 1, ft_ft_putchar);
	ft_print_dir();
	ft_putstr_fd(a->c, 0);
	a->i += ft_strlen(a->c) - tmp;
}

char			*ft_joinarr(char **array)
{
	VART;
	i = -1;
	len = 0;
	while (array[++i])
		len = len + ft_strlen(array[i]);
	len += ft_arraylen(array) - 1;
	temp = (char *)malloc(sizeof(char) * (len + 1));
	i = -1;
	len = 0;
	while (array[++i])
	{
		n = -1;
		while (array[i][++n])
		{
			temp[len] = array[i][n];
			len++;
		}
		temp[len] = ' ';
		len++;
	}
	temp[len] = '\0';
	return (temp);
}

char			*findfile(char *tofind)
{
	VAR;
	if (ft_strstr(tofind, " ") != NULL)
		split = ft_strsplit(tofind, ' ');
	else
		split = ft_set_heredoc_arr();
	this.curr_dir = getcwd(buff, 4094);
	P;
	while ((this.dptr = readdir(this.dp)) != NULL)
	{
		if (split[0] == NULL)
		{
			if ((ft_strncmp(this.dptr->d_name, tofind, ft_strlen(tofind)) == 0))
			{
				V;
			}
		}
		if (SPLT && (ft_strncmp(this.dptr->d_name, FIND, ft_strlen(FIND)) == 0))
		{
			E;
		}
	}
	LL;
	return (temp);
}
