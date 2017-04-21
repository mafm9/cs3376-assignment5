// file: onepipe.cpp
// author: Miguel Medrano
// date: 03/04/2015
// purpose: CS3376
// description:
// this program executes "ls -ltr | grep 3376", by dividing the two command
//among the child and parent process
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
int main(int argc, char *argv[]){
int status;
int childpid;

 // create one pipe to send the output of "ls" process to "grep" process
 int pipes[3];
 pipe(pipes);
if(argc <2)
{
std::cout <<  "Please enter more than 2 args";
}
if(argc > 5)
{
std::cout << "Please enter fewer than 5 args";
}

 // fork the first child (to execute cat)
 if((childpid = fork()) == -1){
 perror("Error creating a child process");
exit(1);
 }
 if (childpid == 0) {
 // replace cat's stdout with write part of 1st pipe
 for(int i=0; i<argc-1; i++)
{
dup2(pipes[i+1],i);
 // close all pipes (very important!); end we're using was safely copied
 close(pipes[i]);

 execvp(argv[i], argv);
}
 exit(0);
 }
 else {
 return(0);
}
}
