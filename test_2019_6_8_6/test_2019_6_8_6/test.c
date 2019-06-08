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
	/*FILE *pf = fopen("test.txt", "wb");
	struct S s = { "zhangsan", 20, 5.6 };*/
	FILE *pf = fopen("test.txt", "rb");
	struct S s = {0};
	if (pf == NULL)
	{
		perror("fopen");
		return 0;
	}
	fread(&s, sizeof(struct S), 1, pf);
	printf("%s %d %f\n", s.name, s.age, s.d);
	system("pause");
	return 0;
}