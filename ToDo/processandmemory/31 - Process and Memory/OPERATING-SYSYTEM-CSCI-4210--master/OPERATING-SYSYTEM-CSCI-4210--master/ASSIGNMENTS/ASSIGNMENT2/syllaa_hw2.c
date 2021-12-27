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

typedef enum { false, true } bool;

struct Point
{
   int x, y;
}; 

/*--------FUNCTION PROTOTYPES-----------------------------------------------*/
int solveKT(int rows, int cols, int dx, int dy,
			 int nLV, int*** matrix,int parent_pid );

bool cellSafe(int x, int y, int rows, int cols, int*** matrix);
void printBoard(int rows, int cols, int***matrix);




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

	if(argc!= 3) //Check for valid command line argument.
	{
		fprintf(stderr, "ERROR: Invalid argument(s)\nUSAGE: a.out <m> <n>");
		exit(EXIT_FAILURE);
	}
	//Make sure the user doesn't input a non_integer for rows
	for(int i=0; argv[1][i] != '\0'; i++){
		if(isdigit(argv[1][i])==0){
			fprintf(stderr, "ERROR: Invalid argument(s)\nUSAGE: a.out <m> <n>");
			exit(EXIT_FAILURE);
		}
	}
	//make sure the user doesn't input a non_integer for column
	for(int i=0; argv[2][i] != '\0'; i++){ 
		if(isdigit(argv[2][i])==0){
			fprintf(stderr, "ERROR: Invalid argument(s)\nUSAGE: a.out <m> <n>");
			exit(EXIT_FAILURE);
		}
	}
	int rows = atoi(argv[1]); //convert the row the user input in integer
	int cols = atoi(argv[2]); //convert the column the user input in integer
	if(rows <=2 || cols <=2 ){//Make sure both row and col are bigger than 2
		fprintf(stderr, "ERROR: Invalid argument(s)\nUSAGE: a.out <m> <n>");
		exit(EXIT_FAILURE);
	}
	/////////////////////End of Command line Error Handling////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////

	/* Create a pipe array, store the parent PID, and evaluate the expression */
	
	int parent_pid = getpid();
	printf("PID %d: Solving the knight's tour problem for a %dx%d board\n",
			 parent_pid, rows, cols);
	fflush(stdout);
	int numLocationVisited = 1; 
	int** matrix;
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

	int max_solution = solveKT(rows, cols, 0,0,numLocationVisited, &matrix, parent_pid);

	printf("PID %d: Best solution found visits %d squares (out of %d)\n",
			parent_pid, max_solution, rows*cols);
	fflush(stdout);
	//Free the dynamically allocated matrix
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
			int dx, int dy, int nLV, int*** matrix,int parent_pid ){


	
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
   	int children;

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

    	printf("PID %d: Dead end after move #%d\n", getpid(), nLV);
    	fflush(stdout);
    	printf("PID %d: Sent %d on pipe to parent\n", getpid(), nLV);
    	fflush(stdout);
    	#ifdef DISPLAY_BOARD
    	printBoard(rows, cols, matrix);
    	#endif /* DISPLAY_BOARD */
    	return nLV;
    }

    /*
    	check for one chil cell
    */
    if(curr_index == 1){
    	return solveKT(rows, cols, validCells[0].x, validCells[0].y, nLV+1, matrix, parent_pid);
    	
    }

    /*
    	Check for multiple childre
    */
    if(curr_index >= 2){
    	printf("PID %d: %d moves possible after move #%d\n", getpid(), curr_index, nLV);
    	fflush(stdout);


		#ifdef DISPLAY_BOARD
    	printBoard(rows, cols, matrix);
    	#endif /* DISPLAY_BOARD */
    	int p[2];
    	int piping = pipe(p);// the argument p will be filled in with specific descriptors
    	int temp = 0;

    	if(piping == -1){
    		perror("pipe() failed\n");
    		return EXIT_FAILURE;
    	}

		for(int i=0; i < curr_index; i++)
		{
			pid_t pid = fork();
			//check for errors
			if(pid < 0)
			{
				perror( "fork() failed\n" );
				return EXIT_FAILURE;
			}

			if ( pid == 0 )
			{
				int rc = solveKT(rows, cols, validCells[i].x ,validCells[i].y, nLV+1 , matrix, parent_pid);
				// Write data to the pipe
				
				write (p[1], &rc, 1 );
				
				exit(0); /* return rc; */
			}

			/* Read from the pipe*/
			int buffer;
			
			read(p[0], &buffer, 1);

			printf("PID %d: Received %d from child\n", getpid(), buffer );
			fflush(stdout);
			if (temp < buffer){
				temp =  buffer;
			}


		}

		#ifdef NO_PARALLEL
    		wait(NULL);
    		if(parent_pid != getpid()){
				printf("PID %d: All child processes terminated; sent %d on pipe to parent\n",
					getpid(), temp);
				fflush(stdout);
		    }
		
		return temp;
    	#endif

		children = curr_index;
		while(children > 0){
			children--;

			int status; //return status for each child process
			
				/*Wait until a child process extis */
			wait(&status); /* BLOCK */

			if(WIFSIGNALED(status)){
				printf( "abnormally\n"); /*core dump or kill */
				fflush(stdout);
			}
			else if( WIFEXITED(status)){
				WEXITSTATUS (status);
			}
		}

		if(parent_pid != getpid()){
			printf("PID %d: All child processes terminated; sent %d on pipe to parent\n",
				getpid(), temp);
			fflush(stdout);
		}
		
		return temp;
    }

	return nLV;
}

void printBoard(int rows, int cols, int***matrix){
	for(int i=0; i < rows; i++){
		printf("PID %d:   ",getpid());
	
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