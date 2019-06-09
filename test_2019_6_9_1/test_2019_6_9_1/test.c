#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i = 0;
	FILE* pf = fopen("log.txt", "w");
	for (i = 0; i < 10; ++i)
	{
		fprintf(pf,"file:%s line=%d date=%s time=%s i=%d\n", __FILE__, __LINE__,\
			__DATE__,__TIME__,i);//Ô¤´¦Àí·ûºÅ
	}
	fclose(pf);
	pf = NULL;
	system("pause");
	return 0;
}