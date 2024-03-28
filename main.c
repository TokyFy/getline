#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int main(void)
{
  int fd = open("text.txt", O_RDONLY);

  char *s = get_next_line(fd);
  printf("%s" , s);
  free(s);
  close(fd);
  return 0;
}
