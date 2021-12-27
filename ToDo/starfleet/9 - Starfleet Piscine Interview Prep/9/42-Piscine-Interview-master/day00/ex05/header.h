#ifndef HEADER_H
# define HEADER_H

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
# include <limits.h>
# define BUFF_SIZE 256


/*--------------------------------
  !! required structure
  --------------------------------*/

struct s_item {
  char          	*key;
  int				value;
  struct s_item 	*next;
};

struct s_dict {
  struct s_item **items;
  int           capacity; //the capacity of the array 'items'
};


/*--------------------------------
  :) function you must implement
  --------------------------------*/

// DICTIONNARY

size_t hash(char *input, size_t len); //return hash result

struct s_dict *dictInit(int capacity); //initialize the dictionnary, given as parameter the capacity of the array.
int	dictInsert(struct s_dict *dict, char *key, int value); //add one item in the dictionnary, if FAIL return 0, otherwise 1
int	dictSearch(struct s_dict *dict, char *key); //find one element in the dictionnary, if not found, return -1

// OTHER

char *compress(char *book, struct s_dict *dict);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/

char *readBookFile(void);
void readWordsFile(char ***pWords, int *pLenWords);

/*--------------------------------
  &  your own other function
  --------------------------------*/

typedef struct s_dict t_dict;
typedef struct s_item t_item;

#endif
