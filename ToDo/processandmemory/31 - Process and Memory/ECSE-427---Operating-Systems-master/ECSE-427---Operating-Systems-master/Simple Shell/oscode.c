/* 
Author: Genevieve Nantel
ID:  260481768
Class: ECSE-427 Mcgill
Date: September 30th 2015
 */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int j_index = 0;
int h_index = -1;

//define a struct for the jobs feature to "package" all job related data together
//As per a comment on the discussion board, I assume that I will only display 10 jobs and a history of the last 10 commands
struct job {      
  char* name;
  pid_t pid;
} jobs[10];

//define a struct for the history feature to "package" all history related data together
struct history {
  char* args[20];
  int bg;
} hist_cmd[10];

//get command method that reads the user's next command, and then parses it into seperte tokens that are used to fill
//the argument vector for the command to be executed
int getcmd(char *prompt, char *args[], int *background)
{
    int length, i = 0;
    char *token, *loc;
    char *line;
    size_t linecap = 0;
    printf("%s", prompt);
    length = getline(&line, &linecap, stdin);
    if (length <= 0) {
        exit(-1);
    }
    // Check if background is specified..
    if ((loc = index(line, '&')) != NULL) {
        *background = 1;
        *loc = ' ';
    } else
        *background = 0;
    while ((token = strsep(&line, " \t\n")) != NULL) {
        for (int j = 0; j < strlen(token); j++)
            if (token[j] <= 32)
                token[j] = '\0';
        if (strlen(token) > 0)
            args[i++] = token;
    }
    //set args[i] to null as it solves a memory error I was receiving
    args[i] = NULL;
    return i;
}

// built an exec function used to handle the execution of the specific commands
void exec(char* args[],int background){
        pid_t pid;
        // start to execute outside commands
        // Enter the change directory command if the user writes "cd"
        if (strcmp(args[0],"cd") == 0){
          int isDir;
          // we chdir on the second argument
          // this will change the current working directory of the calling process to the directory specified in path
          isDir = chdir(args[1]);
          //if the chdir of the second argument entered by the user does not return zero then it is not valid
          if (isDir != 0){
            printf("Error! This is not a valid directory.\n");
          }
        //if the user enters pwd then the system will print the full filename of the current working directory using getwcd
        } else if(strcmp(args[0], "pwd") == 0){
        //print the current working directory 
            printf("Current directory: %s\n", getcwd(NULL,(size_t)NULL));
        // next if the exit types exit then it will exit the shell
        } else if(strcmp(args[0], "exit") == 0){
            exit(0);
        //next, if the user enters "jobs" we will print a list of all the current jobs running in the background at any given time
        } else if(strcmp(args[0], "jobs") == 0){
            int isJob = 0;
            for (int i= 0; i <= j_index + 1; i++){
                if(jobs[i].name != NULL){
                    printf("job %d : %s\n",i, jobs[i].name);
                    isJob = 1;
                }
            }
            if (isJob != 1){
                printf("There are currently no active jobs.\n");
            } // if the user enters fg then the job is moved from the background to the foreground
        } else if(strcmp(args[0], "fg")==0){
          int isJob = 0;
          //collect desired job using strtol
          //parses the string str interpreting its content as an integral number which is returned as a long int value
          int d_job = (int) strtol(args[1], NULL, 10);
          printf("%d\n", d_job);
          for (int i= 0 ; i <= j_index + 1; i++){
            if (jobs[i].name != NULL && i == d_job){
                isJob = 1;
                printf("Job [%d] %s is moving to the foreground\n", d_job, jobs[i].name);
                //wait until the job has been moved
                waitpid(jobs[i].pid, NULL, 0);
                //free the memory 
                free(jobs[i].name);
                jobs[i].name = NULL;
                //update the jobs
                j_index--;
            }
          }
          // if there is no job for that id then print message
          if (!isJob){
            printf("No job was found.\n");
          }// next we enter the history feature if user enters types history
        } else if (strcmp(args[0], "history") == 0){
            // we first loop to in order of exectution and print it
          for(int k = h_index; k > -1; k--)         //Prints history in most recent order of execution, including the history command itself
          {
            printf("[%d] ", k);
            //we then loop through most recent order of execution for history command
            for (int j = 0; j < sizeof(hist_cmd[k].args); j++){
                //check if history is null
              if(hist_cmd[k].args[j] == NULL){
                break;
              } else {
                printf("%s ", hist_cmd[k].args[j]);
                }
            }
            printf("\n");
          }// we now enter the forking process as described in the first part of the assignment
        } else {
            //(1) fork a child process using fork()
            pid = fork();
            // if pid is 0 then it is the child
            if (pid == 0) {
                //(2) the child process will invoke execvp()
                execvp(args[0], args);
            //(3) if background == 0, the parent will wait, otherwise gets the next command... 
            } else if (pid > 0) {
                if (background == 0){
                    waitpid(0, NULL, 0);
                } else {
                    // if the job is to run in the background, we update them
                    for (int i= 0; i < 1 + j_index; i++){
                        if (jobs[i].name == NULL){
                            jobs[i].pid = pid;
                            //name of current job points to string of args[0] (current command)
                            jobs[i].name = strdup(args[0]);
                            j_index++;
                            break;
                        }
                    }
                }
            } else {
                perror("Error: Forking failed.\n");
                exit(-1);
            }
        }
    }

int main() {
    char *args[20];
    char *temp[20]; 
    int bg;
    while(1){
        bg = 0;
        int found = 0;

        int cnt = getcmd("\n>>  ", args, &bg);
        for (int i = 0; i < cnt; i++)
            printf("\nArg[%d] = %s", i, args[i]);
        if (bg)
            printf("\nBackground enabled..\n");
        else
            printf("\nBackground not enabled \n");
        printf("\n\n");

        // user enters into the history
        if (strcmp(args[0], "r") == 0) {
            // If no commands have been entered yet then notify to tell that history is empty
            if (hist_cmd[0].args[0] == NULL) {
                printf("\nError: There are currently no elements in history.\n");
                //If the user had entered a command without any second parameters
            } else if (args[1] == NULL){
                found = -1;
                // If history is not full then update it
                if (h_index <= 9){
                    h_index++;
                    // if history is not full simply copy last entered command to current history slot
                    hist_cmd[h_index].bg = hist_cmd[h_index-1].bg;
                    for (int l = 0; l < sizeof(hist_cmd[h_index-1])/2; l++){
                        if(hist_cmd[h_index-1].args[l] == NULL){
                            hist_cmd[h_index].args[l] = NULL;
                            break;
                        } else {
                            hist_cmd[h_index].args[l] = strdup(hist_cmd[h_index-1].args[l]);
                    }
                  } // if the history is full then we need to shift the commands to get most recent 10
                } else if (h_index > 9){
                    for (int j = 0; j < 9; j++){
                        hist_cmd[j].bg = hist_cmd[j+1].bg;
                        memmove(hist_cmd[j].args, hist_cmd[j+1].args, sizeof(hist_cmd[j+1].args));
                    } //set h_index to 9 to make sure history counter is at the last position
                    h_index = 9;
                }
            } else { 
                // if the user entered a second parameter after r, we  need to handle this search command for the history
                // if the history value is greater than 9 we need to set it back to 9
                if (h_index > 9){
                    h_index = 9;
                }
                // search in the history for the corresponding search command
                for(int i = h_index; i > -1; i--){
                    // if there is a match between history and user entered search command then we set found to 1
                    if(hist_cmd[i].args[0][0] == args[1][0]){
                      found = 1;
                      // if the found command had background enable then we set current one  to 1 also
                      if (hist_cmd[i].bg == 1){
                         bg = 1;
                      }// copy the found command in the temp array
                      for (int p = 0; p < sizeof(hist_cmd[i].args)/4; p++){
                        // we first verify if it is null, if so , we set temp array to null 
                        if(hist_cmd[i].args[p] == NULL){
                          temp[p] = NULL;
                          break;
                          // if it is not null them we set temp array to point tonfound command using strdup
                        } else {
                          temp[p] = strdup(hist_cmd[i].args[p]);
                        }
                      } // adjust the history counter 
                      if (h_index <= 9){
                        h_index++;
                      } //again, if history is full shift previous commands
                      if (h_index > 9){
                        for (int j = 0; j < 9; j++){
                          hist_cmd[j].bg = hist_cmd[j+1].bg;
                          memmove(hist_cmd[j].args, hist_cmd[j+1].args, sizeof(hist_cmd[j+1].args));
                        }
                        // set the history index to 9
                        h_index = 9;
                      }// check if ackground is equal to, if so set command history background to 1 also and reset bg
                      if (bg == 1){
                        hist_cmd[h_index].bg = 1;
                        bg = 0;
                      }//using the temp array, the history is updated accordingly
                      for (int l = 0; l < sizeof(temp)/2; l++){
                        if(temp[l] == NULL){
                          hist_cmd[h_index].args[l] = NULL;
                          break;
                        }else{
                          hist_cmd[h_index].args[l] = strdup(temp[l]);
                        }
                      }
                      break;
                    }
                }
            } 
            //if no match was found in the history then we print a message
            if(found == 0 || hist_cmd[0].args[0] == NULL){
                printf("Sorry, no match was found in history.\n");
              } else {// if there was a match that was found in history, then we execute that command
                exec(hist_cmd[h_index].args,hist_cmd[h_index].bg);
              } //else if the user entered a command that was not history, we update the history counter and shift if it is full
         } else {
            if (h_index <= 9){
              h_index++;
            } //once again, if the history is ful, we shift previous commands to update it
            if (h_index > 9){
              for (int i = 0; i < 9; i++){
                hist_cmd[i].bg = hist_cmd[i+1].bg;
                memmove(hist_cmd[i].args,hist_cmd[i+1].args, sizeof(hist_cmd[i+1].args));
              }
              // set history index back to 9
              h_index = 9;
            } // handle the command history background. is the background is 1 then set history command to 1 else set it to 0
            if (bg == 1){
              hist_cmd[h_index].bg = 1;
            } else {
              hist_cmd[h_index].bg = 0;
            } //copy the desired command into history
            for (int j = 0; j < sizeof(args)/4; j++){
              if(args[j] == NULL) {
                hist_cmd[h_index].args[j] = NULL;
                break;
              } else {
                hist_cmd[h_index].args[j] = strdup(args[j]);
              }
            } // execute the command by calling the custom exec command
            exec(args,bg);
          }
        // For the jobs feature, loop though the jobs list to see if it has completed its execution using waitpid and WNOHANG flag
        for (int i = 0; i < 10; i++){
            if (jobs[i].name != NULL){
                // The waitpid function is used to request status information from a child process whose process ID is pid
                // The WNOHANG flag indicates that the parent process shouldn't wait
                pid_t pidCheck = waitpid(jobs[i].pid, NULL, WNOHANG);
                if (pidCheck == 0){
                //Continue, we do nothing as the child is still running
                } else {
                    // if the job is done executing, then we free up space and decrease the index
                    jobs[i].name = NULL;
                    j_index--;
                }
            }
        }
    }
}

void freecmd() {
    //I am not quite sure what to do here but what i have built seems to be working without this. I free the memory already withing my code
}