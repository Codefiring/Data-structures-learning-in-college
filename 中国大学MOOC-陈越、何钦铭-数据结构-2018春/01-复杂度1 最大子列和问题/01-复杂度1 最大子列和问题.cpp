// 01-复杂度1 最大子列和问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>

#define NoIntergrate 0
#define MaxSize 100000

int MaxSubseqSum(int *, int);
int DevideAndConque(int list[], int left, int right);

int main()
{
	int k, sum;
	scanf("%d", &k);
	int data[MaxSize], flag = 0;
	int *p = data;
	for (int i = 0; i < k; i++)
	{
		scanf("%d", &data[i]);
		if (data[i] >= 0)flag = 1;
	}
	if (flag == 0)
	{
		printf("%d\n", NoIntergrate);
		return 0;
	}
	else
	{
		sum = MaxSubseqSum(p , k);
		printf("%d\n", sum);
	}
	return 0;
}

int Max3(int A, int B, int C)
{
	
	return A > B ? A > C ? A : C : B > C ? B : C;

}

int DevideAndConque(int list[], int left, int right)
{
	int MaxLeftSum, MaxRightSum;
	int LeftBorderSum, RightBorderSum;
	int MaxLeftBorderSum, MaxRightBorderSum;
	int center, i;
	
	if (left == right)
		if (list[left] > 0)return list[left];
		else return 0;
	else
	{ 
		center = (left + right) / 2;

		MaxRightSum = DevideAndConque(list, left, center);
		MaxLeftSum = DevideAndConque(list, center + 1, right);

		MaxLeftBorderSum = 0; LeftBorderSum = 0;
		for (i = center; i >= left; i--)
		{
			LeftBorderSum += list[i];
			if (LeftBorderSum >= MaxLeftBorderSum)
				MaxLeftBorderSum = LeftBorderSum;
		}

		MaxRightBorderSum = 0; RightBorderSum = 0;
		for (i = center + 1; i <= right; i++)
		{
			RightBorderSum += list[i];
			if (RightBorderSum >= MaxRightBorderSum)
				MaxRightBorderSum = RightBorderSum;
		}
	}
		return Max3(MaxRightSum, MaxLeftSum, MaxLeftBorderSum + MaxLeftBorderSum);
}

int MaxSubseqSum(int List[], int k)
{
	return DevideAndConque(List, 0, k - 1);
}
//穷举法
/*int MaxSubseqSum(int List[], int k)
{
	int ThisSum, MaxSum = 0;
	int i, j;

	for (i = 0; i < k; i++)
	{
		ThisSum = 0;
		for (j = i; j < k; j++)
		{
			ThisSum += List[j];
			if (ThisSum > MaxSum)
				MaxSum = ThisSum;
		}
	}
	return MaxSum;
}
*/