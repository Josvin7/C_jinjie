#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<windows.h>

// 比较函数
int CompInt(const void* xp,const void* yp) {
	int x = *(const int*)xp;//xp是void*类型，我们要用于int类型数组排序所以先强转为int*，然后在解引用为x的值进行比较
	int y = *(const int*)yp;
	if (x > y) {
		return -1;
	}
	else if (x == y) {
		return 0;
	}
	else {
		return 1;
	}

}
//交换函数
void swap(char *p, char *q, size_t num) {
	while (num--) {
		char temp = *p;
		*p = *q;
		*q = temp;
		p++;
		q++;
	}
}
// my_sort函数
void my_qsort(void *base,size_t num,size_t size,int (*comp)(const void*,const void*)) {
	assert(base);
	assert(comp);
	char *p = (char*)base;
	for (size_t i = 0; i < num - 1; i++) {
		int flag = 0;
		for (size_t j = 0; j < num - 1 - i; j++) {
			if (comp(p + j*size, p + (j + 1)*size)>0) {
				swap(p+j*size,p+(j+1)*size,size);
				flag = 1;
			}
		}
		if (flag == 0) {
			break;
		}
	}
}

int main() {
	int arr[] = { 1, 23, 4, 5, 65, 32, 124, 675 };
	
	int num = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, num, sizeof(int), CompInt);
	
	system("pause");
	return 0;
}