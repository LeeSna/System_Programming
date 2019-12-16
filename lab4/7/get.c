#include <stdio.h>

void main() {
    printf("Content-type: text/html\n\n");
    printf(" INPUT <HR>\n");
    printf("%s\n", getenv("QUERY_STRING"));
}
