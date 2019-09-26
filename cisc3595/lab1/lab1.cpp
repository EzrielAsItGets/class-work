/*
Ezriel Ciriaco
Professor Harazduk
CISC 3593 R01
26 September 2019

Lab1: Write a program that reads all of the arguments from the command line,
uses the first argument as a command and the remaining arguments as the
arguments to the given command.
*/

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

int main(int argc, char *argv[]) {
  char * ls_args[3] = {"ls", "-1", NULL};
  pid_t c_pid, pid;
  int status;

  c_pid = fork();

  if (c_pid == 0) {
    cout << "Child process pid is " << getpid() << "\n";
    execvp(ls_args[0], ls_args);
    perror("execve failed");
  }
  else if (c_pid > 0) {
    if ((pid = wait(&status)) < 0) {
      cout << "Parent process pid is " << getpid() << "\n";
      return 1;
    }
  }
  else {
    perror("fork failed");
    return 1;
  }

  return 0;
}
