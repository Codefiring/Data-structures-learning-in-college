//¶ş²æÊ÷µÄÊä³ö.h
void preorder(bitree*p)
{
	if(p!=NULL)
	{
		cout<<p->data;
		if(p->lchild!=NULL||p->rchild!=NULL)
		{
			cout<<"(";
			preorder(p->lchild);
			if(p->rchild!=NULL)cout<<",";
			preorder(p->rchild);
			cout<<")";
		}
	}
}
