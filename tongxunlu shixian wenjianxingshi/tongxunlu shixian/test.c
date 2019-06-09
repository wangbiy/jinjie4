#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
#include <stdlib.h>
#include "contact.h"
void menu()
{
	printf("*************************************\n");
	printf("*************** ͨѶ¼ **************\n");
	printf("***        1.add     2.del        ***\n");
	printf("***        3.search  4.modify     ***\n");
	printf("***        5.show    6.sort       ***\n");
	printf("***        7.empty   0. exit      ***\n");
	printf("*************************************\n");
}
void test()
{
	Contact con;//����ͨѶ¼
	InitContact(&con);//��ʼ��
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case EMPTY:
			EmptyContact(&con);
		case EXIT:
			SaveContact(&con);
			DestroyContact(&con);
			printf("�˳�!\n");
			break;
		default:
			printf("ѡ�����!\n");
			break;	
		}
	} while (input);
}
int main()
{
	test();
	system("pause");
	return 0;
}