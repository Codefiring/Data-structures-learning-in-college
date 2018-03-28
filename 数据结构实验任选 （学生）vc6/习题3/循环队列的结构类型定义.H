//循环队列的结构类型定义.h
const int m=5;
typedef int datatype;
typedef struct
{   datatype sequ[m];
    int  rear, quelen;
}qu;