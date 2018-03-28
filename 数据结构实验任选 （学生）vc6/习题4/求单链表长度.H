//求单链表长度.h
int length(linklist*head)

{  linklist *p=head->next;
   int n=0;
   while(p!=NULL){  n++;  p=p->next; }
   return n;
}