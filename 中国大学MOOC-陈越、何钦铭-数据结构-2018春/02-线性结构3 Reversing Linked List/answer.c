/*
评测结果
时间  结果  得分  题目  编译器 用时（ms）  内存（MB）  用户
2017-07-08 15:54    答案正确    25  5-2 gcc 131 3
测试点结果
测试点 结果  得分/满分   用时（ms）  内存（MB）
测试点1    答案正确    12/12   2   1
测试点2    答案正确    3/3 14  1
测试点3    答案正确    2/2 1   1
测试点4    答案正确    2/2 2   1
测试点5    答案正确    2/2 2   1
测试点6    答案正确    3/3 131 3
测试点7    答案正确    1/1 2   1
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
	首先用count求链表长度，放到cnt中保存。每次执行cnt自身减掉k，如果cnt<k则不进行翻转
	然后使用ptr1 ptr2 ptr3 三个指针
	ptr1为当前节点 ptr2为下一个节点 将ptr1->ptr2改为ptr2->ptr1。因为ptr2中的next原有内容会丢失，故用ptr3保存ptr2的下一个节点
	执行完一次后，k个节点区间内，头尾互换。
	故lastend保存前一区块的末端，是上一区间的头节点
	nexthead即下一区块的头结点，同样也是该区块翻转完后的末端。于是提前用lastend=nexthead保存。
	*/
	int cnt;
	if (k == 1)
		return;
	cnt = count(*head, array);
	int i, ptr1, ptr2, ptr3, firstflag = 0, nexthead = *head, lastend = -2;//ptr1指当前指针，ptr2指下一个要指向ptr1的，ptr3指向还未做反转的下一个。
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

		array[nexthead].next = ptr3;//主要反转做完后，重新定义头尾节点的指向。
		if (firstflag == 0) {
			lastend = nexthead;
			*head = ptr1;//因为在循环中最后改变了ptr2的值，所以此处用ptr1 。

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