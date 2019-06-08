#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int main()
{
	/*FILE *pf = fopen("test1.txt", "w");
	fputs("zhangsan\n", pf);
	fputs("lisi\n", pf);
	fputs("wangwu\n", pf);*/
	char buf[20] = { 0 };
	FILE *pf = fopen("test1.txt", "r");
	if (pf == NULL)
	{
		perror("fopen");
		system("pause");
		return 0;
	}
	fgets(buf, 20, pf);
	printf("%s", buf);
	fgets(buf, 20, pf);
	printf("%s", buf);
	fgets(buf, 20, pf);
	printf("%s", buf);
	fclose(pf);
	pf = NULL;
	system("pause");
	return 0;
}
