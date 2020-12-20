#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<assert.h>
#include<windows.h>



int my_atoi(const char * str) {
	assert(str);
	int j = 0;
	while (str[j] != '\0') {
		// 将字符串前边的空格跳过
		while (str[j] != '\0' && str[j] == ' ') {
			j++;
		}
		//如果出现+  -  或者数字就结束循环，否则返回0
		if (str[j]!='+' && str[j] != '-' && (str[j]<'0' ||str[j]>'9')) {
			return 0;
		}
		break;	
	}
	
	// 程序走到这里说明开头是+123  或者-123类似开头
	int ans = 0;
	int tmp = 1;
	// 对 +  - 处理一下，利用tmp标记+  -
	if (str[j] == '+') {
		j++;
		
	}
	if (str[j] == '-') {
		tmp = -1;
		j++;
	}
	int count = 0;
	// 处理数字
	while (str[j] != '\0'&& str[j] >='0' &&str[j]<='9') {
		//printf("%d", pow(10, count));
		ans += pow(10,count)*(str[j] - '0');
		count++;
		j++;
	}
	int num = 0;
	// 反转一下
	while (ans) {
		num += pow(10, --count)*(ans % 10);
		ans = ans / 10;
	}
	return num*tmp;

}

int main() {
	//模拟实现atoi
	char str[] = "   +22675wer";
	int ans = my_atoi(str);
	printf("%d\n",ans);
	system("pause");
	return 0;
}