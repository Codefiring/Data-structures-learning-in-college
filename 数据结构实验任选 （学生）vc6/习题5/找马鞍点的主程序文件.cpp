//找马鞍点的主程序文件.cpp
#include<iostream.h>
#include"数组的结构类型定义.h"
#include"找马鞍点.h"
void main()
{
	array*pa=new array;
    int i, j;
    for (i=0;i<m;i++)
      for (j=0;j<n;j++)
        cin>>pa->A[i][j];
    minmax(pa);
}