#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>

int ls_la(char *cmd) {
    
    int status;
    switch(fork()) {
	case 0:
	    execl("/bin/bash", "/bin/bash", "-c", cmd, NULL);
	    break;
	case -1:
	    perror("fork");
	    exit(0);
	default:
	    wait(&status);
	    break;
    }
    return status;
}

void main(int argc, char *argv[]) {
    
    char str[20];
    char opt[20];
    
    strcpy(str, argv[1]);
    
    if(argc >=3) {
	strcpy(opt, argv[2]);
	strcat(str, " ");
	strcat(str, opt);
    }
    ls_la(str);

}
