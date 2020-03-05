NAME: Tony Xu
CSC-241 - Lab 2
This lab explores the concept of shell and write a simple shell program.The shell program should use the same style as the Bourne shell for running programs.

The program should use the execvp() system call to execute the file
that contains the command. This way the exec() will search the PATH directory paths automatically.

The shell must also interpret the “&” operator as a command terminator. A command terminated with “&” should be executed concurrently with the shell rather than the shell waiting for the command to terminate before it prompts the user for another command (background execution).

If a command is given that execvp() cannot execute (such as an erroneous command), an appropriate error message must be outputted and the shell should be reprompted.

Your program should terminate once the ^C signal is used or when the user types in “exit”.