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
	/*fseek(pf, -2, SEEK_END);*///从文件末尾偏移
	fseek(pf, 4, SEEK_SET);//起始位置偏移
	printf("%c\n", fgetc(pf));
	printf("%c\n", fgetc(pf));
	rewind(pf);
	printf("%c\n", fgetc(pf));//让文件回到起始的位置
	system("pause");
	return 0;
}