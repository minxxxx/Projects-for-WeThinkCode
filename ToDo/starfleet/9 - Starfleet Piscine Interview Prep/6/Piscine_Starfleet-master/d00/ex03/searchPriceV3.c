/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonroe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:44:59 by smonroe           #+#    #+#             */
/*   Updated: 2019/01/07 17:39:51 by smonroe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t hash(char *input)
{

} //return hash result

struct s_dict *dictInit(int capacity)
{

} //initialize the dictionary.

int	dictInsert(struct s_dict *dict, char *key, struct s_art *value)
{

} //add element in dict, if FAIL return 0, otherwise 1

struct s_art *dictSearch(struct s_dict *dict, char *key)
{

} //find element in dict, if not found, return NULL

int searchPrice(struct s_dict *dict, char *name)
{

}
