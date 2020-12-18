#include<stdio.h>
#include<windows.h>
#pragma disable(4996)


// Ð´·¨Ò»£º
char* my_strcpy(char *dec, char* src) {
	char * tmp = dec;
	while (*src != '\0') {
		*dec = *src;
		dec++;
		src++;
	}
	*dec = '\0';
	return tmp;
}
char* my_strncpy(char *dec, char* src,int num) {
	char * tmp = dec;
	while (*src != '\0' && num-- ) {
		*dec = *src;
		dec++;
		src++;
	}
	//*dec = '\0';
	return tmp;
}


char* my_strcat(char* des, char* src) {
	char*tmp = des;
	while (*des != '\0') {
		des++;;
	}
	while (*src != '\0') {
		*des = *src;
		des++;
		src++;
	}
	return tmp;
}


char* my_strncat(char* des, char* src, int num) {
	char*tmp = des;
	while (*des != '\0') {
		des++;
	}
	while (*src != '\0' && num--) {
		*des = *src;
		des++;
		src++;
	}
	return tmp;
}

int main11() {

	const char*str1 = "qsbqidgiqdgi";
	char str2[30];
	memset(str2,0,30);
	my_strncpy(str2, str1,113);
	printf("%s",str2);
	system("pause");
	return 0;

}