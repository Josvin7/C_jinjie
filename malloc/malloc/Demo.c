#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
void GetMemory(char *p)
{
	p = (char *)malloc(100);
}
char *GetMemory1(void)
{
	char p[] = "hello world";
	return p;
}

int main() {
	//char *str = NULL;
	//GetMemory(str);
	//strcpy(str, "hello world");
	//printf(str);
	char *str = NULL;
	str = GetMemory1();
	printf(str);
	system("pause");
	return 0;
}
