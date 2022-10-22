#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int binary_search(char arr[], int k, int sz)//һ�����˾������Ĵ���������ط�������������������[]
{
	int left = 0;
	int right = sz - 1;
	while (right >= left)//�����±���ڵ������±�ʱִ��ѭ�����е���������ԭ����ǵ������±����ʱ��������±�ֵ
	{
		int mid = (left + right) / 2;//mid���м�Ԫ���±꣬mid��ѭ���ڣ���Ȼ��left��right��ֵ�ı��Ͳ��ܸ���mid��ֵ
		//������������ѧ�ϵĶ��ַ�˼��
		if (arr[mid] > k)
			right = mid - 1;
		else if (arr[mid] < k)
			left = mid + 1;
		else
			return mid;
	}
	return -1;//����������ֲ���������ʱ����-1
}
int main()
{
	char arr[] = { 1,2,3,4,5,6,7,8,9 };
	//��ֱ����binary_search�����м������������sz���Ϊ1����Ϊarr����ȥ��������Ԫ�صĵ�ַ��������arr��ָ��
	int sz = sizeof(arr) / sizeof(arr[0]);
	int k;
	scanf("%d", &k);//������Ҫ���ҵ�����
	int ret = binary_search(arr, k, sz);//������ֲ��Һ���
	if (ret == -1)//�ж��Ƿ��ҵ�ָ�����ֵ��±�
		printf("�Ҳ���ָ��������\n");
	else
		printf("�ҵ��ˣ��±���:%d\n", ret);
	return 0;

}