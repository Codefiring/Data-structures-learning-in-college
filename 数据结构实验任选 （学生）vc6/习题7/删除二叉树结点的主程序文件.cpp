//删除二叉树结点的主程序文件.cpp
#include<iostream.h>
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include"二叉链表的结构类型定义.h"
#include"二叉树的建立.h"
#include"二叉树的输出.h"
//#include"删除结点和子树.h"
void main()
{
	bitree*root;
	datatype x;
	CreateBiTree(root);
	preorder(root);
    PrintBiTree(root,2);
	cout<<endl;
	cin>>x;
	//root=delsubtree(root,x);
	preorder(root);
	cout<<endl;
}

