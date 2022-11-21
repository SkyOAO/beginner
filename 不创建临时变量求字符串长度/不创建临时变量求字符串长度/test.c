#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int my_strlen(char *str)
{
	if (*str != '\0')//解引用用来找到字符串hello world,\0不算做数组长度的组成成分
		return 1 + my_strlen(str + 1);//数组是指针，指针+1会向后读字符串
	else
		return 0;//用来停下函数的调用（递归）
}
int main()
{
	char arr[] = "hello world";
	int len = my_strlen(arr);//向my_strlen函数传过去数组的首元素地址
	printf("len=%d", len);
	return 0;
}