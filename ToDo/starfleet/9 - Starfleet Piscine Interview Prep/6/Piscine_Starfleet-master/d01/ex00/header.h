#ifndef HEADER_H
# define HEADER_H
# include <stdlib.h>
/*--------------------------------
  !! required
  --------------------------------*/


//          "00000000001111111111222222222233333333334444444444555555555566666666667777777777"
//          "01234567890123456789012345678901234567890123456789012345678901234567890123456789"
# define CS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 !?:;,.$&<>()+*-_="
# define LEN 80

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

#endif
