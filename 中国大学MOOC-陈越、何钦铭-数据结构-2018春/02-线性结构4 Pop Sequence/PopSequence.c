#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define MAXMUM_POP 1000
typedef struct {
	int *top;
	int *base;
	int stacksize;
}SqStack;

int popSize = 0, popLenth = 0, numSequence = 0;

int InitStack(SqStack *S,int size) {
	(*S).base = (int*)malloc(size * sizeof(int));
	if (!(*S).base)return 0;
	(*S).top = (*S).base;
	(*S).stacksize = size;
	return 0;			
}

int GetTop(SqStack S, int *e) {
	if (S.top == S.base)return 0;
	e = *(S.top - 1);
	return 0;
}

int Push(SqStack *S, int e) {
	*(*S).top++ = e;
	return 0;
}

int Pop(SqStack *S, int *e) {
	e = *(--(*S).top);
	return 0;
}

int ArrayJudge(int *a, int *b, int num) 
{
	int flag = 0;
	for (int i = 0; i < num; i++)
		if (a[i] != b[i])
			return 1;
	return 0;
}

int Check(int* popCheck) {

}

int main()
{
	
	scanf("%d%d%d", &popSize, &popLenth, &numSequence);
	int popCheck[MAXMUM_POP] = {0};

	for (int i = 0; i < numSequence; i++)
		for (int j = 0; j < popLenth; j++)
			scanf(" %d", &popCheck[i]);

	/*for (int i = 0; i < numSequence*popLenth; i++)
		scanf("%d", popCheck[i]);*/

	int a[7] = { 0,2,3,4,3,2,1 };
	int b[7] = { 0,2,3,4,3,2,1 };
	ArrayJudge(a, b, 7);
	return 0;
}
