#include<stdio.h>
#include<windows.h>

int CompInt(const void* xx,const void* yy) {
	int x = *(int *)xx;
	int y = *(int *)yy;
	return x - y;

}
int CompDouble(const void* xx, const void* yy) {
	double x = *(double *)xx;
	double y = *(double *)yy;
	return x > y ? 1:-1;

}
int CompChar(const void* _a, const void* _b)//参数格式固定
{
	char* a = (char*)_a;    //强制类型转换
	char* b = (char*)_b;
	return *a - *b;
}
int CompString(const void* _a, const void* _b)//参数格式固定
{
	char* a = (char*)_a;//强制类型转换
	char* b = (char*)_b;
	return strcmp(a, b);
}

int main0() {
	int arr[] = {1,23,45,78,5542,567,86,421,345};
	double arr1[] = {12.2,12.3,45.6,2.3,45.6};
	int num = sizeof(arr1) / sizeof(arr1[0]);
	qsort(arr1, num, sizeof(double), CompDouble);
	system("pause");
	return 0;
}