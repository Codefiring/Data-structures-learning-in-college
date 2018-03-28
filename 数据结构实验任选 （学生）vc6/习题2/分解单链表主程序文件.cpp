//分解单链表主程序文件.cpp
#include<iostream.h>
#include<stdio.h>
#include"单链表结构类型定义.h"
#include"建立单链表.h"
#include"输出单链表.h"
#include"输出循环链表.h"
#include"在循环链表中插入.h"
#include"分解单链表.h"
void main()
{  linklist *head,*letter,*digit,*other;
   creat(head);
   print1(head);
   letter=new linklist;
   letter->next=letter;
   digit=new linklist;
   digit->next=digit;
   other=new linklist;
   other->next=other;
   resolve(head,letter,digit,other);//调用分解单链表的函数
   print2(letter);
   print2(digit);
   print2(other);
}

