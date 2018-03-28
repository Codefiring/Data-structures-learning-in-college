//交换左右子树的主程序文件.cpp
#include<iostream.h>
#include<stdio.h>
#include"二叉链表的结构类型定义.h"
#include"二叉树的建立.h"
#include"二叉树的输出.h"
#include"交换左右子树.h"
void main()
{
	bitree*pb;
	pb=creattree();
	preorder(pb);
	cout<<endl;
	swap(pb);
	preorder(pb);
	cout<<endl;
}

