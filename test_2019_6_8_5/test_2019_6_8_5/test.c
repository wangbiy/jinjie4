#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		perror("fpoen");
		return 0;
	}
	printf("%c\n", fgetc(pf));
	/*fseek(pf, 3, SEEK_CUR);*/
	/*fseek(pf, -2, SEEK_END);*///���ļ�ĩβƫ��
	fseek(pf, 4, SEEK_SET);//��ʼλ��ƫ��
	printf("%c\n", fgetc(pf));
	printf("%c\n", fgetc(pf));
	rewind(pf);
	printf("%c\n", fgetc(pf));//���ļ��ص���ʼ��λ��
	system("pause");
	return 0;
}