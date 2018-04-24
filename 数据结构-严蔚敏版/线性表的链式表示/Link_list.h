#ifndef LINK_LIST_H_
#define LINK_LIST_H_
#define LIST_INIT_SIZE  100

#include<stdlib.h>
#include<malloc.h>
#include "Status.h"


typedef struct LNode {	//linknode type
	Elemtype data;
	struct LNode * next;
}LNode, *Link, *Position;

typedef struct {	//linklist type
	Link head, tail;	//define the head LNode and the tail LNode
	int len;
}LinkList;

Status MakeNode(Link p, Elemtype e) {
	//make node point to e, return ERROR if failed
	
	//p = (Link)malloc(sizeof(Link));
	(*p).data = e;
	(*p).next = NULL;

	return OK;
}//MakeNode

void FreeNode(Link *p) {
	//free LNode p
	free(*p);
	*p = NULL;
}

Status InitList(LinkList *l) {
	//make an empty linklist
	Link p;		//get a new linknode 
	p = (Link)malloc(sizeof(Link));
	if (!p)
		return ERROR;
	p->data = 0;
	p->next = NULL;
	l->head = p;		//make linklist first point to this linknode
	l->tail = l->head;
	l->len = 0;
	return OK;
}

Status DestroyList(LinkList *l) {
	//destroy the list.the list will be nonexist.
	Link p;
	while (l->head!=l->tail) {
		p = l->head->next;
		FreeNode(l->head);
		l->head = p;
	}
	FreeNode(l->head);
	l->head = NULL;
	l->tail = NULL;
	return OK;
}

Status ClearList(LinkList *l) {
//	LinkList p;
	return OK;

}

Status InsFirst(LinkList *l, Link s) {
	//Give the linklist pointer l and the node pointer s
	//put s before the head of l
	s->next = l->head->next;
	l->head->next = s;
	while (l->tail->next != NULL)l->tail = l->tail->next;
	l->len++;

	return OK;
}

Status DelFirst(LinkList *l, Link q) {
	//Give the linklist pointer l and the node pointer q
	//Delete l->head and return it as q
	if (!l->len)return ERROR;
	(*q).data = l->head->next->data;
	(*q).next = NULL;
	l->head->next = l->head->next->next;
	l->len--;
	return OK;
}

Status Append(LinkList *l, Link s) {
	
	l->tail->next = s;
	while (l->tail->next != NULL) {
		l->tail = l->tail->next;
		l->len++;
	}
	return OK;
}

Status Remove(LinkList *l, Link q) {
	//remove the last LNode and return it as q
	Link tmp;
	tmp = l->head;
	while (tmp->next != l->tail)tmp = tmp->next;
	q = l->tail;
	l->tail = tmp;
	l->tail->next = NULL;
	return OK;
}

Status InsBefore(LinkList *l, Link *p, Link s) {
	//p point to a LNode in l and add s before q in l
	if (p == l->head)return ERROR;
	else if (p == l->head->next) InsFirst(l, s);
	else {
		while (l->head->next != p)l->head = l->head->next;
		l->head->next = s;
		s->next = p;
		l->len++;
	}
	return OK;
}

#endif