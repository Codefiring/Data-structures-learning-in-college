//二叉树的建立.h
bitree*creattree()
{
	char ch;
	bitree*Q[maxsize];
	int front,rear;
	bitree*root,*s;
	root=NULL;
	front=1;rear=0;
	while((ch=getchar())!='#')
	{
		s=NULL;
		if(ch!='@')
		{
			s=new bitree;
			s->data=ch;
			s->lchild=NULL;
			s->rchild=NULL;
		}
		rear++;
		Q[rear]=s;
		if(rear==1)root=s;
		else
		{
			if(s&&Q[front])
				if(rear%2==0)Q[front]->lchild=s;
				else Q[front]->rchild=s;
			if(rear%2==1)front++;
		}
	}
	return root;
}
