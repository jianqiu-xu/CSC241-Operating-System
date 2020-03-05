#include <unistd.h> 
#include <signal.h> 
#include <stdlib.h> 
#include <stdio.h>
#include <string.h>

void alarmHandler(int);
void quitHandler(int);

int main(){

char name[10];

signal (SIGALRM, alarmHandler);
signal (SIGINT, quitHandler);
printf("Type in your username: ");
alarm(5);
scanf("%s", name);

while(strcmp(name, "exit") != 0){
	printf("Your username is %s.\n", name);
	printf("Type in your username: ");
	fflush(stdout);
	alarm(5);
	scanf("%s", name);
}
printf("\nBye bye!\n");
exit(0);
}

void alarmHandler(int theAlarm){
	printf("\nTime up!\n");
	printf("Type in your username: ");
	fflush(stdout);
	alarm(5);
	return;
}

void quitHandler (int theInt) {
	printf("\nPlease type 'exit' to quit.\n");
	printf("Type in your username: ");
	fflush(stdout);
	alarm(5);
	return;
}
