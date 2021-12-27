/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 07:45:15 by ggroener          #+#    #+#             */
/*   Updated: 2016/05/22 15:35:07 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	size_t	len_s;

	start = 0;
	end = 0;
	if (s)
		len_s = ft_strlen(s);
	while (s && *(s + start) && (*(s + start) == ' ' || *(s + start) == '\n'\
				|| *(s + start) == '\t'))
		start++;
	while (s && end < len_s && (*(s + len_s - 1 - end) == ' '\
				|| *(s + len_s - 1 - end) == '\n'\
				|| *(s + len_s - 1 - end) == '\t'))
		end++;
	if ((int)(len_s - end - start) < 0)
		return (ft_strsub(s, start, 0));
	return (ft_strsub(s, start, len_s - end - start));
}
