#include <stdio.h>
#include<windows.h>

#include <string.h>
int main11()
{
	char str[] = "- This, a sample string.";
	char * pch;
	printf("Splitting string \"%s\" into tokens:\n", str);
	pch = strtok(str, " ,.-");
	while (pch != NULL)
	{
		printf("%s\n", pch);
		pch = strtok(NULL, " ,.-");
	}
	system("pause");

	return 0;
}
int main()
{
	const char*str1 = "abcdef";
	const char*str2 = "bbb";
	unsigned int a = strlen(str2);
	unsigned int b = strlen(str1);
	unsigned int c = strlen(str2)-strlen(str1);
	if (strlen(str2) - strlen(str1)>0)
	{
		printf("str2>str1\n");
	}
	else
	{
		printf("srt1>str2\n");
	}
	system("pause");
	return 0;
}