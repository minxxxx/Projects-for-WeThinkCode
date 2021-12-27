/*
Genevieve Nantel
ID: 260481768
ECSE 427, Mini_A2
October 19th 2015
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <semaphore.h> 
#include <sys/shm.h>
#include <sys/types.h> 
#include <sys/stat.h>
#include <sys/mman.h> 
#include <fcntl.h>

//define the size of the buffer to 3. As mentionned in the discussion board, 
//we are allowed to have our buffer fixed sized. 
//As in the event trace of the assignment handout, the buffer goes from 0 to 2
// I therefore set the buffer fixed size to 3
#define BUFFER_SIZE 3
//SHM mode, set to 0666 as mentioned in the book
#define SHM_MODE ((mode_t)0666)

// struct to hold the information of the printing job
// the job will only hold information about the client_id id and the nbr_pages to print
typedef struct {
    // client_id identifier
    int client_id;
    // nbr_pages to print
    int nbr_pages;
} jobber;
// struct to store job BUFER and semaphores for synchronization
typedef struct{   
    jobber curr_jobs_buff[BUFFER_SIZE];
    sem_t mutex, full, empty;
} MEM;

//entering main client function
int main(int argc, char **argv){
    // file name for shared memory
	const char *name = "/OSa2ttppllttM";
    //define a pointer pointing to the shared memory MEM
    MEM* shared_mem_ptr;
    // deffine a job request
    jobber job_req;

    //shared memory file descriptor
    int shm_fd;
    int bufferIndex = 0;
    // initialize n to 3 which represents the number of empty slots
    int n = 3;
    //  if argc is not equal to three, then the user did not enter the command properly
    // either the user has inputted to many or too few commands
    // should be ./nameoffile client_id# page# (./name 1 2)
    if(argc != 3){
        printf("%d\n", argc);
        fprintf(stderr, "You have entered an unvalid command. Please run program as : ./{name_of_file} client_id# page# \n");
    	exit(0);
    }
    // Create new shared memory object
    //If successful, it will return a non-negative value, else it will fail with a negative value.
    shm_fd = shm_open(name, O_RDWR, SHM_MODE);

    //If shm_open failed, it will return -1. Here we verify if it failed and we notify the user. 
    printf("My file descriptor value is %d\n", shm_fd);
    if (shm_fd == -1){
        printf("The shared memory access (shm_open) failed.\n");
        exit(1);
    }
    //memory map the shared memory object
    shared_mem_ptr = (MEM *) mmap(0, sizeof(MEM), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

    //Check if the memory mapping failed and notify the user
    printf("My file shared_mem_ptr is %d\n", shared_mem_ptr);
    if ((shared_mem_ptr == MAP_FAILED) || (shared_mem_ptr == -1) ){
        printf("Shared memory pointer mapping failed.\n");
        exit(1);
    }

    // set the client_id id for the job request to be the first argument entered by
    // the user(after ./filename) which represents the client_id
    job_req.client_id = atoi(argv[1]);
    // set the number of nbr_pages for the job request to be the second argument entered by
    // the user(after ./filename) which represents the number of nbr_pages
    job_req.nbr_pages = atoi(argv[2]);

    // Wait for a free spot. NoTe that this is the semaphore down operation
    sem_wait(&shared_mem_ptr->empty); 
    // Wait for the control of memory
    sem_wait(&shared_mem_ptr->mutex);
    // Places the current value of the empty semaphore into the integer pointed to by number of empty slots
    sem_getvalue(&shared_mem_ptr->empty, &n);
    // If there are no empty slots available, then the user is notified
    if (n == 0){
    	printf("No space available for now. Client %d sleeps\n", job_req.client_id);

    }
    // assuming a circular buffer, while cliend id and number of pages is not null then we increment index of the buffer
    while ((shared_mem_ptr->curr_jobs_buff[bufferIndex].client_id) != NULL && (shared_mem_ptr->curr_jobs_buff[bufferIndex].nbr_pages) != NULL){
            bufferIndex++;
            // to make sure there is no buffer overflow, the buffer index is set back to zero  if the index is bigger than the size of the buffer
            if (bufferIndex >= BUFFER_SIZE){
                bufferIndex = 0;
            }
    }
    // insert the job request in the buffer where there is an empty spot
    shared_mem_ptr->curr_jobs_buff[bufferIndex] = job_req;

    printf("Client %d has %d pages to print, puts request in Buffer[%d]\n", job_req.client_id, job_req.nbr_pages, bufferIndex);
    // mutex up operation
    sem_post(&shared_mem_ptr->mutex);
    // semaphore up operation
    sem_post(&shared_mem_ptr->full);
    // release the shared memory
    shmdt(&shared_mem_ptr);
}