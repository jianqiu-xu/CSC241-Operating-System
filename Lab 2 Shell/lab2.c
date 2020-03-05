#include <unistd.h> 
#include <signal.h> 
#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <stdbool.h>

int main(){

	char *str;
	str = NULL;
	unsigned long n = 0;
	unsigned long cmd;
	char *ptr;

	while(1){

		fflush(stdout);
		cmd = getline(&str, &n, stdin); // take user input
		str[strlen(str)-1] = '\0';

		if(strcmp(str, "exit") == 0){ // program terminate once the "exit" is typed
			exit(0);
		}

		char delim[] = " "; // prase input using space as delimiter
		char **argv = NULL; // pointer array point to *ptr
		int numStrings = 0; // number of strings in the input
		bool conc;

		ptr = strtok(str, delim); // pointer to the character of next token
		//printf(str);
		
		while (ptr != NULL){
			argv = realloc(argv, sizeof(*ptr) * numStrings++); // reallocate memory for the pointer array
		
			argv[numStrings-1] = ptr; // store the pointers
		
			ptr = strtok(NULL, delim); // go to the next string separated by space
			//printf(ptr);
		}

		if(strcmp(argv[numStrings-1], "&") == 0){
			argv[numStrings-1] = '\0';
			conc = false;			// if the last element is '&', the parent and child process run concurrently
		}
					
		if (fork() == 0){ // fork a child process
			if(execvp (argv[0], argv) == -1){ // execute shell
				//exit(0);
				printf("Wrong Command."); // print error message if command incorrect
				return 1;
			}
		}

		if (conc == true){wait(0);}

		free(argv); // free the memory allocation
		
		}

	return 0;
}
	
