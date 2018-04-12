#pragma once
#include<stdlib.h>
#include<malloc.h>

#define Elemtype int
typedef int Status; //define the type of the function return status of the process

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR -1
#define INFEASTIBLE -1
#define OVERFLOW -2

typedef struct LNode {	//linknode type
	Elemtype data;
	struct LNode * next;
}*Link, *Position;

typedef struct {	//linklist type
	Link head, tail;	//define the head LNode and the tail LNode
	int len;
}LinkList;

Status MakeNode(Link &p, Elemtype e) {
	//make node point to e, return ERROR if failed
	p = (Link)malloc(sizeof(LNode));
	if(!p)	
		return(ERROR);
	p->data = e;
	return OK;
}//MakeNode

void FreeNode(Link &p) {
	//free LNode p
	free p;
	p = NULL;
}

Status InitList(LinkList &l) {
	//make an empty linklist
	Link p;
	p = (Link)malloc(sizeof(LNode));
	if (!p)
		return ERROR;
	p->next = NULL;
	l.head = p;
	l.tail = l.head;
	l.len = 0;
	return OK;
}

Status DestroyList(LinkList &l) {
	Link p;
	while (l.head!=l.tail) {
		p = l.head->next;
		free(l.head);
		l.head = p;
	}
	free(l.head);
	l.head = NULL;
	l.tail = NULL;
	return OK;
}
