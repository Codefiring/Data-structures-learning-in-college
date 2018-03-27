#include<stdio.h>
int main() {
	int result = 0, thissum = 0, N, digit[10005], first = 0, begin = 0, last = 0;
	scanf("%d", &N);
	scanf("%d", digit);
	/*我们要先判断一个数的情况，如果不判断的话，result初始值为0,在赋值的过程中result不可能小于0，但确实存在负数的情况*/
	result = thissum = digit[0];
	for (int i = 1; i<N; i++) {
		scanf("%d", digit + i);
		if (thissum >= 0)
			thissum += digit[i];
		else {
			thissum = digit[i];
			begin = i;            //begin表示当前最大和的开始位置
		}
		if (thissum>result) {    //如果当前最大和比结果大则更新结果以及起始位置
			last = i;
			first = begin;
			result = thissum;
		}
	}
	if (result<0) {               //如果最终结果为负数，则输出首尾元素
		result = 0;
		first = 0;
		last = N - 1;
	}
	printf("%d %d %d", result, digit[first], digit[last]);
	return 0;
}