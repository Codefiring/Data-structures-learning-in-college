//ѭ��������ӳ��ӵ��������ļ�.cpp
#include<iostream.h>
#include<stdlib.h>
#include"ѭ�����еĽṹ���Ͷ���.h"
#include"�ÿն�.h"
#include"���.h"
#include"����.h"
void main()
{  qu *sq;
   datatype x, *p;
   int key;
   sq=new qu;
   setnull(sq);
   do
   {  cout<<"1.Enter Queue   2.Delete Queue   -1.Quit:";
      cin>>key;
      switch(key)
      {  case 1:  cout<<"Enter the Data:"; cin>>x;
		          enqueue(sq,x);  break;
	     case 2:  p=dequeue(sq);
		          if(p!=NULL) cout<<*p<<endl;
		          break;
	     case -1: exit(0);
      }
   }while(1);
}