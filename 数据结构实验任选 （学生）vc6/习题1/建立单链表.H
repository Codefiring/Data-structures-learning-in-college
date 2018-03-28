//建立单链表.h
void creat(linklist*&head)
//采用尾插法建立具有头结点的单链表
{
	char ch;
	linklist *s,*r;
	head=new linklist;
	r=head;
	while((ch=getchar())!='*')
	{
		s=new linklist;
		s->data=ch;
		r->next=s;
		r=s;
	}
	r->next=NULL;
}


