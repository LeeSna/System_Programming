/* nonblockpipe.c */
/* pipe and nonblocking read/write example */

#include <fcntl.h>
#include <errno.h>

#define MSGSIZE 16

char *parent_name = "parent";
char *child_name = "child";
char *parent_msg = "Hello, child";
char *child_msg = "Hello, parent";

void nonblock_rv(char *, int, int, char*);

void main() {

  int pp[2][2], i;
  int pid;

  /* open pipe */

}
