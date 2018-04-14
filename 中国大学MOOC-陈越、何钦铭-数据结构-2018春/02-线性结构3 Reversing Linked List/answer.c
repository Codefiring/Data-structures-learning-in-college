/*
������
ʱ��  ���  �÷�  ��Ŀ  ������ ��ʱ��ms��  �ڴ棨MB��  �û�
2017-07-08 15:54    ����ȷ    25  5-2 gcc 131 3
���Ե���
���Ե� ���  �÷�/����   ��ʱ��ms��  �ڴ棨MB��
���Ե�1    ����ȷ    12/12   2   1
���Ե�2    ����ȷ    3/3 14  1
���Ե�3    ����ȷ    2/2 1   1
���Ե�4    ����ȷ    2/2 2   1
���Ե�5    ����ȷ    2/2 2   1
���Ե�6    ����ȷ    3/3 131 3
���Ե�7    ����ȷ    1/1 2   1
*/
#include<stdio.h>
#define MAXLEN 100002
struct node {
	int data;
	int next;
};

int k, head;

struct node workArray[MAXLEN];

int Input(struct node  array[])
{
	int i, inputHead, inputLength;
	int index, data, next;

	scanf("%d %d %d", &inputHead, &inputLength, &k);
	for (i = 0; i<inputLength; i++) {
		scanf("%d %d %d", &index, &data, &next);
		array[index].data = data;
		array[index].next = next;
	}
	return inputHead;
}

int count(int head, struct node array[])
{
	int i, cnt = 1;
	i = head;
	while (array[i].next != -1) {
		cnt++;
		i = array[i].next;
	}
	return cnt;
}
void PrintList(int head, struct node array[])
{
	int idx = head;
	while (array[idx].next != -1) {
		printf("%05d %d %05d\n", idx, array[idx].data, array[idx].next);
		idx = array[idx].next;
	}
	printf("%05d %d %d", idx, array[idx].data, array[idx].next);
}

int ReverseList(struct node array[], int *head, int k)
{
	/*
	������count�������ȣ��ŵ�cnt�б��档ÿ��ִ��cnt�������k�����cnt<k�򲻽��з�ת
	Ȼ��ʹ��ptr1 ptr2 ptr3 ����ָ��
	ptr1Ϊ��ǰ�ڵ� ptr2Ϊ��һ���ڵ� ��ptr1->ptr2��Ϊptr2->ptr1����Ϊptr2�е�nextԭ�����ݻᶪʧ������ptr3����ptr2����һ���ڵ�
	ִ����һ�κ�k���ڵ������ڣ�ͷβ������
	��lastend����ǰһ�����ĩ�ˣ�����һ�����ͷ�ڵ�
	nexthead����һ�����ͷ��㣬ͬ��Ҳ�Ǹ����鷭ת����ĩ�ˡ�������ǰ��lastend=nexthead���档
	*/
	int cnt;
	if (k == 1)
		return;
	cnt = count(*head, array);
	int i, ptr1, ptr2, ptr3, firstflag = 0, nexthead = *head, lastend = -2;//ptr1ָ��ǰָ�룬ptr2ָ��һ��Ҫָ��ptr1�ģ�ptr3ָ��δ����ת����һ����
	while (cnt >= k) {
		//      printf("-------head=%d,nexthead=%d,cnt=%d\n",*head,nexthead,cnt);//for_test
		ptr1 = nexthead;
		ptr2 = array[ptr1].next;
		for (i = 1; i<k; i++) {
			ptr3 = array[ptr2].next;
			array[ptr2].next = ptr1;
			ptr1 = ptr2;
			ptr2 = ptr3;

		}

		array[nexthead].next = ptr3;//��Ҫ��ת��������¶���ͷβ�ڵ��ָ��
		if (firstflag == 0) {
			lastend = nexthead;
			*head = ptr1;//��Ϊ��ѭ�������ı���ptr2��ֵ�����Դ˴���ptr1 ��

		}
		else {
			array[lastend].next = ptr1;
			lastend = nexthead;
		}

		firstflag++;
		nexthead = ptr2;
		cnt -= k;
	}
}

int main()
{

	head = Input(workArray);
	ReverseList(workArray, &head, k);
	PrintList(head, workArray);
}