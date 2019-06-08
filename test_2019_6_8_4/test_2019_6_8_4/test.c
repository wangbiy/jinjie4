#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
#include <stdlib.h>
struct S
{
	char name[20];
	int age;
	double d;

};
int main()
{
	struct S s = { "张三",20, 3.54 };
	char buf[30] = { 0 };
	struct S tmp = { 0 };
	sprintf(buf, "%s %d %lf", s.name, s.age, s.d);//将结构体转换为字符串,涉及到的是内存
	printf("%s\n", buf);
	//从buf中获取一个格式化的数据，放入tmp中
	sscanf(buf, "%s %d %lf", tmp.name, &(tmp.age), &(tmp.d));
	printf("%s %d %lf\n", tmp.name,tmp.age,tmp.d);
	system("pause");
	return 0;
}