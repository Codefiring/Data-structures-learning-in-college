//二叉链表的结构类型定义.h
const int maxsize=1024;
typedef char datatype;
typedef struct node
{
	datatype data;
	struct node *lchild,*rchild;
}bitree;
