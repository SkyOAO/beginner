#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main()
{
	int i;
	char password[20] = { 0 };//�趨���볤�ȷ�Χ
	for (i = 0; i < 3; i++)//��i=1;i<=3;���޷�����if(i==3)�µ�ִ�����
	{
		printf("����������:");
		scanf("%s", password);//������forѭ�����棬���һ�������ͻ��˳�����
		if (strcmp(password, "66547@89") == 0)//strcmp���������Ƚ������ַ����Ƿ���ȣ�˫�����ڿɷ����κ�20λ���ڵ��ַ�
		{
			printf("��¼�ɹ�\n");
			break;
		}
		else
			printf("�������\n");
	}
	if (i == 3)
		printf("��������������˳�����\n");
	return 0;
}
