#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>

struct student {
    char *name;
    int mScore;
    int fScore;
};

int cp(const void *cp1, const void *cp2) {
    return strcmp( ((struct student *)cp1)->name,
		    ((struct student *)cp2)->name);
}

void print_node(const void* nodeptr, VISIT order, int level) {
    if(order == preorder || order == leaf) {
	printf("%s  ||%d	||      %d\n",
		    (*(struct student **)nodeptr)->name,
		    (*(struct student **)nodeptr)->mScore,
		    (*(struct student **)nodeptr)->fScore);
    }
}

void main() {

    int stNum;

    printf("학생 수 입력 : ");
    scanf("%d", &stNum);

    char tName[stNum*15];
    struct student tNode[stNum];
    struct student *root = NULL;

    char *nameptr = tName;
    struct student *nodeptr = tNode;
    struct student **r;
    int i = 0;

    printf("이름, 중간 점수, 기말 점수 입력 : \n");
    while(i++ < stNum) {
	if(scanf("%s%d%d",nameptr,
		    &nodeptr->mScore, &nodeptr->fScore) != EOF) {
	    nodeptr->name = nameptr;
	    r = (struct node**)tsearch((void*)nodeptr, (void**)&root, cp);
	    
	    if(*r == nodeptr)
		printf("Ok--\n");
	    else
		printf("Already exists\n");

	    nameptr += strlen(nameptr) + 1;
	    nodeptr++;
	}
	else
	    break;
    }

    printf("이름    || 중간 점수    || 기말 점수 \n");
    printf("-------------------------------------\n");
    twalk((void *)root, print_node);
}
