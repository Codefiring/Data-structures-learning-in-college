#ifndef LINK_LIST_H_
#define LINK_LIST_H_

#include<stdlib.h>
#include<malloc.h>
#include "Status.h"

typedef struct LNode {	//linknode type
	Elemtype data;
	struct LNode * next;
}*Link, *Position;

typedef struct {	//linklist type
	Link head, tail;	//define the head LNode and the tail LNode
	int len;
}LinkList;

Status MakeNode(Link *p, Elemtype e) {
	//make node point to e, return ERROR if failed
	p = (Link)malloc(sizeof(Link));
	printf("%d", sizeof(Link));
	if(!p)	
		return(ERROR);
	p->data = e;
	return OK;
}//MakeNode

void FreeNode(Link *p) {
	//free LNode p
	free(p);
	p = NULL;
}

Status InitList(LinkList *l) {
	//make an empty linklist
	Link p;
	p = (Link)malloc(sizeof(Link));
	if (!p)
		return ERROR;
	p->next = NULL;
	l.head = p;
	l.tail = l.head;
	l.len = 0;
	return OK;
}

Status DestroyList(LinkList l) {
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

Status ClearList(LinkList l) {

}


#endif