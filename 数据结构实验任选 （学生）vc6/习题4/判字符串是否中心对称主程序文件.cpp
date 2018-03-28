//判字符串中心对称的主程序文件.cpp
#include<iostream.h>
#include"单链表顺序栈结构类型定义.h"
#include"置栈空.h"
#include"求单链表长度.h"
#include"输出单链表.h"
#include"建立单链表.h"
#include"顺序栈入栈.h"
#include"顺序栈出栈.h"
#include"判字符串是否中心对称.h" 
void main()
{
	linklist *head;stack *s;
	datatype str[80];
	cin>>str;
	creat(head,str);
	printlink(head);
	setnull(s);
	if(symmetry(head,s)) cout<<"字符串\""<<str<<"\"中心对称\n";
	else cout<<"字符串\""<<str<<"\"不是中心对称\n";
}