#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//struct S
//{
//	int n;
//	int *arr;
//};
struct S
{
	int n;
	int arr[];//柔性数组成员
};
int main()
{
	/*struct S *ps = (struct S*)malloc(sizeof(struct S));
	int i = 0;
	ps->n = 10;
	ps->arr = (int*)malloc(10 * sizeof(int));
	for (i = 0; i < 10; ++i)
	{
		ps->arr[i] = i + 1;
	}
	for (i = 0; i < 10; ++i)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
	free(ps->arr);
	free(ps);
	ps = NULL;*/
	struct S *ptr = malloc(sizeof(struct S) + 10*sizeof(int));
	int i = 0;
	ptr->n = 10;
	for (i = 0; i < 10; ++i)
	{
		ptr->arr[i] = i + 1;
		printf("%d ", ptr->arr[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}