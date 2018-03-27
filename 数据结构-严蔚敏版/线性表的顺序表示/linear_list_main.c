//This file is using to test the Linear_list.h

#include<stdio.h>
#include "Linear_list.h"

int main()
{
	Sqlist a ;
	Sqlist *l = &a;
	InitList(l);
	for(int i = 0;i<10;i++)
	AddElem(l, i);
	int number;
	ElemType *e = &number;
	ElemType c ;
	ElemType *d = &c;
	PriorElem(a, 4, d);
	printf("%d\n", c);
	printf("%d\n",GetElem(a,5,e));
	ListInsert(l, 3, 2);
	printf("%d\n", GetElem(a, 5, e));
	printf("%d\n", l->listsize);
	printf("%d\n", l->length);
	ListDelete(l, 5, e);
	printf("%d\n", number);
	printf("%d\n", l->length);
	printf("The construction has been done !\n");
	return 0;
}
