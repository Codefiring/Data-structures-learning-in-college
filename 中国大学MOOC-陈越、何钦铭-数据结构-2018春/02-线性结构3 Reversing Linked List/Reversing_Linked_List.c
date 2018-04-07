#include<stdio.h>
#define Max_N 100010

typedef struct
{
	int Adress;
	int Data;
	int Next;
}SLinkList;


int main()
{
	int L_length = 0;
	int L_head = 0;
	int L_reverse_n = 0;
	scanf("%d%d%d", &L_head, &L_length, &L_reverse_n);

	SLinkList L[Max_N] = { 0 };
	for (int i = 0; i < L_length; i++)
		scanf("%d%d%d", &L[i].Adress, &L[i].Data, &L[i].Next);
	
	SLinkList L_sorted[Max_N] = { 0 };
	int l_next = L_head;
	for(int i = 0;i<L_length;i++) {
		for (int j = 0; j < L_length; j++) 
			if (L[j].Adress == l_next) {
				L_sorted[i].Adress = L[j].Adress;
				L_sorted[i].Data = L[j].Data;
				L_sorted[i].Next= L[j].Next;
			}
		l_next = L_sorted[i].Next;
		}


	int cal_times = L_length / L_reverse_n;
	int l_index = 0;
	SLinkList L_reverse[Max_N] = { 0 };
	for (int i = 0; i < cal_times; i++) {
		l_index = 0 + i*L_reverse_n;
		L_reverse[l_index + L_reverse_n - 1].Next = L_sorted[l_index + L_reverse_n - 1].Next;
		for (int j = l_index; j < L_reverse_n; j++) {
			L_reverse[j].Adress = L_sorted[L_reverse_n + l_index - j - 1].Adress;
			L_reverse[j].Data = L_sorted[L_reverse_n + l_index - j - 1].Data;
		}
		for (int j = l_index; j < L_reverse_n - 1; j++)
			L_reverse[j].Next = L_reverse[j + 1].Adress;
	}
	if (L_length%L_reverse_n)
		for (int i = (cal_times*L_reverse_n); i < L_length; i++) {
			L_reverse[i] = L_sorted[i];
		}

	for (int i = 0; i < L_length-1; i++)
		printf("%.5d %d %.5d\n", L_reverse[i].Adress, L_reverse[i].Data, L_reverse[i].Next);
	printf("%.5d %d %d\n", L_reverse[L_length - 1].Adress, L_reverse[L_length - 1].Data, L_reverse[L_length - 1].Next);

	return 0;
}