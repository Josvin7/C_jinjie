#include<stdio.h>
#include<windows.h>



int my_strlen(char *str) {
	//int count = 0;
	char * tmp = str;
	while (*tmp != '\0') {
		//count++;
		tmp++;
	}
	return tmp-str;
}
int main() {

	const char*str1 = "qsbqidgiqdgi";
	int a = my_strlen(str1);
	system("pause");
	return 0;
}