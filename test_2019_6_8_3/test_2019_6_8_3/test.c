#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
struct S
{
	char name[20];
	int age;
	float i;
};
int main()
{
	/*FILE *pf = fopen("test2.txt", "w");*/
	FILE *pf = fopen("test2.txt", "r");
	//写文件
	//格式化形式写文件
	/*struct S s = { "zhangsan", 20, 3.14f };*/
	struct S s = { 0 };
	/*fprintf(pf, "%s %s %d", "zhangsan", "lisi", 20);*/
	/*fprintf(pf, "%s %d %f",s.name,s.age,s.i);*/
	fscanf(pf, "%s %d %f", s.name, &(s.age), &(s.i));
	printf("%s %d %f\n", s.name, s.age, s.i);
	fclose(pf);
	pf = NULL;
	system("pause");
	return 0;
}