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
		system("cls");//ע��systemҪ�ŵ�Sleep�������������Դﵽ��Ҫ��Ч��
		left++;
		right--;
	}
	printf("%s\n", arr2);//Ϊ���ó������е�����ܹ���ʾhello world��������ĩβ��ӡarr2
	return 0;
}