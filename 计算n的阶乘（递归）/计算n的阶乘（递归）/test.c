#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int Fac(int n)
{
	if (n <= 1)
		return 1;
	else
		return n * Fac(n - 1);
}
int main()
{
	int n = 1, ret;
	scanf("%d", &n);
	ret = Fac(n);
	printf("%d\n", ret);
	return 0;
}