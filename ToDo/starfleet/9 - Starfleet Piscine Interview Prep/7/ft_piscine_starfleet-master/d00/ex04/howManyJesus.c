#include "header.h"

#include <stdio.h>
//empty str!! what happens at end???

static size_t	hash(char *str, int len)
{
	int				base;
	size_t			hash;
	unsigned char	*u_str;

	u_str = (unsigned char*)str;
	base = 101;
	hash = 0;
	while (len--)
	{
		hash *= base;
		hash += *u_str;
		u_str++;
	}
	return (hash);
}
	
static size_t	roll_hash(size_t old_hash, int len, unsigned char rm, unsigned char add)
{
	size_t	new_hash;
	int 	base;

	base = 101;
	new_hash = old_hash - pow(base, len - 1) * rm;
	new_hash *= base;
	new_hash += add;
	return (new_hash);
}

int 			howManyJesus(char *bible, char *jesus)
{
	int b_len;
	int j_len;
	int	j_hash;
	int	b_hash;
	int total;
	
	b_len = strlen(bible);
	j_len = strlen(jesus);
	j_hash = hash(jesus, j_len);
	b_hash = hash(bible, j_len);
	total = 0;
	for (int i = 0; i < b_len - j_len + 1; i++)
	{	
		if (j_hash == b_hash && strncmp(bible + i, jesus, j_len) == 0)
			total++;
		b_hash = roll_hash(b_hash, j_len, bible[i], bible[i + j_len]);
	}
	return (total);
}
