#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int main()
{
	/*FILE *pf = fopen("test.txt", "w");
	fputc('a', pf);
	fputc('b', pf);
	fputc('c', pf);*/
	FILE *pf = fopen("test.txt", "r");
	printf("%c\n",fgetc(pf));
	printf("%c\n", fgetc(pf));
	printf("%c\n", fgetc(pf));
	fclose(pf);
	pf = NULL;

	//char arr[10] = { 0 };
	//int ch = 0;
	//printf("����������:>");
	//scanf("%s", &arr);
	//printf("��ȷ��Y/N:");
	///*fflush(stdin);*/
	//while (getchar() != '\n')//���뻺����
	//{
	//	;
	//}
	//ch = getchar();
	//if (ch == 'Y')
	//	printf("yes\n");
	//if (ch == 'N')
	//	printf("no\n");

	system("pause");
	return 0;
}