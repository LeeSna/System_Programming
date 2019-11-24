#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
    
    int width, height;
    int **a;
    int **b;

    printf("행렬의 가로 길이 입력 : ");
    scanf("%d", &width);
    printf("행렬의 세로 길이 입력 : ");
    scanf("%d", &height);

    a = (int**) malloc(sizeof(int*) * height);
    b = (int**) malloc(sizeof(int*) * height);

    for(int i = 0; i < height; i++) {
	a[i] = (int*) malloc(sizeof(int) * width);
	b[i] = (int*) malloc(sizeof(int) * width);
    }
    
    srand(time(NULL));

    printf("----- matrix A -----\n");
    for(int i = 0; i < height; i++) {
	for(int j = 0; j < width; j++) {
	    a[i][j] = (int)(rand()%5);
	    printf("%d ", a[i][j]);
	}
	printf("\n");
    }

    printf("----- matrix B -----\n");
    for(int i = 0; i < height; i++) {
	for(int j = 0; j < width; j++) {
	    b[i][j] = (int)(rand()%5);
	    printf("%d ", b[i][j]);
	}
	printf("\n");
    }

    printf("----- A + B -----\n");
    for(int i = 0; i < height; i++) {
	for(int j = 0; j < width; j++) {
	    printf("%d ", a[i][j] + b[i][j]);
	}
	printf("\n");
    }

    for(int i = 0; i < height; i++) {
	free(a[i]);
	free(b[i]);
    }
    free(a);
    free(b);
}
