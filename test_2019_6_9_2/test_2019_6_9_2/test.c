#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//#define SQUARE(x) x*x//宏的定义
#define SQUARE(x) (x)*(x)//宏的定义
int Square(int x)
{
	return x*x;
}
int main()
{
	/*printf("%d\n", SQUARE(5));*/
	//printf("%d\n", SQUARE(5+4));//(5+4*5+4=29)
	printf("%d\n", SQUARE(5 + 4));//给宏的两个x带上括号，结果为81
	//printf("%d\n", Square(5 + 4));//81
	system("pause");
	return 0;
}