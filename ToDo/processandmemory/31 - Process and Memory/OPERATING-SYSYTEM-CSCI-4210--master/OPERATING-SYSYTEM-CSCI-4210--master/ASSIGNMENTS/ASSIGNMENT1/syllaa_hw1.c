#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

void scanfile(FILE *fp, char*** words, int** count, int* size, int* current_index, int* read);
void condense_alpha_str(char* word, char*** words, int *size, int *current_index, int **count, int* read);



int main(int argc, char *argv[])
{

    if (argc < 2 || argc > 3)
    {
        fprintf(stderr, "Please provide 3 command line arguments!\n");
        return 1;
    }
  DIR * dir = opendir( argv[1] );   /* open the current working directory */

  if ( dir == NULL )
  {
    perror( "opendir() failed" );
    return EXIT_FAILURE;
  }

  struct dirent * file;
  int size = 32;
  printf("Allocated initial parallel arrays of size %d.\n",size);
  fflush( stdout );
  char** words =  calloc(size, sizeof(char*));
  int* count = calloc(size,sizeof(int));
  int current_index =0;
  int read=0;

  while ( ( file = readdir( dir ) ) != NULL )
  {

    struct stat buf;

    char* filepath = malloc(strlen(argv[1])+ strlen("/")+ strlen(file->d_name)+1);

    snprintf(filepath, strlen(argv[1])+ strlen("/")+ strlen(file->d_name)+1, "%s%s%s", argv[1], "/", file->d_name);

    int rc = lstat( filepath , &buf );


    if ( rc == -1 )
    {
      perror( "lstat() failed" );
      return EXIT_FAILURE;
    }

    if ( S_ISREG( buf.st_mode ) ) // if the file is a regular file. 
    {
      
       
      //Opening file for reading
      
      FILE * fp = fopen(filepath, "r");
      
      
      scanfile(fp, &words, &count, &size, &current_index, &read);
       fclose(fp);
      
    }
   
    free(filepath);


  }
  printf("All done (successfully read %d words; %d unique words).\n",read, current_index);
  fflush( stdout );

  if(argc == 3){
    
    int number = strtol(argv[2], NULL, 10);
    printf("First %d words (and corresponding counts) are:\n", number);
    fflush( stdout );
      for(int i=0; i < number; i++){
         printf("%s -- %d\n", words[i], count[i]);
         fflush( stdout );
      }
    printf("Last %d words (and corresponding counts) are:\n", number);
    fflush( stdout );
      for(int i = current_index-number; i < current_index; i++){
          printf("%s -- %d\n", words[i], count[i]);
          fflush( stdout );
      }

  }
  else{
    printf("All words (and corresponding counts) are:\n");
    fflush( stdout );
    for(int i=0; i < current_index; i++){
        printf("%s -- %d\n", words[i], count[i]);
        fflush( stdout );
      }
  }
  
      fflush(stdout);

    
    for(int i=0; i < current_index; i++){
      free(words[i]);
    }
    free(count);
    free(words);

  closedir( dir );
  return EXIT_SUCCESS;
}



void scanfile(FILE *fp, char*** words, int** count, int* size, int* current_index, int *read){
    

    while(1){

      char* word = calloc(79, sizeof(char));

      fscanf(fp, "%s", word);
     
      condense_alpha_str(word, words, size, current_index, count, read);
      free(word);

      if(feof(fp)){

        break;
      }
     }

      

}
void condense_alpha_str(char* word, char*** words, int *size, int *current_index, int **count, int* read){
  int word_index = 0;
  char* nonalpha = (char*) calloc(79, sizeof(char));
  int found=0;
  while(word[word_index] != '\0'){
    if (!(isalpha(word[word_index]))){
        nonalpha[found] = word[word_index];
        found++;
    }
    ++word_index;
  }
  nonalpha[found] = '\0';

  char *token= NULL;

  if(found==0){ token = strtok(word, " "); }
  else{  token = strtok(word, nonalpha); }
   

    
  while(token!=NULL){
    if(strlen(token)> 1){ *read = *read+1; }

    if(*current_index == (*size)){
      *size = *size +32;
      printf("Re-allocated parallel arrays to be size %d.\n",*size);
      fflush( stdout );
      *words = realloc(*words, *size*sizeof(char*));
       (*count) = realloc((*count), *size*sizeof(int));
    }

    char* temp= NULL;

    char *str = "";
    temp= (char*)calloc(strlen(token)+1+strlen(str), sizeof(char));
    snprintf(temp, strlen(token)+1+strlen(str), "%s%s", token, str );


    if(strlen(temp)<2){
      free(temp);
    }
    else{
      int isthere = 0;
    if(*current_index==0){
      if(strlen(temp)>1){
        (*words)[*current_index] =temp ;
        (*count)[*current_index]  = 1;
      
        *current_index = *current_index +1;
      }
      
    }
   
    else{

      for(int i=0; i < *current_index; i++){
       
        if(strcmp((*words)[i],temp)==0){
          (*count)[i] = (*count)[i]+1;
          isthere = 1;
        }
      
      }
      if(isthere==0){
        if(strlen(temp)>1){
           (*words)[*current_index] =temp ;
          (*count)[*current_index]  = 1;
          *current_index = *current_index +1;
        }
       

      }
     
    }
    }

    if(found==0){
      token = strtok(NULL, " ");
    }
    else{token = strtok(NULL, nonalpha);
    }

     
    }

    free(nonalpha);
}
