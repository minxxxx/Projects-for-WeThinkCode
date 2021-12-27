/*
	Alseny Sylla
	RIN: 661409905
	CSCI 4210 - Homework2

	Description:
		Implementation of a multi-process solution to the classic Knight's tour problem.
		Goal: Pratice fork() and pipe() in support of interprocess communication (IPC).
		Requirement: Program must determine whether a valid solution is possible for 
					 the night tour problem on a m x m Board.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <pthread.h>

int max_squares = 0; //maximum number of squares covered
int*** dead_end_boards; //maintain a list of "dead end board"
int dead_end_boards_index =0;
int dead_end_boards_size = 2000;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;


	


typedef enum { false, true } bool;
struct Point
{
   int x, y;
}; 

/*--------FUNCTION PROTOTYPES-----------------------------------------------*/
int solveKT(int rows, int cols, int dx, int dy,
			 int nLV, int*** matrix );

bool cellSafe(int x, int y, int rows, int cols, int*** matrix);
void printBoard(int rows, int cols, int***matrix);




struct B_ARG
{
   int rows;
   int cols;
   int dx;
   int dy;
   int nlv;
   int*** matrix;

}; 

void * CallSolveKT( void* argument){
	struct B_ARG *arg = (struct B_ARG* ) argument;

	solveKT( arg->rows, arg->cols, arg->dx, arg->dy, arg->nlv, arg->matrix);

	return NULL;

}



/*--------Main Code----------------------------------------------------------*/
int main(int argc, char* argv[])
{

	///////////////////COMMAND-LINE ARGUMENTS AND ERROR HANDLING//////////////////
	///////////////////////////////////////////////////////////////////////////////

	//the program requires three commands line arguments
	/*
		1. the .out 
		2. m --> the number of rows (integer)
		3. n --> the number of columns (integer)
	*/
//-------------------------------------------------------------------------------
	if(argc < 3 || argc > 4) //Check for valid command line argument.
	{
		fprintf(stderr, "ERROR: Invalid argument(s)\nUSAGE: a.out <m> <n> [<k>]");
		exit(EXIT_FAILURE);
	}
	//Make sure the user doesn't input a non_integer for rows
	for(int i=0; argv[1][i] != '\0'; i++){
		if(isdigit(argv[1][i])==0){
			fprintf(stderr, "ERROR: Invalid argument(s)\nUSAGE: a.out <m> <n> [<k>]");
			exit(EXIT_FAILURE);
		}
	}
	//make sure the user doesn't input a non_integer for column
	for(int i=0; argv[2][i] != '\0'; i++){ 
		if(isdigit(argv[2][i])==0){
			fprintf(stderr, "ERROR: Invalid argument(s)\nUSAGE: a.out <m> <n> [<k>]");
			exit(EXIT_FAILURE);
		}
	}
	int rows = atoi(argv[1]); //convert the row the user input in integer
	int cols = atoi(argv[2]); //convert the column the user input in integer
	if(rows <=2 || cols <=2 ){//Make sure both row and col are bigger than 2
		fprintf(stderr, "ERROR: Invalid argument(s)\nUSAGE: a.out <m> <n> [<k>]");
		exit(EXIT_FAILURE);
	}

	if(argc==4){
		int given_value = atoi(argv[3]);
		if(given_value == 0 || given_value > (rows*cols)){
			fprintf(stderr, "ERROR: Invalid argument(s)\nUSAGE: a.out <m> <n> [<k>]");
			exit(EXIT_FAILURE);
		}
	}
	

	/////////////////////End of Command line Error Handling////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////

	/* Create a pipe array, store the parent PID, and evaluate the expression */
//----------------------------------------------------------------------------------
	


	
	 dead_end_boards = malloc( dead_end_boards_size* sizeof(int**));


	printf("THREAD %u: Solving the knight's tour problem for a %dx%d board\n",
			 (unsigned int)pthread_self(), rows, cols);
	fflush(stdout);
	int numLocationVisited = 1; 

	int** matrix;

//------------------Initialization of the matrix with -1 ----------------------------
	//allocation of matrix using malloc
	matrix = malloc(rows * sizeof(int*));
	for(int i =0; i < rows; i++){
		matrix[i] = malloc(cols*sizeof(int));
	}
	//store -1 in all the cells for checking the cell is not visited
	for(int i=0; i < rows; i++){
		for(int j=0; j < cols; j++){
			matrix[i][j] = -1;
		}
	}
//------------------------------------------------------------------------------------
	 solveKT(rows, cols, 0,0,numLocationVisited, &matrix );

	printf("THREAD %u: Best solution found visits %d squares (out of %d)\n",
			(unsigned int) pthread_self(), max_squares, rows*cols);
	fflush(stdout);
	//Free the dynamically allocated matrix


	if(argc==4){

		
			int given_value = atoi(argv[3]);
		
			for(unsigned int i=0; i < dead_end_boards_index; i++){
			int locationVisited =0;
			for(unsigned int r=0; r<rows; r++){
				for(unsigned int c =0; c < cols; c++){
					if(dead_end_boards[i][r][c] != -1){
						locationVisited +=1;
					}
				}
			}
			if(locationVisited >= given_value){
				printBoard(rows, cols, &dead_end_boards[i]);
			}
		}
		
		
	}
	if(argc == 3){
		for(unsigned int i=0; i < dead_end_boards_index; i++){
			printBoard(rows, cols, &dead_end_boards[i]);
		}
	}



	for(int i =0; i < rows; i++){
		free(matrix[i]);
	}
	free(matrix);

	return EXIT_SUCCESS;
}
/*---------------------END OF MAIN--------------------------------------------------*/
//////////////////////////////////////////////////////////////////////////////////////
/*
	Utility function to check x and y are valid indexes for rows*cols chessboard
*/
bool cellSafe(int x, int y, int rows, int cols, int*** matrix){
	 return ( x >= 0 && x < rows && y >= 0 && 
	 			y < cols && (*matrix)[x][y] == -1);
}
int solveKT(int rows, int cols, 
			int dx, int dy, int nLV, int*** matrix ){


	
	//Since the Knight is initially at the first block

	/* Move pattern on basis of the change of x and y
		coordinates respectively.
	   xMove[] and yMove[] define next move of Knight.
       xMove[] is for next value of x coordinate
       yMove[] is for next value of y coordinate */
    int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
    int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };

    struct Point validCells[8];
   	int curr_index = 0;
   	//int children;

    (*matrix)[dx][dy] = nLV;
    int next_x;
    int next_y;

    //Try all next moves from the current coordinate dx, dy
    for(int i=0; i < 8; i++)
    {
    	next_x = dx + xMove[i];
    	next_y = dy + yMove[i];
    	if(cellSafe(next_x, next_y, rows, cols, matrix)){
    		struct Point temp = {next_x, next_y};
    		validCells[curr_index] = temp;
    		curr_index++;
    	}
    }

    /*
    	check if the current cell is lead cell. 
    */
    if(curr_index==0){
    	pthread_mutex_lock(&mutex);

    	printf("THREAD %u: Dead end after move #%d\n", (unsigned int) pthread_self(), nLV);
    	fflush(stdout);
    	#ifdef DISPLAY_BOARD
    	printBoard(rows, cols, matrix);
    	#endif /* DISPLAY_BOARD */


    	if(nLV > max_squares){
    		max_squares = nLV;
    	 }

    	if(dead_end_boards_index == dead_end_boards_size){ //just in case the dead ends boards are fulled
    		dead_end_boards_size = dead_end_boards_size*2;
    		dead_end_boards = realloc(dead_end_boards, sizeof(int**)* dead_end_boards_size);
    	}

		dead_end_boards[dead_end_boards_index] = malloc(rows*sizeof(int*));
    	
    	for(unsigned int i =0; i < rows; i++){
			dead_end_boards[dead_end_boards_index][i] = malloc(cols*sizeof(int));
		}

		for(int i=0; i < rows; i++){
			for(int j=0; j < cols; j++){
				dead_end_boards[dead_end_boards_index][i][j] = (*matrix)[i][j];
			}
		}

		dead_end_boards_index  = dead_end_boards_index +1;
		pthread_mutex_unlock(&mutex);

    	return nLV;
    }


    /*
    	check for one chil cell
    */
    if(curr_index == 1){

    	return solveKT(rows, cols, validCells[0].x, validCells[0].y, nLV+1, matrix);
    	
    }

    /*
    	Check for multiple childre
    */
    if(curr_index >= 2){
    	printf("THREAD %u: %d moves possible after move #%d; creating threads\n", (unsigned int) pthread_self(), curr_index, nLV);
    	fflush(stdout);


		#ifdef DISPLAY_BOARD
    	printBoard(rows, cols, matrix);
    	#endif /* DISPLAY_BOARD */
    	
    	pthread_t *tid = malloc(sizeof(pthread_t)* curr_index);

    	int*** child_boards = malloc( curr_index* sizeof(int**));

    	for(unsigned int i=0; i < curr_index;i++){
    		    child_boards[i] = malloc(rows*sizeof(int*));
    		    for(unsigned int j =0; j < rows; j++){
					child_boards[i][j] = malloc(cols*sizeof(int));
				}

				for(unsigned int r =0; r < rows; r++){
					for(unsigned int c =0; c < cols; c++){
						child_boards[i][r][c]= (*matrix)[r][c];
					}
				}

    	}
 
    	struct B_ARG *children = malloc(sizeof(struct B_ARG)* curr_index);

    	//now lock the mutex
    	pthread_mutex_lock(&mutex2);
    	for(unsigned int i=0; i < curr_index; i++){
    		children[i].rows = rows;
    		children[i].cols = cols;
    		children[i].dx = validCells[i].x;
    		children[i].dy = validCells[i].y;
    		children[i].nlv = nLV+1;
    		children[i].matrix = &child_boards[i];
    		int rc = pthread_create(&tid[i], NULL, CallSolveKT, (void* ) &children[i]);

    		if(rc != 0){
    			fprintf(stderr, "Unable to create thread  %d \n",rc );
    			return EXIT_FAILURE;
    		}
	
    	}
    	pthread_mutex_unlock(&mutex2);

    		for(unsigned int i =0; i < curr_index; i++){
    			unsigned int * temp;
    			int rc = pthread_join( tid[i], (void**)&temp);

    			if(rc != 0){
    			fprintf(stderr, "Unable to join thread  %d \n",rc );
    			
    			}
    		}
    	

	 		return nLV;

		
	
    }

	return nLV;
}

void printBoard(int rows, int cols, int***matrix ){
	for(int i=0; i < rows; i++){
		if(i==0){
			printf("THREAD %u: > ",(unsigned int)pthread_self());
		}
		if(i!=0){
			printf("THREAD %u:   ",(unsigned int)pthread_self());
		}
		

	
		for(int j=0; j < cols; j++){
			if((*matrix)[i][j] == -1){
				printf(".");

			}
			else{
				printf("k");
			}
			
		}
		printf("\n");
		
	}
	fflush(stdout);
}



