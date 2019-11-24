#include <stdio.h>
#include <errno.h>
#include <string.h>

void my_perror(char *s) {
    printf("%s : %s", s, strerror(errno));
}

