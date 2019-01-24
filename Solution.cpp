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
	vector<int>	plusOne(vector<int>	&digits);
	vector<vector<int>> pascalTriangle(int numRows);	
	vector<int> pascalTriangle_onearray(int	rowIndex);
	int *merge(int A[],int B[],int m,int n);
	template<typename T> //注意，这里没有引号结尾
	inline int length(T& array){return sizeof(array)/sizeof(array[0]);}
};

// 返回数组长度
//template<typename T> //注意，这里没有引号结尾
//int Solution::length(T& array)
//{
//	return sizeof(array)/sizeof(array[0]);
//}

// 去除重复元素
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

// 去除有序数组中的重复元素
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

// 去除有序数组中重复元素，但是允许最多两次重复的元素
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
		{// 相同则判断num，num<2表示重复的只有两个；超过2个，则去除[num>2,不保留]
			num++;
			if(num<2)	
			{//如果num小于2，表示此时有一个重复量但是仍保留，
				A[++j]=A[i];
			}
		}	
		else	
		{// 不同则按照上面的逻辑，j向后进一位，添上Ai
			A[++j] = A[i];
			num	= 0;
		}
	}
	return j+1;
}

// vector数组的进位加法[从最后一位加1，满十则前位加1]
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

// 帕斯卡三角形
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

// 帕斯卡三角形[一维数组]
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

// 合并有序数组A和B
int *Solution::merge(int A[],int B[],int m,int n)	
{
	int	i =	m+n-1;
	int	j =	m-1;
	int	k =	n-1;
	while(i>=0)	
	{// 从向量尾部倒过来添加
		if(j>=0	&& k>=0)	
		{// 两个都没排完时
			if(A[j]>B[k])	
			{// 添加大的元素到最后
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
		{// 若B排完，A还有剩余，依次添加到A中
			A[i]=A[j];
			j--;
		}	
		else if(k>=0)	
		{// 若A排完，B还有剩余，依次添加到A中
			A[i]=B[k];
			k--;
		}
		i--;
	}
	return A;
}



///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////
int main( ) 
{
	Solution *sol = new Solution();

	// 删除数组中的指定项，返回新数组个数
	int A[] = {1 ,2 ,2 ,3 ,4 ,2 ,5};
	int Nremoveelement;
	Nremoveelement = sol->removeElement(A,sizeof(A)/sizeof(A[0]),2);
	cout << "删除指定项后的数组元素个数：" << endl;
	cout << Nremoveelement<<endl;

	// 删除有序数组中的重复项，返回新数组个数
	int Asorted[] = {1 ,2 ,2 ,3 ,4 ,4 ,5};
	int Nremoveduplicate;
	Nremoveduplicate = sol->removeDuplicates(Asorted,sizeof(Asorted)/sizeof(Asorted[0]));
	cout<<endl;
	cout << "删除有序数组中的重复项后的新数组个数：" << endl;
	cout << Nremoveduplicate <<endl;

	// 删除有序数组中的重复项，但是允许最多两次重复的元素,返回新数组个数
	int Asorted2[] = {1 ,2 ,2 ,3,3,3 ,4 ,4 ,5};
	int Nremoveduplicate2;
	Nremoveduplicate2 = sol->removeDuplicates_2(Asorted2,sizeof(Asorted2)/sizeof(Asorted2[0]));
	cout<<endl;
	cout << "删除有序数组中的重复项后的新数组个数：" << endl;
	cout << Nremoveduplicate2 <<endl;

	// vector数组的进位加法[从最后一位加1，满十则前位加1]
	int n[] = {1, 2, 3, 9, 9};
	vector<int> A3(n, n+5);
	vector<int> A3_add1;
	A3_add1 = sol->plusOne(A3);
	cout<<endl;
	cout << "vector数组的进位加法：" << endl;
	for(int m=0;m<A3_add1.size();m++)
	{
		cout<<A3_add1[m];//<<endl
		cout<<" ";
	}
	cout<<endl;

	// 帕斯卡三角形[二维数组]
	int row = 5;
	cout<<endl;
	cout << "生成行数为"<<row<<"的帕斯卡三角形:"<< endl;
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

	// 帕斯卡三角形[一维数组]
	int row1 = 4;
	cout<<endl;
	cout << "生成行数为"<<row<<"的帕斯卡三角形:"<< endl;
	vector<int>	PascalTria1;
	PascalTria1 = sol->pascalTriangle_onearray(row1);	
	for(int j=0;j<PascalTria1.size();j++)
	{
		cout<<PascalTria1[j]; 
		cout<<" ";
	}
	cout<<endl;

	// 合并有序数组A和B
	cout<<endl;
	cout<<"合并有序数组A和B:"<< endl;
	int A1[ ] = {1, 2, 3, 9};
	int B1[ ] = {2, 5, 6, 8};
	int nA1 = sol->length(A1); 
	int nB1 = sol->length(B1);  
	int *AB;
	AB = sol->merge(A1,B1,nA1,nB1);
	for(int i=0;i<nA1+nB1;i++)
	{
		cout << AB[i] << " " ;
	}
	cout << endl;

	system("pause");
	return 0;
}