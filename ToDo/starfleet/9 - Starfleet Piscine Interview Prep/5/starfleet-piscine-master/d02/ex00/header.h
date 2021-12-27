#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>

/*--------------------------------
  !! required structure
  --------------------------------*/
	struct s_stone {
		int size;
		struct s_stone *next;
	};

	struct s_list {
		int size;
		int	amount;
		struct s_list *next;
	};

/*--------------------------------
  :) function you must implement
  --------------------------------*/
//stone is a pointer to the first
void sortStones(struct s_stone **stone);


/*--------------------------------
  ?? test function used in main
  --------------------------------*/
struct s_stone *genRandomStoneList(int n);
void printStone(struct s_stone *stone);
struct s_stone *createStone(int size);
void exitWithMsg(char *msg);


/*--------------------------------
  &  your own other function
  --------------------------------*/

void	swapStones(int *a1, int *b1, int *a2, int *b2);

#endif