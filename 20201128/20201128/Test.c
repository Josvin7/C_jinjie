#include<stdio.h>
#include<windows.h>
int main1() {
	int a = 10;
	int b = -20;
	system("pause");
	return 0;
}
//´úÂë2
int check_sys()
{
	union
	{
		int i;
		char c;
	}un;
	un.i = 1;
	return un.c;
}

int check_sys1()
{
	int i = 1;
	return (*(char *)&i);
}
int main2()
{
	int ret = check_sys1();
	if (ret == 1)
	{
		printf("Ğ¡¶Ë\n");
	}
	else
	{
		printf("´ó¶Ë\n");
	}
	system("pause");
	return 0;
}
