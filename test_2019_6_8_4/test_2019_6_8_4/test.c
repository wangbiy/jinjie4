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
	struct S s = { "����",20, 3.54 };
	char buf[30] = { 0 };
	struct S tmp = { 0 };
	sprintf(buf, "%s %d %lf", s.name, s.age, s.d);//���ṹ��ת��Ϊ�ַ���,�漰�������ڴ�
	printf("%s\n", buf);
	//��buf�л�ȡһ����ʽ�������ݣ�����tmp��
	sscanf(buf, "%s %d %lf", tmp.name, &(tmp.age), &(tmp.d));
	printf("%s %d %lf\n", tmp.name,tmp.age,tmp.d);
	system("pause");
	return 0;
}