#pragma once
#include<stdlib.h>
#include<malloc.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR -1
#define INFEASTIBLE -1
#define OVERFLOW -2

typedef int Status; //define the type of the function return status of the process

#define LIST_INIT_SIZE 100 //define the initial size of the linear list
#define LIST_INCREMENT_SIZE 10 //define the increment size of the linear list
#define ElemType int //define the data type of the linear list 

typedef struct {
	ElemType *elem;   //the fundimental address of the memory 
	int length;         //the current length of the linear list
	int listsize;		//the whole size of the memory had been given measure by(sizeof(Elem))
}Sqlist;

Status InitList(Sqlist* l)
{
	l->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!l->elem) exit(OVERFLOW);
	l->length = 0;
	l->listsize = LIST_INIT_SIZE;
	return OK;
}

Status DestroyList(Sqlist* l)
{
	free(l);
	l = NULL;
	printf("The list has been destroyed !");
	return OK;
}

Status ClearList(Sqlist* l)
{
	if (!l->length) return OK;
	InitList(l);
	return OK;
}

Status ListEmpty(Sqlist l)
{
	printf("The list has been empty !");
	if (!l.length)return TRUE;
	else return FALSE;
}

int ListLength(Sqlist l)
{
	return l.length;
}

ElemType GetElem(Sqlist l, int i, ElemType* e)  // This function make 'e' equals to 'elem' in list 'l' at position 'i'
{
	if (1 > i || i > l.length)return ERROR;
	*e = l.elem[i-1];
	return *e;
}

Status AddElem(Sqlist *l,ElemType e)
{
	if (l->length == l->listsize)
	{
		l = realloc(l, sizeof((l->listsize + LIST_INCREMENT_SIZE) * sizeof(ElemType)));
	}
	l->elem[l->length++] = e;
	return OK;
}

int LocateElem(Sqlist l, ElemType e,int index[])
/*Input: list 'l' and the compare 'e' and the array holds the position where 'l.elem' equals to 'e'*/
{
	int num_counter = 1;
	if (ListEmpty(l))exit(ERROR);
	for (int i = 0; i < l.length; i++)
	{
		if (l.elem[i] == e) {
			index[num_counter - 1] = i;
			num_counter++;
		}
	}
	printf("The location of the elem are:");
	for (int j = 0; j < num_counter; j++)
	{
		printf("%d ", l.elem[index[j]]);
	}
}

