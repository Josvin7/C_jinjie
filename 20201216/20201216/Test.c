#include<stdio.h>
#include<windows.h>





struct S1
	{
		char c1;
		int i;
		char c2;
	};
struct S2
{
	char c1;
	char c2;
	int i;
};
int main1() {
	printf("%d\n", sizeof(struct S1));
	printf("%d\n", sizeof(struct S2));
	struct S3
	{
		double d;//���������Ϊ8
		char c;//8+1
		int i;//δ�����ȼ�3�ڼ�4=>16
	};
	printf("%d\n", sizeof(struct S3));
	struct S4
	{
		char c1;//���������Ϊ1
		struct S3 s3;//�ṹ���СΪ16����������Ϊ8��1+7+16
		double d;//24+8=32
	};
	printf("%d\n", sizeof(struct S4));
	system("pause");
	return 0;
}