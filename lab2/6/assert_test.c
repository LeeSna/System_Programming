#include <stdio.h>
#include <stdlib.h>

#define my_assert(exp) \
    if(!exp) {\
    printf("%s:%d:%s\n",__FILE__, __LINE__, __func__); \
    printf("Assertion '"#exp"' failed\n"); \
    exit(1); \
    }\

void foo(int num) {
    my_assert((num >= 0) && (num <= 100));
    printf("foo: num = %d\n", num);
}

void main(int argc, char *argv[]) {
    int num;

    if(argc < 2) {
	fprintf(stderr, "Usage : assert_test aNumber\n(0 <= aNumber <= )\n");
	exit(1);
    }

    num = atoi(argv[1]);
    foo(num);
}
