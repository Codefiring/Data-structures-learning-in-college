//在循环链表中插入.h
void insert(linklist*h,linklist*p)
{  linklist *q=h;
   while(q->next!=h) q=q->next;
   q->next=p;
   p->next=h;
}