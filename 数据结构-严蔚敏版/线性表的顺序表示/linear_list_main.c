#include<stdio.h>
#include "Linear_list.h"


int main()
{
	Sqlist a ;
	Sqlist *l = &a;
	InitList(l);
	AddElem(l, 1);
	AddElem(l, 2);
	int number;
	ElemType *e = &number;
	
	printf("%d\n",GetElem(a,1,e));
	printf("%d\n", l->listsize);
	printf("%d\n", l->length);
	printf("The construction has been done !\n");
	return 0;
}
