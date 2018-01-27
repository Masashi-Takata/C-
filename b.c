#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *file;
  char *line;
  size_t length;
  file=fopen("/dev/stdin","r");
  line=NULL;
  while (getline(&line,&length,file)!=-1) {
    printf(line);
  }
  free(line);
  fclose(file);
  return 0;
}
