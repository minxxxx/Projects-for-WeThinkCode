/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2018/01/06 11:10:01 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ush/exp.h"

char		*g_ifs;
char		g_ifsw[4];

static void	expifs(void)
{
	char *ifsch;
	char *whch;
	char *runp;

	if (!(g_ifs = getenv("IFS")))
		g_ifs = ft_strcpy(g_ifsw, " \t\n");
	else
	{
		ft_bzero(g_ifsw, 4);
		ifsch = g_ifs;
		whch = g_ifsw;
		while (*ifsch)
		{
			if (*ifsch == ' ' || *ifsch == '\t' || *ifsch == '\n')
			{
				runp = g_ifsw;
				while (runp < whch && *runp != *ifsch)
					++runp;
				if (runp == whch)
					*whch++ = *ifsch;
			}
			++ifsch;
		}
		*whch = '\0';
	}
}

static int	exploop1(t_sds *word, char **words, t_vec *av)
{
	if (**words == '\\')
		sh_expbackslash(word, words, 0);
	else if (**words == '$')
		sh_expdollars(word, words, av, 0);
	else if (**words == '`')
	{
		++*words;
		sh_expbacktick(word, words, av);
	}
	else if (**words == '"' && ++*words)
	{
		sh_expdquote(word, words, av);
		if (av && !word->len)
			*(char **)ft_vecpush(av) = ft_strdup("");
	}
	else if (**words == '\'')
	{
		++*words;
		sh_expsquote(word, words);
		if (av && !word->len)
			*(char **)ft_vecpush(av) = ft_strdup("");
	}
	else
		return (YEP);
	return (NOP);
}

int			sh_exp(char **words, t_sds *word, t_vec *av)
{
	--*words;
	while (*++*words)
		if (exploop1(word, words, av))
			continue ;
		else if (**words == '~')
			sh_exptilde(word, words, av ? av->len : 0);
		else if (**words == '{')
			sh_expbrace(word, words, av);
		else if (ft_strchr("*[?", **words))
			sh_expglob(word, words, av);
		else if (ft_strchr(" \t", **words) && av)
		{
			*(char **)ft_vecpush(av) = ft_strdup(word->len ? word->buf : "");
			word->len = 0;
		}
		else
			*ft_sdspush(word) = **words;
	return (YEP);
}

int			sh_expwords(t_vec *av, char const *src, size_t n)
{
	t_sds	word;
	char	*words;
	char	*sv;
	int		st;

	words = ft_malloc(n + 1);
	ft_bzero(words, n + 1);
	sv = ft_strncpy(words, src, n);
	expifs();
	ft_sdsctor(&word);
	st = sh_exp(&words, &word, av);
	if (word.len)
		*(char **)ft_vecpush(av) = word.buf;
	else
		ft_sdsdtor(&word);
	free(sv);
	return (st);
}

int			sh_expword(t_sds *word, char const *src, size_t n)
{
	char	*words;
	char	*sv;
	int		st;

	words = ft_malloc(n + 1);
	ft_bzero(words, n + 1);
	sv = ft_strncpy(words, src, n);
	expifs();
	st = sh_exp(&words, word, NULL);
	free(sv);
	return (st);
}
