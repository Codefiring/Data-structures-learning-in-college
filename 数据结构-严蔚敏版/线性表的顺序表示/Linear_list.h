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


