#include<stdio.h>
#include<windows.h>




char* my_strcpy(char *dec,char* src) {
	char * tmp = dec;
	while (*src != '\0') {
		*dec = *src;
		dec++;
		src++;
	}
	*dec = '\0';
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





int my_strcmp(char *str,char *str1) {
	while (*str1 != '\0' && *str != '\0') {
		if (*str != *str1 ) {
			return (*str - *str1) > 0 ? 1 :  -1;
		}
		str++;
		str1++;
	}
	if (*str == '\0') {
		return -1;
	}
	else if(*str1 == '\0') {
		return 1;
	}
	return 0;
}


char * my_strstr(const char * str, const char * str1) {
	if (*str1 == '\0') {
		return 0;
	}
	char *tmp = str;
	while (*tmp != '\0') {
		char *cp = tmp;
		while (*cp != '\0'&&*str1 != '\0' && *cp == *str1) {
			cp++;
			str1++;
		}
		if (*str1 == '\0') {
			return tmp;
		}
		tmp++;
	}
	return 0;
}
int main() {


	char str[50] = "dfghjsd";
	char *str1 = "sdgg";
	//my_strcat(str,str1);
	memmove(str, str1,2);
	printf("%d",str);
	system("pause");
	return 0;
}