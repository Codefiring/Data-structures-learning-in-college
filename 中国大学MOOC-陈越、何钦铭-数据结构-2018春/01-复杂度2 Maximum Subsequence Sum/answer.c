#include<stdio.h>
int main() {
	int result = 0, thissum = 0, N, digit[10005], first = 0, begin = 0, last = 0;
	scanf("%d", &N);
	scanf("%d", digit);
	/*����Ҫ���ж�һ�����������������жϵĻ���result��ʼֵΪ0,�ڸ�ֵ�Ĺ�����result������С��0����ȷʵ���ڸ��������*/
	result = thissum = digit[0];
	for (int i = 1; i<N; i++) {
		scanf("%d", digit + i);
		if (thissum >= 0)
			thissum += digit[i];
		else {
			thissum = digit[i];
			begin = i;            //begin��ʾ��ǰ���͵Ŀ�ʼλ��
		}
		if (thissum>result) {    //�����ǰ���ͱȽ��������½���Լ���ʼλ��
			last = i;
			first = begin;
			result = thissum;
		}
	}
	if (result<0) {               //������ս��Ϊ�������������βԪ��
		result = 0;
		first = 0;
		last = N - 1;
	}
	printf("%d %d %d", result, digit[first], digit[last]);
	return 0;
}