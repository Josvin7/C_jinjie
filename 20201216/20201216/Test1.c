#include <stdio.h>
#include<windows.h>
//#pragma pack(8)//设置默认对齐数为8
struct S1
{
	char c1;
	int i;
	char c2;
};
//#pragma pack()//取消设置的默认对齐数，还原为默认
//#pragma pack(1)//设置默认对齐数为8
struct S2
{
	char c1;
	int i;
	char c2;
};
//#pragma pack()//取消设置的默认对齐数，还原为默认

struct S
{
	char a : 3;
	char b : 4;
	char c : 5;
	char d : 4;
};

int main()
{
	//输出的结果是什么？
	struct S s = { 0 };
	s.a = 10;
	s.b = 12;
	s.c = 3;
	s.d = 4;
	printf("%d\n", s);
	//printf("%d\n", sizeof(struct S1));
	//printf("%d\n", sizeof(struct S2));
	system("pause");
	return 0;
}