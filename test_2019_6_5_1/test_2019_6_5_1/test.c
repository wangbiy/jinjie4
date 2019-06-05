#define _CRT_SECURE_NO_WARNINGS1 
#include <stdio.h>
#include <stdlib.h>
struct S
{
	int n;
	char arr[];//柔性数组成员
};
int main()
{
	struct S *p=(struct S*)malloc(sizeof(struct S) + 10 * (sizeof(char)));
	int i = 0;
	struct S *ptr;
	p->n = 10;
	for (i = 0; i < 10; ++i)
	{
		p->arr[i] = i + 1;
		printf("%d ", p->arr[i]);
	}
	printf("\n");
	ptr = realloc(p,sizeof(struct S)+20 * (sizeof(char)));
	if (ptr != NULL)
	{
		p = ptr;
	}
	p->n = 20;
	for (i = 0; i < 20; ++i)
	{
		p->arr[i] = i + 1;
		printf("%d ", p->arr[i]);
	}
	printf("\n");
	free(p);
	p = NULL;
	system("pause");
	return 0;
}