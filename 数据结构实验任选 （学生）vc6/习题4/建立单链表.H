//建立具有头结点的单链表.h
void creat(linklist *&head,datatype*str)
{  datatype *p=str;
   linklist *s,*r;
   head=new linklist;
   r=head;
   while(*p!='\0')
   {  
	  s=new linklist;
      s->data=*p;
	  r->next=s;
	  r=s;
	  p++;
   }
   r->next=NULL;
}