#include<stdio.h>
#include<windows.h>



int IsReverse(char str1[], char str2[],int len1,int len2) {
	if (len1 != len2) {
		return -1;
	}
	//������ת������ֽ��
	for (int i = 0; i < len1;i++){
			char tmp = str1[0];
			for (int k = 0; k < len1-1;k++) {
				
				str1[k] = str1[k + 1];
				
				
			}
			str1[len1 - 1] = tmp;
			// �жϱȽ�����Ԫ���Ƿ���ͬ
			for (int m = 0; m < len1; m++) {
				if (str1[m] != str2[m]) {
					break;
				}
				if (str1[m] == str2[m] && m == len1 - 1) {
					return 1;
				}
			}
			
			
			

	}
	return -1;
}
int main2() {
	//дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ��� 
	char str1[] = "abcd";
	char str2[] = "dabc";
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (IsReverse(str1, str2, len1, len2)==1) {
		printf("true\n");
	}
	else {
		printf("flase\n");
	}
	system("pause");
	return 0;
}