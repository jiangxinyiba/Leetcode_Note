#include "Array.h"
#include "DynamicProgram.h"

int main()
{
	///////////////////////////////////////////////////////////////////////////
	////////////////////////////Array Demo/////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	Array *array = new Array();
	int result;
	int num;

	// 删除数组中的指定项，返回新数组个数
	int A[] = { 1 ,2 ,2 ,3 ,4 ,2 ,5 };
	result = array->removeElement(A, sizeof(A) / sizeof(A[0]), 2);
	cout << "删除指定项后的数组元素个数：" << endl;
	cout << result << endl;

	// 删除有序数组中的重复项，返回新数组个数
	int Asorted[] = { 1 ,2 ,2 ,3 ,4 ,4 ,5 };
	result = array->removeDuplicates(Asorted, sizeof(Asorted) / sizeof(Asorted[0]));
	cout << endl;
	cout << "删除有序数组中的重复项后的新数组个数：" << endl;
	cout << result << endl;

	// 删除有序数组中的重复项，但是允许最多两次重复的元素,返回新数组个数
	int Asorted2[] = { 1 ,2 ,2 ,3,3,3 ,4 ,4 ,5 };
	result = array->removeDuplicates_2(Asorted2, sizeof(Asorted2) / sizeof(Asorted2[0]));
	cout << endl;
	cout << "删除有序数组中的重复项后的新数组个数：" << endl;
	cout << result << endl;

	// vector数组的进位加法[从最后一位加1，满十则前位加1]
	int n[] = { 1, 2, 3, 9, 9 };
	vector<int> A3(n, n + 5);
	vector<int> A3_add1;
	A3_add1 = array->plusOne(A3);
	cout << endl;
	cout << "vector数组的进位加法：" << endl;
	for (unsigned int m = 0; m<A3_add1.size(); m++)
	{
		cout << A3_add1[m];//<<endl
		cout << " ";
	}
	cout << endl;

	// 帕斯卡三角形[二维数组]
	num = 5;
	cout << endl;
	cout << "生成行数为" << num << "的帕斯卡三角形:" << endl;
	vector<vector<int>>	PascalTria;
	PascalTria = array->pascalTriangle(num);
	for (int i = 0; i<num; i++)
	{
		for (unsigned int j = 0; j<PascalTria[i].size(); j++)
		{
			cout << PascalTria[i][j];
			cout << " ";
		}
		cout << endl;
	}
	cout << endl;

	// 帕斯卡三角形[一维数组]
	num = 4;
	cout << endl;
	cout << "生成行数为" << num << "的帕斯卡三角形:" << endl;
	vector<int>	PascalTria1;
	PascalTria1 = array->pascalTriangle_onearray(num);
	for (unsigned int j = 0; j<PascalTria1.size(); j++)
	{
		cout << PascalTria1[j];
		cout << " ";
	}
	cout << endl;

	// 合并有序数组A和B
	cout << endl;
	cout << "合并有序数组A和B:" << endl;
	int A1[8] = { 1, 2, 3, 9 };
	int B1[] = { 2, 5, 6, 8 };
	int nA1 = 4;//sol->length(A1); 
	int nB1 = 4;//sol->length(B1);  
	int *AB;
	AB = array->merge(A1, B1, nA1, nB1);
	for (int i = 0; i<nA1 + nB1; i++)
	{
		cout << AB[i] << " ";
	}
	cout << endl;

	// 求数组中两个数值的序号，两个数值求和等于指定值
	 cout<<endl;
	 cout<<"求数组中两个数值的序号:"<< endl;
	 int n2[] = {1, 2, 3, 9, 11};
	 vector<int> numbers(n2, n2+5);
	 vector<int> TwoTarget;
	 int target = 12;
	 TwoTarget = array->twoSum(numbers,target);	
	 for (int numTarget=0;numTarget<2;numTarget++)
	 {
	 	cout<<TwoTarget[numTarget]<<" ";
	 }
	 cout<<endl;

	// 列出数组中三个数值求和等于0的所有情况
	cout << endl;
	cout << "列出数组中三个数值求和等于0的所有情况:" << endl;
	int n3[] = { 1, 0, 3, 2, 11, -3, 0 };
	vector<int> numbers3(n3, n3 + 7);
	vector<vector<int>> ThreeTarget;
	ThreeTarget = array->threeSum(numbers3);
	for (unsigned int numTarget31 = 0; numTarget31<ThreeTarget.size(); numTarget31++)
	{
		for (unsigned int numTarget32 = 0; numTarget32<ThreeTarget[0].size(); numTarget32++)
		{
			cout << ThreeTarget[numTarget31][numTarget32] << " ";
		}
		cout << endl;
	}

	// 选择有序数组中的最小值
	cout << endl;
	cout << "选择有序数组中的最小值:" << endl;
	int n4[] = { 4,5,6,7,0,1,2,3 };
	vector<int>	number4(n4, n4 + 8);
	result = array->findMin(number4);
	cout << result << endl;

	// 求取直方图中最大的长方形区域
	 cout<<endl;
	 cout<<"求取直方图中最大的长方形区域:"<< endl;
	 int n5[] = {2,1,5,6,2,3};
	 vector<int>	number5(n5, n5+6);
	 result = array->largestRectangleArea(number5);
	 cout<< result << endl;

	// 求取矩阵中的最大矩形面积
	 cout<<endl;
	 cout<<"求取矩阵中的最大矩形面积:"<< endl;
	 int n6[4][4] = {0,0,0,0,0,1,1,1,1,1,1,0,0,1,0,0};
	 ///给vector赋二维数组
	 vector<vector<int>> number6(4,vector<int>(4)) ;  
	 for(int i = 0; i < 4; ++i)
	 {
	 	for(int j = 0; j < 4; ++j)
	 	{
	 		number6[i][j]=n6[i][j];
	 	}
	 }
	    result = array->maximalRectangle(number6);
	 cout<< result << endl;

	// 判断回文数
	num = 12321;
	cout << endl;
	cout << "判断回文数" << num << ":" << endl;
	cout << boolalpha << array->isPalindrome(num) << endl;

	// 寻找有序矩阵中的指定元素 O(n^2)
	cout << endl;
	cout << "寻找有序矩阵中的指定元素:" << endl;
	int n7[3][4] = { 1,3,5,7,10,11,17,20,25,30,34,60 };
	///给vector赋二维数组
	vector<vector<int>> number7(3, vector<int>(4));
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			number7[i][j] = n7[i][j];
		}
	}
	num = 17;
	cout << boolalpha << array->searchMatrix(number7, num) << endl;

	// 寻找有序数组中指定元素的位置
	int n8[] = { 1,3,5,6 };
	num = 1;
	cout << endl;
	cout << "寻找有序数组中指定元素" << num << "的位置：" << endl;
	cout << array->searchInsert(n8, 4, num) << endl;

	// n阶乘
	num = 5;
	cout << endl;
	cout << num << "阶乘为：" << endl;
	result = array->factorial(num);
	cout << result << endl;

	//  Fibonacci 数列
	num = 6;
	cout << endl;
	cout << "第" << num << "个斐波那契数是：" << endl;
	result = array->Fibonacci(num);
	cout << result << endl;

	//  判断数字是否是2的整数次幂
	num = 8;
	cout << endl;
	bool isTwomi = array->isPowerOfTwo(num);
	cout << num << ((isTwomi) ? "是" : "不是") << "2的整数次幂" << endl;

	///////////////////////////////////////////////////////////////////////////
	///////////////////DynamicProgram Demo/////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////

	DynamicProgram *DP = new DynamicProgram();
	cout<<endl;
	cout<<"找到数组中的最小值作为买入点从之后的数据中找到高点卖出"<< endl;
	int n9[] = {10,3,1,5,2};
	vector<int> numbers9(n9, n9+5);
	cout<<"最高价差可以达到："<< DP->maxProfit(numbers9)<<endl;

	cout << endl;
	int m10 = 4, n10 = 3;
	cout << m10<<"*"<<n10<<"矩阵的最短路径:" << DP->uniquePaths(m10,n10) << endl;


	system("pause");
	return 0;
}
