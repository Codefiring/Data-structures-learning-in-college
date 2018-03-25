#include<stdio.h>
#include "Linear_list.h"


int main()
{
	Sqlist a[10];
	Sqlist*l = a;
	InitList(l);
	AddElem(l, 1);
	AddElem(l, 2);
	ElemType *e;
	GetElem(a, 2, e);
	printf("%d\n", );
	printf("%d\n", l->listsize);
	printf("%d\n", l->length);
	printf("The construction has been done !\n");
	return 0;
}
