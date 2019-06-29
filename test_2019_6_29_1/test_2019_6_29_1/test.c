#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
#include <stdlib.h>
int binary_sort(int arr[], int size, int k)//����ҿ�
{
	int left = 0;
	int right = size;
	while (left < right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] < k)
		{
			left = mid + 1;
		}
		else if (arr[mid] > k)
		{
			right = mid;
		}
		else if (arr[mid] == k)
			return mid;
	}
	return -1;
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 10 };
	int size = sizeof(arr) / sizeof(int);
	int ret = 0;
	int k = 0;
	printf("������Ҫ�ҵ���;");
	scanf("%d", &k);
	ret = binary_sort(arr, size, k);
	if (ret == -1)
	{
		printf("�Ҳ���!\n");
	}
	else
		printf("�ҵ��������±�Ϊ%d\n", ret);
	system("pause");
	return 0;
}