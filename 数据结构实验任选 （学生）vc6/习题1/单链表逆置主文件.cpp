//单链表逆置主文件.cpp
#include<iostream>
using namespace std;
#include<stdio.h>
#include"单链表结构类型定义.h"
#include"建立单链表.h"
#include"输出单链表.h"
#include"单链表逆置.h"
void main()
{
	linklist*head;
	creat(head);
	print(head);
	invert(head);//调用单链表逆置的函数
	print(head);
}

