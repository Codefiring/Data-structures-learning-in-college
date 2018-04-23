#include <stdio.h>
#include "Link_list.h"

int main() {
	LinkList list;
	LinkList *l = &list;

	printf("Creating LinkList: \"list\"...\n");
	
	InitList(l);
	printf("list.len:%d\n", list.len);
	printf("After InitList: address of list.head:%p\n", list.head);
	printf("After InitList: address of list.tail:%p\n", list.tail);

	LNode tmp;
	Link s = &tmp;
	MakeNode(s, 5);

	printf("%d\n", tmp.data);

	InsFirst(l, s);
	printf("After InFirst: list.head->next->data = %d\n", list.head->next->data);
	printf("After InFirst: list.len = %d\n", list.len);
	printf("After InFirst: address of list.head:%p\n", list.head);
	printf("After InFirst: address of list.tail:%p\n", list.tail);

	LNode cnode;
	Link node_chain =  &cnode;
	cnode.next = NULL;
	const Link node_head = node_chain;
	
	for (int i = 0; i < 10; i++) {
		node_chain = node_head;
		while (node_chain->next != NULL)node_chain = node_chain->next;
		Link s_tmp;
		s_tmp = (Link)malloc(sizeof(Link));
		MakeNode(s_tmp, i);
		node_chain->next = s_tmp;
	}

	Append(l, node_head);
	printf("After Append: list.len = %d\n", list.len);
	printf("After Append: address of list.head:%p\n", list.head);
	printf("After Append: address of list.tail:%p\n", list.tail);
	printf("After Append: list.head->next->data = %d\n", list.head->data);
	printf("After Append: list.tail->data = %d\n", list.tail->data);

	LNode q_tmp;
	Link q = &q_tmp;
	DelFirst(l, q);
	printf("After DelFirst: q->data = %d\n", q->data);
	printf("After DelFirst: list.head->next->data = %d\n", list.head->next->data);
	printf("After DelFirst: list.tail->data = %d\n", list.tail->data);
	printf("After DelFirst: list.len = %d\n", list.len);

	LNode q2_tmp;
	Link q2 = &q2_tmp;
	Remove(l, q2);
	printf("After Remove: q->data = %d\n", q->data);
	printf("After Remove: list.head->next->data = %d\n", list.head->next->data);
	printf("After Remove: list.tail->data = %d\n", list.tail->data);
	printf("After Remove: list.len = %d\n", list.len);




	//DestroyList(l);
	//printf("list.head:%p\n", l);

	return 0;
}