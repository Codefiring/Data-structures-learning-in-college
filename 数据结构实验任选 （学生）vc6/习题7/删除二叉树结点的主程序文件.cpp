//ɾ�������������������ļ�.cpp
#include<iostream.h>
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include"��������Ľṹ���Ͷ���.h"
#include"�������Ľ���.h"
#include"�����������.h"
//#include"ɾ����������.h"
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

