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
	//��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ����ģ����д�����������ľ����в���ĳ�������Ƿ���ڡ�
	int num = 0;
	int array[4][4] = {
		{1,2,3,4},
		{ 5, 6, 7, 8 },
		{ 9, 10, 11, 12 },
		{ 13, 15, 17, 123 }
	};
	printf("����������Ҫ���ҵ�����num��");
	scanf("%d", &num);
	if (ToFind(array, num) == 1) {
		printf("��");
	}
	else{
		printf("wu");
	}

	system("pause");
	return 0;
}