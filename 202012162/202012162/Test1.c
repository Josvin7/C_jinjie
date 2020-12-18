#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

void Sort(int *array,int size) {
	for (int i = 0; i < size-1;i++) {
		int flag = 0;
		for (int j = 0; j < size - i - 1;j++) {
			if (array[j] > array[j + 1]) {
				int tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				flag = 1;
			}
		}
		if (flag == 0) {
			break;
		}
	}

}
void ToFindSigle(int *array, int *ans, int size) {
	Sort(array, size);
	int i = 0, j = 0;
	for (; i < size-1;i++) {
		//printf("%d  ",array[i]);

		if (array[i] != array[i + 1]) {
			ans[j] = array[i];
			j++;
			continue;
		}
		i++;

	}
	if (i == size - 1) {
		ans[1] = array[size-1];
	}
}

int main() {
	int array[] = { 1, 1, 2, 2, 3, 4, 5, 4, 3, 6, 7, 6, 7, 8, 8, 87, 87, 543, 543, 23, 23 ,888};
	int ans[2] = {0,0};
	int size = sizeof(array)/sizeof(int);
	ToFindSigle(array, ans,size);
	printf("%d",size);

	system("pause");
	return 0;
}