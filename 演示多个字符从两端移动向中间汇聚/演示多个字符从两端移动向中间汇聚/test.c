#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<Windows.h>
int main()
{
	char arr1[] = "hello world!!!";
	char arr2[] = "##############";
	int left = 0;
	int right = strlen(arr1) - 1;
	while (left <= right)
	{
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		printf("%s\n", arr2);
		Sleep(1000);
		system("cls");//注意system要放到Sleep下面用来清屏以达到想要的效果
		left++;
		right--;
	}
	printf("%s\n", arr2);//为了让程序运行的最后能够显示hello world，可以在末尾打印arr2
	return 0;
}