#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int my_strlen(char *str)
{
	if (*str != '\0')//�����������ҵ��ַ���hello world,\0���������鳤�ȵ���ɳɷ�
		return 1 + my_strlen(str + 1);//������ָ�룬ָ��+1�������ַ���
	else
		return 0;//����ͣ�º����ĵ��ã��ݹ飩
}
int main()
{
	char arr[] = "hello world";
	int len = my_strlen(arr);//��my_strlen��������ȥ�������Ԫ�ص�ַ
	printf("len=%d", len);
	return 0;
}