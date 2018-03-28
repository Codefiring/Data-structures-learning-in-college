//顺序表的结构类型定义.h
typedef char datatype;
const int maxsize=1024;
typedef struct
{ datatype data[maxsize];
  int last;
}sequenlist;
