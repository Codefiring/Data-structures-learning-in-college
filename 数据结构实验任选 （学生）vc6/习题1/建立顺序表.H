//½¨Á¢Ë³Ðò±í.H
void creat(sequenlist*&L)
{
	L=new sequenlist;
	L->last=0;
	char ch;
	while((ch=getchar())!='*')
	{
		L->data[L->last]=ch;
		L->last++;
	}
}


