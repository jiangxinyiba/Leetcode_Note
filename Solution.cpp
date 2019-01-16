#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution	
{
public:
	int	removeElement(int A[],int n,int	elem);
	int	removeDuplicates(int A[],int n)	;
	int	removeDuplicates_2(int A[],int n);
	vector<int> fun1(int num);
	vector<int>	plusOne(vector<int>	&digits);
};

// ȥ���ظ�Ԫ��
int	Solution::removeElement(int A[],int n,int elem)	
{
	int	i=0;
	int j =	0;
	for(i=0; i<n; i++)	
	{
		if(A[i] == elem)	
		{
			continue;
		}
		A[j] = A[i];
		j++;
	}
	return j;
}

// ȥ�����������е��ظ�Ԫ��
int	Solution::removeDuplicates(int A[],int n)	
{// A is a sorted array!
	if(n==0)	
	{
		return	0;
	}

	int	j=0;
	for(int	i=1;i<n;i++)	
	{
		if(A[j]!=A[i])	
		{
			A[++j]=A[i];
		}
	}
	return	j+1;
}

// ȥ�������������ظ�Ԫ�أ�����������������ظ���Ԫ��
int	Solution::removeDuplicates_2(int	A[],int	n)	
{
	if(n == 0)	
	{
		return	0;
	}
	int	j = 0;
	int	num	= 0;
	for(int	i =	1;i < n; i++)	
	{
		if(A[j]	== A[i])	
		{// ��ͬ���ж�num��num<2��ʾ�ظ���ֻ������������2������ȥ��[num>2,������]
			num++;
			if(num<2)	
			{//���numС��2����ʾ��ʱ��һ���ظ��������Ա�����
				A[++j]=A[i];
			}
		}	
		else	
		{// ��ͬ����������߼���j����һλ������Ai
			A[++j] = A[i];
			num	= 0;
		}
	}
	return j+1;
}

// vector����Ľ�λ�ӷ�[�����һλ��1����ʮ��ǰλ��1]
vector<int>	Solution::plusOne(vector<int>	&digits)	
{
	vector<int>	res(digits.size(),0);
	int	sum	= 0;
	int	one	= 1;
	for(int	i = digits.size()-1;i >= 0; i--)	
	{
		sum	= one+digits[i];
		one	= sum/10;
		res[i]=	sum%10;
	}
	if(one > 0)	
	{
		res.insert(res.begin(),	one);
	}
	return	res;
}

int main(int argc, char *argv[]) 
{
	Solution *sol = new Solution();

	// ɾ�������е�ָ����������������
	int A[] = {1 ,2 ,2 ,3 ,4 ,2 ,5};
	int Nremoveelement;
	Nremoveelement = sol->removeElement(A,sizeof(A)/sizeof(A[0]),2);
	cout << "ɾ��ָ����������Ԫ�ظ�����" << endl;
	cout << Nremoveelement<<endl;

	// ɾ�����������е��ظ���������������
	int Asorted[] = {1 ,2 ,2 ,3 ,4 ,4 ,5};
	int Nremoveduplicate;
	Nremoveduplicate = sol->removeDuplicates(Asorted,sizeof(Asorted)/sizeof(Asorted[0]));
	cout << "ɾ�����������е��ظ����������������" << endl;
	cout << Nremoveduplicate <<endl;

	// ɾ�����������е��ظ������������������ظ���Ԫ��,�������������
	int Asorted2[] = {1 ,2 ,2 ,3,3,3 ,4 ,4 ,5};
	int Nremoveduplicate2;
	Nremoveduplicate2 = sol->removeDuplicates_2(Asorted2,sizeof(Asorted2)/sizeof(Asorted2[0]));
	cout << "ɾ�����������е��ظ����������������" << endl;
	cout << Nremoveduplicate2 <<endl;

	// vector����Ľ�λ�ӷ�[�����һλ��1����ʮ��ǰλ��1]
	int n[] = {1, 2, 3, 9, 9};
	vector<int> A3(n, n+5);
	vector<int> A3_add1;
	A3_add1 = sol->plusOne(A3);
	cout << "vector����Ľ�λ�ӷ���" << endl;
	for(int m=0;m<A3_add1.size();m++)
	{
		cout<<A3_add1[m];//<<endl
		cout<<" ";
	}
	cout<<endl;

	system("pause");
	return 0;
}