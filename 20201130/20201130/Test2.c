#include<stdio.h>
#include<windows.h>



void Reverse(char *str, int len,int k) {
	
	//������ת������ֽ��
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
	//ʵ��һ�����������������ַ����е�k���ַ���
	char str[] = "abcd";
	
	int len = strlen(str);
	int k = 0;
	printf("����������Ҫ�ƶ���λ��k��");
	scanf("%d",&k);
	Reverse(str, len, k);
	for (int m = 0; m < len; m++) {
		printf("%c\n",str[m]);
	}
	
	
	system("pause");
	return 0;
}