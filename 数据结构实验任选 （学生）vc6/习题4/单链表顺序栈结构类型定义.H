//定义单链表结构类型.h
typedef char datatype;
typedef struct node
{  datatype data;
   struct node *next;
}linklist;
//定义顺序栈结构类型
const int maxsize=40;
typedef struct
{  datatype elements[maxsize];
   int top;
}stack;