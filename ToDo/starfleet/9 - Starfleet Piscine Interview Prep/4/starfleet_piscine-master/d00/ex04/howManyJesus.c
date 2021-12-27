#include <string.h> //memcpy, strlen, ...

int hash(char *str, int size)
{
	int value = 0;
	for(int i = 0; i < size; i++)
		value+=str[i];
	return value;
}


int howManyJesus(char *bible, char *jesus)
{
	int count = 0;
	int pattern_len = strlen(jesus);
	int len = (int)strlen(bible);
	int goal_hash = hash(jesus, pattern_len);
	int roll_hash = hash(bible, pattern_len);
	for(int i = 0; i <  len - pattern_len; i++)
	{
		if (roll_hash == goal_hash && !strncmp(bible + i, jesus, pattern_len))
			count++;
		roll_hash -= bible[i];
		roll_hash += bible[i + pattern_len];
	}
	return count;
}