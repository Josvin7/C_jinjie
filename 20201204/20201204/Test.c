#include<stdio.h>
#include<windows.h>





void * my_memmove(void * des, const void * src, int num) {
	char *_des = (char *)des;
	char *_src = (char *)src;
	
	if (_des > _src && (_des + num) < _src) {
		///从后往前移动
		_src = _src + num - 1;
		_des = _des + num - 1;
		while (num--) {
			*_des = *_src;
			_des--;
			_src--;
		}
	}
	else {
		// 从前往后移动
		while (num--) {
			*_des = *_src;
			_des++;
			_src++;
		}
	}

	return des;
}
int main() {

	char str[50] = "hdgfigfangwenhui";
	my_memmove(str,str+1,3);
	printf("%s",str);
	system("pause");

	return 0;
}