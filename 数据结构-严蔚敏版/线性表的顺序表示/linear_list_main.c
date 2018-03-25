#include<stdio.h>
#include "Linear_list.h"


int main()
{
	Sqlist a;
	Sqlist*l = &a;
	InitList(l);
	printf("%d\n", l->listsize);
	printf("%d\n", l->length);
	printf("The construction has been done !\n");
	return 0;
}
