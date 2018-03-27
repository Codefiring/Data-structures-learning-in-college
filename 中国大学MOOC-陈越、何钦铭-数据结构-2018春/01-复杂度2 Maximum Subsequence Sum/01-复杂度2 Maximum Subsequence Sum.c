#include<stdio.h>
#include<stdlib.h>

#define NoIntergrate 0
#define MaxSize 100000

int MaxSubseqSum(int *, int, int*);
int DevideAndConque(int list[], int left, int right,int mandl[]);

int main()
{
	int k, sum;

	int mandl[4] ;   //存放最小和最大值
	int *ml = mandl;

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
		printf("%d %d %d\n", NoIntergrate, data[0], data[k-1]);
		return 0;
	}
	else
	{
		sum = MaxSubseqSum(p, k ,ml);
		//if(sum == 0)
		//	printf("%d %d %d\n", NoIntergrate, data[0], data[k - 1]);
		//else
			printf("%d %d %d\n", sum, mandl[0], mandl[1]);

	}
	return 0;
}

int Max3(int A, int B, int C)
{

	return A > B ? A > C ? A : C : B > C ? B : C;

}

int DevideAndConque(int list[], int left, int right,int mandl[])
{
	int MaxLeftSum, MaxRightSum;
	int LeftBorderSum, RightBorderSum;
	int MaxLeftBorderSum, MaxRightBorderSum;
	int center, i;
	int ml[4];

	if (left == right)
		if (list[left] > 0) {
			mandl[0] = list[left];
			mandl[1] = list[left];
			return list[left];
		}
		else {
			mandl[0] = list[left];
			mandl[1] = list[right];
			return 0;
		}
	else
	{
		center = (left + right) / 2;

		MaxRightSum = DevideAndConque(list, left, center, mandl);
		MaxLeftSum = DevideAndConque(list, center + 1, right, mandl);

		MaxLeftBorderSum = 0; LeftBorderSum = 0;
		for (i = center; i >= left; i--)
		{
			ml[1] = list[center];
			LeftBorderSum += list[i];
			if (LeftBorderSum > MaxLeftBorderSum )
			{
				MaxLeftBorderSum = LeftBorderSum;
				ml[0] = list[i];
			}
		}

		MaxRightBorderSum = 0; RightBorderSum = 0;
		for (i = center + 1; i <= right; i++)
		{
			ml[2] = list[center+1];
			RightBorderSum += list[i];
			if (RightBorderSum > MaxRightBorderSum)
			{
				MaxRightBorderSum = RightBorderSum;
				ml[3] = list[i];
			}
		}
	}
	
	int max;
	max = Max3(MaxLeftBorderSum, MaxRightBorderSum, MaxLeftBorderSum + MaxRightBorderSum);
	
	if (max == MaxLeftBorderSum)
	{
		mandl[0] = ml[0];
		mandl[1] = ml[1];
	}
	else if (max == MaxRightBorderSum)
	{
		mandl[0] = ml[2];
		mandl[1] = ml[3];
	}
	else
	{
		mandl[0] = ml[0];
		mandl[1] = ml[3];
	}
	return max;
}

int MaxSubseqSum(int List[], int k,int mandl[])
{
	return DevideAndConque(List, 0, k - 1, mandl);
}

