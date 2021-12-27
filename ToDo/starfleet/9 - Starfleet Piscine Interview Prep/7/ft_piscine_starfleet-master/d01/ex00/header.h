#ifndef HEADER_H
# define HEADER_H

# include <math.h>
# include <stdlib.h>
# include <string.h>

/*--------------------------------
  !! required
  --------------------------------*/
# define CS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 !?:;,.$&<>()+*-_="

struct s_node {
	char c;
	struct s_node *prev;
	struct s_node *next;
};

/*--------------------------------
  :) function you must implement
  --------------------------------*/
char *precious(int *text, int size);

/*--------------------------------
  ?? test function used in main
  --------------------------------*/


/*--------------------------------
  &  your own other function
  --------------------------------*/

struct s_node *new_node(char c, struct s_node *next, struct s_node *prev);
struct s_node *create_list(char *s);

#endif
