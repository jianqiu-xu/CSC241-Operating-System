NAME: Tony Xu
CSC-241 - Lab 1
This lab explores the concept of signals, and asynchronous mechanism for process communication.

The program will prompts for a username, waits for user input, if none is given after a timeout of 5 seconds, print the message "Time up!", reset the alarm and display the prompt again.

If the username input is received, the program echoes the input ("Your username is ___") and then redisplays the username prompt.

If the input is the word "exit" then the program displays "Bye bye!" and exits immediately.

If the input is ^C (SIGINT) signal during the process, the program will display "Please type 'exit' to quit" and redisplay the username prompt.