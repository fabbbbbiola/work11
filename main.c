#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char ** parse_args(char * line){
  char ** stuff = (char **)calloc(6, sizeof(char *));
  int i = 0;
  while (line){
    stuff[i] = strsep(&line, " ");
    i++;
  }
  return stuff;
}

int main(){
  char line[52] = "ls -a -l";
  char ** stuff = parse_args(line);
  execvp(stuff[0], stuff);
}

