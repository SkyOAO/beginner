#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main()
{
	int i;
	char password[20] = { 0 };//设定密码长度范围
	for (i = 0; i < 3; i++)//若i=1;i<=3;则无法触发if(i==3)下的执行语句
	{
		printf("请输入密码:");
		scanf("%s", password);//若放在for循环外面，输错一次密码后就会退出程序
		if (strcmp(password, "66547@89") == 0)//strcmp函数用来比较两个字符串是否相等，双引号内可放置任何20位以内的字符
		{
			printf("登录成功\n");
			break;
		}
		else
			printf("密码错误\n");
	}
	if (i == 3)
		printf("三次密码均错误，退出程序\n");
	return 0;
}
