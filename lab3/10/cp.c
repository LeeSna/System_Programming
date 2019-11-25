#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <string.h>

#define SEMKEY (key_t) 0111
#define SHMKEY (key_t) 0111
#define SHMSIZE 1024

void testsem(int semid);
void p(int semid);
void v(int semid);

void main() {
    
    int semid, i;
    
    union semun {
		int value;
		struct semid_ds *buf;
		unsigned short int *array;
    } arg;

    if((semid = semget(SEMKEY, 1, IPC_CREAT|0666)) == -1) {
		perror("semget failed");
		exit(1);
    }

    arg.value = 1;
    if(semctl(semid, 0, SETVAL, arg) == -1) {
		perror("semctl failed");
		exit(1);
    }

    id_t pid;
    pid = fork();

    // child process
    if(pid == 0) {
	p(semid);
	printf("child %d : semaphore in use\n", getpid());

	int shmid, len;
	void *shmaddr;

	if((shmid = shmget(SHMKEY, SHMSIZE, IPC_CREAT|0666)) == -1) {
	    perror("shmget failed");
	    exit(1);
	}
	if((shmaddr = shmat(shmid, NULL, 0)) == (void *)-1) {
	    perror("shmat flaied");
	    exit(1);
	}

	printf("copy string : %s \n", (char*)shmaddr);

	if(shmdt(shmaddr) == -1) {
	    perror("shmdt failed");
	    exit(1);
	}
	if(shmctl(shmid, IPC_RMID, 0) == -1) {
	    perror("shmctl failed");
	    exit(1);
	}

	printf("child %d : putting semaphore\n", getpid());
	v(semid);
	exit(0);
    }
    // parent process
    else if(pid > 0) {
	p(semid);
	printf("parent %d : semaphore in use\n", getpid());

    	int shmid, len;
    	void *shmaddr;
    	char str[30];
	
	printf("복사할 문자열 : ");
	gets(str);

    	if((shmid = shmget(SHMKEY, SHMSIZE, IPC_CREAT|0666)) == -1) {
	    perror("shmget failed");
	    exit(1);
	}
	if((shmaddr = shmat(shmid, NULL, 0)) == (void *)-1) {
	    perror("shmat flaied");
	    exit(1);
	}
		
	strcpy((char*)shmaddr, str);

	if(shmdt(shmaddr) == -1) {
	    perror("shmdt failed");
	    exit(1);
	}

	printf("parent %d : putting semaphore\n", getpid());
	v(semid);
		
	sleep(1);
	exit(1);
    }
    else {
	printf("fork failed");	
    }
    sleep(5);

    if(semctl(semid, 0 ,IPC_RMID, arg) == -1) {
	perror("semctl failed");
	exit(1);
    }

}

void p(int semid) {
	
    struct sembuf pbuf;
    pbuf.sem_num = 0;
    pbuf.sem_op = -1;
    pbuf.sem_flg = SEM_UNDO;

    if(semop(semid, &pbuf, 1) == -1) {
	perror("semop failed");
	exit(1);
    }
}

void v(int semid) {
	
    struct sembuf vbuf;
    vbuf.sem_num = 0;
    vbuf.sem_op = -1;
    vbuf.sem_flg = SEM_UNDO;

    if(semop(semid, &vbuf, 1) == -1) {
	perror("semop failed");
	exit(1);
    }
}
