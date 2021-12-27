/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findPalindrome.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 07:29:03 by amontano          #+#    #+#             */
/*   Updated: 2019/01/16 07:29:05 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int isPalindrome(char *l, char *r, int status)
{
    if (!status) return (status);
    l = (*l < 0) ? l + 1 : l;
    r = (*r < 0) ? r - 1 : r;
    if (l <= r) {
        status &= (*l == *r);
        isPalindrome(l + 1, r - 1, status);
    }
    return (status);
}

char *build_palindrome(char *seqence)
{

}

char *findPalindrome(char *sequence, int nDelete)
{
    char *left  = &sequence[0];
    char *right = &sequence[strlen(sequence) - 1];
    
    while (nDelete)
    {
        
        if (isPalindrome(left, right, 1))
            return (build_palindrome(sequence));
    }
}