#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//#define SQUARE(x) x*x//��Ķ���
#define SQUARE(x) (x)*(x)//��Ķ���
int Square(int x)
{
	return x*x;
}
int main()
{
	/*printf("%d\n", SQUARE(5));*/
	//printf("%d\n", SQUARE(5+4));//(5+4*5+4=29)
	printf("%d\n", SQUARE(5 + 4));//���������x�������ţ����Ϊ81
	//printf("%d\n", Square(5 + 4));//81
	system("pause");
	return 0;
}