#include <stdio.h>
#include<windows.h>
//#pragma pack(8)//����Ĭ�϶�����Ϊ8
struct S1
{
	char c1;
	int i;
	char c2;
};
//#pragma pack()//ȡ�����õ�Ĭ�϶���������ԭΪĬ��
//#pragma pack(1)//����Ĭ�϶�����Ϊ8
struct S2
{
	char c1;
	int i;
	char c2;
};
//#pragma pack()//ȡ�����õ�Ĭ�϶���������ԭΪĬ��

struct S
{
	char a : 3;
	char b : 4;
	char c : 5;
	char d : 4;
};

int main()
{
	//����Ľ����ʲô��
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