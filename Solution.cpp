#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution	
{
public:
	template<typename T> //ע�⣬����û�����Ž�β
	inline int length(T& array){return sizeof(array)/sizeof(array[0]);};
	int	removeElement(int A[],int n,int	elem);
	int	removeDuplicates(int A[],int n)	;
	int	removeDuplicates_2(int A[],int n);
	vector<int>	plusOne(vector<int>	&digits);
	vector<vector<int>> pascalTriangle(int numRows);	
	vector<int> pascalTriangle_onearray(int	rowIndex);
	int *merge(int A[],int B[],int m,int n);
	vector<int>	twoSum(vector<int> &numbers,int target);
	
};

// �������鳤��
//template<typename T> //ע�⣬����û�����Ž�β
//int Solution::length(T& array)
//{
//	return sizeof(array)/sizeof(array[0]);
//}

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
int	Solution::removeDuplicates_2(int A[],int n)	
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
vector<int>	Solution::plusOne(vector<int> &digits)	
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

// ��˹��������
vector<vector<int>>	Solution::pascalTriangle(int numRows)	
{
	vector<vector<int>>	vals;
	vals.resize(numRows);
	for(int	i=0;i<numRows;i++)	
	{
		vals[i].resize(i+1);
		vals[i][0] = 1;
		vals[i][vals[i].size()-1] = 1;
		for(int	j=1;j<vals[i].size()-1;j++)	
		{
			vals[i][j] = vals[i-1][j-1]+vals[i-1][j];
		}
	}
	return	vals;
}

// ��˹��������[һά����]
vector<int>	Solution::pascalTriangle_onearray(int rowIndex)	
{
	vector<int>	vals;
	vals.resize(rowIndex+1,	1);
	for(int	i=0;i<rowIndex+1;++i)	
	{
		for(int	j=i-1;j>=1;--j)	
		{
			vals[j] = vals[j] + vals[j-1];
		}
	}
	return	vals;
}

// �ϲ���������A��B
int *Solution::merge(int A[],int B[],int m,int n)	
{
	int	i =	m+n-1;
	int	j =	m-1;
	int	k =	n-1;
	while(i>=0)	
	{// ������β�����������
		if(j>=0	&& k>=0)	
		{// ������û����ʱ
			if(A[j]>B[k])	
			{// ��Ӵ��Ԫ�ص����
				A[i]=A[j];
				j--;
			}	
			else	
			{
				A[i]=B[k];
				k--;
			}
		}	
		else if(j>=0)	
		{// ��B���꣬A����ʣ�࣬������ӵ�A��
			A[i]=A[j];
			j--;
		}	
		else if(k>=0)	
		{// ��A���꣬B����ʣ�࣬������ӵ�A��
			A[i]=B[k];
			k--;
		}
		i--;
	}
	return A;
}

// ��������������ֵ����ţ�������ֵ��͵���ָ��ֵ
vector<int>	Solution::twoSum(vector<int> &numbers, int target)	
{
	//�߽����⣬����Ҫ���Ǳ߽�����Ĵ���
	vector<int>	ret;
	if(numbers.size()<=1)
	{
		return	ret;
	}
	//�½�һ��map<key,value>	ģʽ�����洢numbers�����Ԫ�غ�index��
	map<int,int> myMap;
	for(int	i=0;i<numbers.size();++i)
	{
		myMap[numbers[i]]=i;
	}
	for(int	i=0;i<numbers.size();++i)
	{
		int	rest_val=target	- numbers[i];
		if(myMap.find(rest_val) != myMap.end())
		{
			int	index = myMap[rest_val];
			if(index == i)
			{
				continue;					//�����ͬһ�����֣����Ǿ�pass���ǲ���ȡ���ֵ��
			}
			if(index < i)
			{
				ret.push_back(index+1);		//����+1����Ϊ��Ŀ˵������Ҫnon-zero	based	index
				ret.push_back(i+1);
				return	ret;
			}
			else
			{
				ret.push_back(i+1);
				ret.push_back(index+1);
				return	ret;
			}
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
int main( ) 
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
	cout<<endl;
	cout << "ɾ�����������е��ظ����������������" << endl;
	cout << Nremoveduplicate <<endl;

	// ɾ�����������е��ظ������������������ظ���Ԫ��,�������������
	int Asorted2[] = {1 ,2 ,2 ,3,3,3 ,4 ,4 ,5};
	int Nremoveduplicate2;
	Nremoveduplicate2 = sol->removeDuplicates_2(Asorted2,sizeof(Asorted2)/sizeof(Asorted2[0]));
	cout<<endl;
	cout << "ɾ�����������е��ظ����������������" << endl;
	cout << Nremoveduplicate2 <<endl;

	// vector����Ľ�λ�ӷ�[�����һλ��1����ʮ��ǰλ��1]
	int n[] = {1, 2, 3, 9, 9};
	vector<int> A3(n, n+5);
	vector<int> A3_add1;
	A3_add1 = sol->plusOne(A3);
	cout<<endl;
	cout << "vector����Ľ�λ�ӷ���" << endl;
	for(int m=0;m<A3_add1.size();m++)
	{
		cout<<A3_add1[m];//<<endl
		cout<<" ";
	}
	cout<<endl;

	// ��˹��������[��ά����]
	int row = 5;
	cout<<endl;
	cout << "��������Ϊ"<<row<<"����˹��������:"<< endl;
	vector<vector<int>>	PascalTria;
	PascalTria = sol->pascalTriangle(row);
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<PascalTria[i].size();j++)
		{
			cout<<PascalTria[i][j]; 
			cout<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

	// ��˹��������[һά����]
	int row1 = 4;
	cout<<endl;
	cout << "��������Ϊ"<<row<<"����˹��������:"<< endl;
	vector<int>	PascalTria1;
	PascalTria1 = sol->pascalTriangle_onearray(row1);	
	for(int j=0;j<PascalTria1.size();j++)
	{
		cout<<PascalTria1[j]; 
		cout<<" ";
	}
	cout<<endl;

	// �ϲ���������A��B
	cout<<endl;
	cout<<"�ϲ���������A��B:"<< endl;
	int A1[8] = {1, 2, 3, 9};
	int B1[ ] = {2, 5, 6, 8};
	int nA1 = 4;//sol->length(A1); 
	int nB1 = 4;//sol->length(B1);  
	int *AB;
	AB = sol->merge(A1,B1,nA1,nB1);
	for(int i=0;i<nA1+nB1;i++)
	{
		cout << AB[i] << " " ;
	}
	cout << endl;

	// ��������������ֵ����ţ�������ֵ��͵���ָ��ֵ
	cout<<endl;
	cout<<"��������������ֵ�����:"<< endl;
	// vector����Ľ�λ�ӷ�[�����һλ��1����ʮ��ǰλ��1]
	int n2[] = {1, 2, 3, 9, 11};
	vector<int> numbers(n2, n2+5);
	vector<int> TwoTarget;
	int target = 12;
	TwoTarget = sol->twoSum(numbers,target);	
	for (int numTarget=0;numTarget<2;numTarget++)
	{
		cout<<TwoTarget[numTarget]<<" ";
	}
	cout<<endl;


	system("pause");
	return 0;
}