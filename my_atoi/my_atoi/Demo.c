#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<assert.h>
#include<windows.h>



int my_atoi(const char * str) {
	assert(str);
	int j = 0;
	while (str[j] != '\0') {
		// ���ַ���ǰ�ߵĿո�����
		while (str[j] != '\0' && str[j] == ' ') {
			j++;
		}
		//�������+  -  �������־ͽ���ѭ�������򷵻�0
		if (str[j]!='+' && str[j] != '-' && (str[j]<'0' ||str[j]>'9')) {
			return 0;
		}
		break;	
	}
	
	// �����ߵ�����˵����ͷ��+123  ����-123���ƿ�ͷ
	int ans = 0;
	int tmp = 1;
	// �� +  - ����һ�£�����tmp���+  -
	if (str[j] == '+') {
		j++;
		
	}
	if (str[j] == '-') {
		tmp = -1;
		j++;
	}
	int count = 0;
	// ��������
	while (str[j] != '\0'&& str[j] >='0' &&str[j]<='9') {
		//printf("%d", pow(10, count));
		ans += pow(10,count)*(str[j] - '0');
		count++;
		j++;
	}
	int num = 0;
	// ��תһ��
	while (ans) {
		num += pow(10, --count)*(ans % 10);
		ans = ans / 10;
	}
	return num*tmp;

}

int main() {
	//ģ��ʵ��atoi
	char str[] = "   +22675wer";
	int ans = my_atoi(str);
	printf("%d\n",ans);
	system("pause");
	return 0;
}