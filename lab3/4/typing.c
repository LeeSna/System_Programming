#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <ncurses.h>

#include <time.h>
#include <sys/time.h>

#define ESC 0x1b

void sampletext();

void main() {
    
    char c;
    char buffer[80];
    int i = 0;
    int j;
    int line = 1;

    time_t start = 0, end = 0;
    float gap = 0;
    int tasu = 0;

    initscr();
    clear();
    refresh();

    for(j = 0; j < 80; j++) {
	buffer[j] = '\0';
    }

    sampletext();

    move(1, 0);
    refresh();
    
    time(&start);

    while(c != 127) {
	c = getchar();
	if(c == '\r' || i >= 80) {
	    line += 2;
	    move(line, 0);
	    printf("\r");
	    refresh();
	    i = 0;
	    for(j = 0; j < 80; j++) {
		if(buffer[j]) {

		    buffer[j] = '\0';
		}
	    }
	}
	else {
	    putchar(c);
	    buffer[i] = c;
	    i++;
	}
    }
    time(&end);
    
    gap = end - start;
    tasu = 60*(58/gap);

    move(7, 0);
    printw("play time : %.1f\n", (float)gap);
    printw("tasu : %d\n", tasu);
    printw("typing err : 0\n");
    refresh();

    if(c == ESC) {
	endwin();
    }
}

void sampletext() {
    
    int line = 0;
    addstr("20143257 leehyeonsu");
    
    line += 2;
    move(line, 0);
    addstr("system programming typing test");

    line += 2;
    move(line, 0);
    addstr("i wanna go home");
}
