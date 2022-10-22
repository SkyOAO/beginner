#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int binary_search(char arr[], int k, int sz)//一个本人经常犯的错误，在这个地方数组名后面总是忘加[]
{
	int left = 0;
	int right = sz - 1;
	while (right >= left)//在右下标大于等于左下标时执行循环，有等于条件的原因就是当左右下标相等时即可输出下标值
	{
		int mid = (left + right) / 2;//mid是中间元素下标，mid在循环内，不然当left和right的值改变后就不能更新mid的值
		//接下来就是数学上的二分法思想
		if (arr[mid] > k)
			right = mid - 1;
		else if (arr[mid] < k)
			left = mid + 1;
		else
			return mid;
	}
	return -1;//当输入的数字不在数组中时返回-1
}
int main()
{
	char arr[] = { 1,2,3,4,5,6,7,8,9 };
	//若直接在binary_search函数中计算数组个数则sz结果为1，因为arr传过去的是其首元素的地址，本质上arr是指针
	int sz = sizeof(arr) / sizeof(arr[0]);
	int k;
	scanf("%d", &k);//输入需要查找的数字
	int ret = binary_search(arr, k, sz);//定义二分查找函数
	if (ret == -1)//判断是否找到指定数字的下标
		printf("找不到指定的数字\n");
	else
		printf("找到了，下标是:%d\n", ret);
	return 0;

}