#include<stdio.h>
#include<windows.h>


int ToFind(int array[][4], int num) {
	
	int i = 0;
	int j = 3;
	while (1) {
		if (i < 4 && array[i][j] < num) {
			i++;
		}
		else if (j >= 0 && array[i][j] > num) {
			j--;
		}
		else if (array[i][j] == num) {
			return 1;
		}
		if (i >= 4 || j < 0) {
			return -1;
		}
	}

}
int main() {
	//有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，请编写程序在这样的矩阵中查找某个数字是否存在。
	int num = 0;
	int array[4][4] = {
		{1,2,3,4},
		{ 5, 6, 7, 8 },
		{ 9, 10, 11, 12 },
		{ 13, 15, 17, 123 }
	};
	printf("请输入那想要查找的数字num：");
	scanf("%d", &num);
	if (ToFind(array, num) == 1) {
		printf("有");
	}
	else{
		printf("wu");
	}

	system("pause");
	return 0;
}