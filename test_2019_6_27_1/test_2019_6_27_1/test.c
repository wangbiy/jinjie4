#include <stdarg.h>
//#define _INTSIZEOF(n)((sizeof(n) + sizeof(int) - 1)\
& ~(sizeof(int) - 1)
int Avg(int n, ...)
{
	int sum = 0;
	va_list arg;
	//typedef char *  va_list;
	va_start(arg, n);//(arg=(char*)&n+((sizeof(n)+sizeof(int)-1)&~(sizeof(int)-1))
	//#define va_start _crt_va_start
    //#define _crt_va_start(ap,v)\
	( ap = (va_list)_ADDRESSOF(v) + _INTSIZEOF(v) )
	for (int i = 0; i < n; ++i)
	{
		sum += va_arg(arg, int);//(*(int*)(arg+=4-4))
		//#define va_arg _crt_va_arg
		//#define _crt_va_arg(ap,t)\
		(*(t*)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)))
	}
	va_end(arg);//arg=((char*)0)
	//#define va_end _crt_va_end 
	//#define _crt_va_end(ap) \
	( ap = (va_list)0 )
	return sum / n;
}
int main()
{
	printf("%d\n",Avg(4, 10, 20, 30, 40));
	system("pause");
	return 0;
}