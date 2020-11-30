#include<stdio.h>
#include<windows.h>



void Reverse(char *str, int len,int k) {
	
	//控制旋转后多少种结果
	for (int i = 0; i < k; i++){
		char tmp = str[0];
		for (int k = 0; k < len - 1; k++) {
			//char temp = str[k];
			str[k] = str[k + 1];


		}
		str[len - 1] = tmp;

	}
	
	//return str;
}
int main3() {
	//实现一个函数，可以左旋字符串中的k个字符。
	char str[] = "abcd";
	
	int len = strlen(str);
	int k = 0;
	printf("请输入那想要移动的位数k：");
	scanf("%d",&k);
	Reverse(str, len, k);
	for (int m = 0; m < len; m++) {
		printf("%c\n",str[m]);
	}
	
	
	system("pause");
	return 0;
}