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
typedef struct {
    jobber curr_jobs_buff[BUFFER_SIZE];
    sem_t mutex, full, empty;
} MEM;

// Entering main server function
int main(void) {
    // file name for shared memory
    const char *name = "/OSa2ttppllttM";

    // shared memory file descriptor
    int shm_fd;
    // initialize the client_id, the number of pages and the index of the buffer to zero
    int client_id = 0;
    int nbr_pages = 0;
    int bufferIndex = 0;
    //define a pointer pointing to the shared memory MEM
    MEM *shared_mem_ptr;

    // Setup shared memory by opening new memory segment
    shm_fd = shm_open(name, O_CREAT | O_RDWR, SHM_MODE);

    //If shm_open failed, it will return -1. Here we verify if it failed and we notify the user.
    printf("My file descriptor value is %d\n", shm_fd);
    if (shm_fd == -1){
        shm_unlink(name);
        printf("The shared memory access (shm_open) failed.\n");
        exit(1);
    }
    // Attach shared memory
    shared_mem_ptr = (MEM *) mmap(0, sizeof(MEM), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

    // configure the size of the shared memory object
    ftruncate(shm_fd, sizeof(MEM)); 

    //Check if the memory mapping failed and notify the user
    printf("My file shared_mem_ptr is %d\n", shared_mem_ptr);
    if ((shared_mem_ptr == MAP_FAILED) || (shared_mem_ptr == -1) ){
        printf("Shared memory pointer mapping failed.\n");
        exit(1);
    }    

    // Initialize the shared memory values fo the client id and the number of pages to null
     for (int i = 0; i < BUFFER_SIZE; i++) {
        shared_mem_ptr->curr_jobs_buff[i].client_id = NULL;
        shared_mem_ptr->curr_jobs_buff[i].nbr_pages = NULL;
     }

    // Here we initialize the semaphores: 
    // The second flag is set to 1 which means that it is using named semaphores as opposed to unnamed
    // the buffer is full when the last int value is 0, empty when last int is equal to the buffer size and it is w mutex when 1
    sem_init(&shared_mem_ptr->mutex, 1, 1);
    sem_init(&shared_mem_ptr->full, 1, 0);
    sem_init(&shared_mem_ptr->empty, 1, BUFFER_SIZE);

    printf("Server on !\n");
    
    int n;
    // continuously run the server 
    while (1){

        // Wait for a job to enter the queue, this is the  Semaphore down operation
        sem_wait(&shared_mem_ptr->full);

        // Wait for memory control this is the semaphore for mutual exclusion
        sem_wait(&shared_mem_ptr->mutex);

        // Places the current value of the full semaphore into the integer pointed to by number of empty slots
        sem_getvalue(&shared_mem_ptr->full, &n);
        // if n is equal to zero then there are no current jobs to print.
        if (n == 0) {
            printf("No jobs were requested.The server sleeps\n");
        }

        // assuming a circular buffer, while cliend id and number of pages is not null then we increment index of the buffer
        while ((shared_mem_ptr->curr_jobs_buff[bufferIndex].client_id) == NULL || (shared_mem_ptr->curr_jobs_buff[bufferIndex].nbr_pages) == NULL){
                bufferIndex++;
                // to make sure there is no buffer overflow, the buffer index is set back to zero  if the index is bigger than the size of the buffer
                if (bufferIndex >= BUFFER_SIZE) {
                    bufferIndex = 0;
                }
        }

        // Set the client id to be equal to the client id in the shared mem job buffer
        client_id = shared_mem_ptr->curr_jobs_buff[bufferIndex].client_id;
        // Set the number of pages to be equal to the number of pages in the shared mem job buffer
        nbr_pages = shared_mem_ptr->curr_jobs_buff[bufferIndex].nbr_pages;
        //Clear the values (set them to null) now that the values have been used
        shared_mem_ptr->curr_jobs_buff[bufferIndex].client_id = NULL;
        shared_mem_ptr->curr_jobs_buff[bufferIndex].nbr_pages = NULL;

        // mutex up operation
        sem_post(&shared_mem_ptr->mutex);
        // semaphore up opreation
        sem_post(&shared_mem_ptr->empty);

        printf("Printing %d pages from Client %d, from Buffer[%d].\n", nbr_pages, client_id, bufferIndex);
        sleep(nbr_pages);

        // Increment buffer for to next round, to check in next buffer index
        bufferIndex++;
        //again, to make sure there is no buffer overflow, the buffer index is set back to zero  if the index is bigger than the size of the buffer
        if (bufferIndex >= BUFFER_SIZE){
            bufferIndex = 0;
        }
    } 
    // destroy  semaphore mutex, empty and full and unlink
    // I also destroy shared memory using ipcrm to be sure
     sem_destroy(&shared_mem_ptr->mutex);
     sem_destroy(&shared_mem_ptr->full);
     sem_destroy(&shared_mem_ptr->empty);
     shm_unlink(name);
}
