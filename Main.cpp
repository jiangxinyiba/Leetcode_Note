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

	// ɾ�������е�ָ����������������
	int A[] = { 1 ,2 ,2 ,3 ,4 ,2 ,5 };
	result = array->removeElement(A, sizeof(A) / sizeof(A[0]), 2);
	cout << "ɾ��ָ����������Ԫ�ظ�����" << endl;
	cout << result << endl;

	// ɾ�����������е��ظ���������������
	int Asorted[] = { 1 ,2 ,2 ,3 ,4 ,4 ,5 };
	result = array->removeDuplicates(Asorted, sizeof(Asorted) / sizeof(Asorted[0]));
	cout << endl;
	cout << "ɾ�����������е��ظ����������������" << endl;
	cout << result << endl;

	// ɾ�����������е��ظ������������������ظ���Ԫ��,�������������
	int Asorted2[] = { 1 ,2 ,2 ,3,3,3 ,4 ,4 ,5 };
	result = array->removeDuplicates_2(Asorted2, sizeof(Asorted2) / sizeof(Asorted2[0]));
	cout << endl;
	cout << "ɾ�����������е��ظ����������������" << endl;
	cout << result << endl;

	// vector����Ľ�λ�ӷ�[�����һλ��1����ʮ��ǰλ��1]
	int n[] = { 1, 2, 3, 9, 9 };
	vector<int> A3(n, n + 5);
	vector<int> A3_add1;
	A3_add1 = array->plusOne(A3);
	cout << endl;
	cout << "vector����Ľ�λ�ӷ���" << endl;
	for (unsigned int m = 0; m<A3_add1.size(); m++)
	{
		cout << A3_add1[m];//<<endl
		cout << " ";
	}
	cout << endl;

	// ��˹��������[��ά����]
	num = 5;
	cout << endl;
	cout << "��������Ϊ" << num << "����˹��������:" << endl;
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

	// ��˹��������[һά����]
	num = 4;
	cout << endl;
	cout << "��������Ϊ" << num << "����˹��������:" << endl;
	vector<int>	PascalTria1;
	PascalTria1 = array->pascalTriangle_onearray(num);
	for (unsigned int j = 0; j<PascalTria1.size(); j++)
	{
		cout << PascalTria1[j];
		cout << " ";
	}
	cout << endl;

	// �ϲ���������A��B
	cout << endl;
	cout << "�ϲ���������A��B:" << endl;
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

	// ��������������ֵ����ţ�������ֵ��͵���ָ��ֵ
	 cout<<endl;
	 cout<<"��������������ֵ�����:"<< endl;
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

	// �г�������������ֵ��͵���0���������
	cout << endl;
	cout << "�г�������������ֵ��͵���0���������:" << endl;
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

	// ѡ�����������е���Сֵ
	cout << endl;
	cout << "ѡ�����������е���Сֵ:" << endl;
	int n4[] = { 4,5,6,7,0,1,2,3 };
	vector<int>	number4(n4, n4 + 8);
	result = array->findMin(number4);
	cout << result << endl;

	// ��ȡֱ��ͼ�����ĳ���������
	 cout<<endl;
	 cout<<"��ȡֱ��ͼ�����ĳ���������:"<< endl;
	 int n5[] = {2,1,5,6,2,3};
	 vector<int>	number5(n5, n5+6);
	 result = array->largestRectangleArea(number5);
	 cout<< result << endl;

	// ��ȡ�����е����������
	 cout<<endl;
	 cout<<"��ȡ�����е����������:"<< endl;
	 int n6[4][4] = {0,0,0,0,0,1,1,1,1,1,1,0,0,1,0,0};
	 ///��vector����ά����
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

	// �жϻ�����
	num = 12321;
	cout << endl;
	cout << "�жϻ�����" << num << ":" << endl;
	cout << boolalpha << array->isPalindrome(num) << endl;

	// Ѱ����������е�ָ��Ԫ�� O(n^2)
	cout << endl;
	cout << "Ѱ����������е�ָ��Ԫ��:" << endl;
	int n7[3][4] = { 1,3,5,7,10,11,17,20,25,30,34,60 };
	///��vector����ά����
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

	// Ѱ������������ָ��Ԫ�ص�λ��
	int n8[] = { 1,3,5,6 };
	num = 1;
	cout << endl;
	cout << "Ѱ������������ָ��Ԫ��" << num << "��λ�ã�" << endl;
	cout << array->searchInsert(n8, 4, num) << endl;

	// n�׳�
	num = 5;
	cout << endl;
	cout << num << "�׳�Ϊ��" << endl;
	result = array->factorial(num);
	cout << result << endl;

	//  Fibonacci ����
	num = 6;
	cout << endl;
	cout << "��" << num << "��쳲��������ǣ�" << endl;
	result = array->Fibonacci(num);
	cout << result << endl;

	//  �ж������Ƿ���2����������
	num = 8;
	cout << endl;
	bool isTwomi = array->isPowerOfTwo(num);
	cout << num << ((isTwomi) ? "��" : "����") << "2����������" << endl;

	///////////////////////////////////////////////////////////////////////////
	///////////////////DynamicProgram Demo/////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////

	DynamicProgram *DP = new DynamicProgram();
	cout<<endl;
	cout<<"�ҵ������е���Сֵ��Ϊ������֮����������ҵ��ߵ�����"<< endl;
	int n9[] = {10,3,1,5,2};
	vector<int> numbers9(n9, n9+5);
	cout<<"��߼۲���Դﵽ��"<< DP->maxProfit(numbers9)<<endl;

	cout << endl;
	int m10 = 4, n10 = 3;
	cout << m10<<"*"<<n10<<"��������·��:" << DP->uniquePaths(m10,n10) << endl;


	system("pause");
	return 0;
}
