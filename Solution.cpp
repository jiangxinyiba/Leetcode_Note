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
	cout << "删除有序数组中的重复项后的新数组个数：" << endl;
	cout << Nremoveduplicate <<endl;

	// 删除有序数组中的重复项，但是允许最多两次重复的元素,返回新数组个数
	int Asorted2[] = {1 ,2 ,2 ,3,3,3 ,4 ,4 ,5};
	int Nremoveduplicate2;
	Nremoveduplicate2 = sol->removeDuplicates_2(Asorted2,sizeof(Asorted2)/sizeof(Asorted2[0]));
	cout << "删除有序数组中的重复项后的新数组个数：" << endl;
	cout << Nremoveduplicate2 <<endl;

	// vector数组的进位加法[从最后一位加1，满十则前位加1]
	int n[] = {1, 2, 3, 9, 9};
	vector<int> A3(n, n+5);
	vector<int> A3_add1;
	A3_add1 = sol->plusOne(A3);
	cout << "vector数组的进位加法：" << endl;
	for(int m=0;m<A3_add1.size();m++)
	{
		cout<<A3_add1[m];//<<endl
		cout<<" ";
	}
	cout<<endl;

	system("pause");
	return 0;
}