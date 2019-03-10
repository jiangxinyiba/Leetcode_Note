#include "Array.h"
# define FALSE 0;
# define TRUE 1;

// �������鳤��
//template<typename T> //ע�⣬����û�����Ž�β
//int Solution::length(T& array)
//{
//	return sizeof(array)/sizeof(array[0]);
//}

// ȥ���ظ�Ԫ��
int	Array::removeElement(int A[], int n, int elem)
{
	int	i = 0;
	int j = 0;
	for (i = 0; i<n; i++)
	{
		if (A[i] == elem)
		{
			continue;
		}
		A[j] = A[i];
		j++;
	}
	return j;
}

// ȥ�����������е��ظ�Ԫ��
int	Array::removeDuplicates(int A[], int n)
{// A is a sorted array!
	if (n == 0)
	{
		return	0;
	}

	int	j = 0;
	for (int i = 1; i<n; i++)
	{
		if (A[j] != A[i])
		{
			A[++j] = A[i];
		}
	}
	return	j + 1;
}

// ȥ�������������ظ�Ԫ�أ�����������������ظ���Ԫ��
int	Array::removeDuplicates_2(int A[], int n)
{
	if (n == 0)
	{
		return	0;
	}
	int	j = 0;
	int	num = 0;
	for (int i = 1; i < n; i++)
	{
		if (A[j] == A[i])
		{// ��ͬ���ж�num��num<2��ʾ�ظ���ֻ������������2������ȥ��[num>2,������]
			num++;
			if (num<2)
			{//���numС��2����ʾ��ʱ��һ���ظ��������Ա�����
				A[++j] = A[i];
			}
		}
		else
		{// ��ͬ����������߼���j����һλ������Ai
			A[++j] = A[i];
			num = 0;
		}
	}
	return j + 1;
}

// vector����Ľ�λ�ӷ�[�����һλ��1����ʮ��ǰλ��1]
vector<int>	Array::plusOne(vector<int> &digits)
{
	vector<int>	res(digits.size(), 0);
	int	sum = 0;
	int	one = 1;
	for (int i = digits.size() - 1; i >= 0; i--)
	{
		sum = one + digits[i];
		one = sum / 10;
		res[i] = sum % 10;
	}
	if (one > 0)
	{
		res.insert(res.begin(), one);
	}
	return	res;
}

// ��˹��������
vector<vector<int>>	Array::pascalTriangle(int numRows)
{
	vector<vector<int>>	vals;
	vals.resize(numRows);
	for (int i = 0; i<numRows; i++)
	{
		vals[i].resize(i + 1);
		vals[i][0] = 1;
		vals[i][vals[i].size() - 1] = 1;
		for (unsigned int j = 1; j<vals[i].size() - 1; j++)
		{
			vals[i][j] = vals[i - 1][j - 1] + vals[i - 1][j];
		}
	}
	return	vals;
}

// ��˹��������[һά����]
vector<int>	Array::pascalTriangle_onearray(int rowIndex)
{
	vector<int>	vals;
	vals.resize(rowIndex + 1, 1);
	for (int i = 0; i<rowIndex + 1; ++i)
	{
		for (int j = i - 1; j >= 1; --j)
		{
			vals[j] = vals[j] + vals[j - 1];
		}
	}
	return	vals;
}

// �ϲ���������A��B
int *Array::merge(int A[], int B[], int m, int n)
{
	int	i = m + n - 1;
	int	j = m - 1;
	int	k = n - 1;
	while (i >= 0)
	{// ������β�����������
		if (j >= 0 && k >= 0)
		{// ������û����ʱ
			if (A[j]>B[k])
			{// ��Ӵ��Ԫ�ص����
				A[i] = A[j];
				j--;
			}
			else
			{
				A[i] = B[k];
				k--;
			}
		}
		else if (j >= 0)
		{// ��B���꣬A����ʣ�࣬������ӵ�A��
			A[i] = A[j];
			j--;
		}
		else if (k >= 0)
		{// ��A���꣬B����ʣ�࣬������ӵ�A��
			A[i] = B[k];
			k--;
		}
		i--;
	}
	return A;
}

// ��������������ֵ����ţ�������ֵ��͵���ָ��ֵ
vector<int>	Array::twoSum(vector<int> &numbers, int target)
{
	//�߽����⣬����Ҫ���Ǳ߽�����Ĵ���
	vector<int>	ret;
	if (numbers.size() <= 1)
	{
		return	ret;
	}
	//�½�һ��map<key,value>	ģʽ�����洢numbers�����Ԫ�غ�index��
	map<int, int> myMap;
	for (unsigned int i = 0; i<numbers.size(); ++i)
	{
		myMap[numbers[i]] = i;
	}
	for (unsigned int i = 0; i<numbers.size(); ++i)
	{
		int	rest_val = target - numbers[i];
		if (myMap.find(rest_val) != myMap.end())
		{
			unsigned int	index = myMap[rest_val];
			if (index == i)
			{
				continue;					//�����ͬһ�����֣����Ǿ�pass���ǲ���ȡ���ֵ��
			}
			if (index < i)
			{
				ret.push_back(index + 1);		//����+1����Ϊ��Ŀ˵������Ҫnon-zero	based	index
				ret.push_back(i + 1);
				return	ret;
			}
			else
			{
				ret.push_back(i + 1);
				ret.push_back(index + 1);
				return	ret;
			}
		}
	}
}

// �г�������������ֵ��͵���0���������
vector<vector<int>>	Array::threeSum(vector<int> &num)
{
	vector<vector<int>>	ret;
	//corner case invalid check
	if (num.size() <= 2)
	{
		return	ret;
	}

	//first	we need to sort the array because we need the non-descending order
	sort(num.begin(), num.end());
	for (unsigned int i = 0; i<num.size() - 2; ++i)
	{
		int	j = i + 1;
		int	k = num.size() - 1;
		while (j<k)
		{
			vector<int>	curr;			//create a	tmp	vector	to	store	each	triplet	which	satisfy	the	solution.
			if (num[i] + num[j] + num[k] == 0)
			{
				curr.push_back(num[i]);
				curr.push_back(num[j]);
				curr.push_back(num[k]);
				ret.push_back(curr);
				++j;
				--k;
				//this	two	while	loop	is	used	to	skip the	duplication	solution
				while (j<k && num[j - 1] == num[j])
				{//����j-1���͵�j����ͬ������
					++j;
				}
				while (j<k && num[k] == num[k + 1])
				{//����k���͵�k+1����ͬ������
					--k;
				}
			}
			else if (num[i] + num[j] + num[k]<0)
			{// �͹�С����j+1	
				++j;
			}
			else
			{// �͹�����k-1
				--k;
			}
		}
		//this	while	loop	also	is	used	to	skip	the	duplication	solution
		while (i<num.size() - 1 && num[i] == num[i + 1])
		{//����i���͵�i+1����ͬ������
			++i;
		}
	}
	return	ret;
}
// ѡ�����������е���Сֵ
int	Array::findMin(vector<int>	&num)
{
	int	size = num.size();
	if (size == 0)
	{
		return 0;
	}
	else if (size == 1)
	{
		return num[0];
	}
	else if (size == 2)
	{
		return min(num[0], num[1]);
	}
	int	start = 0;
	int	stop = size - 1;
	while (start	< stop - 1)
	{
		if (num[start] <	num[stop])
		{
			return num[start];
		}
		int	mid = start + (stop - start) / 2;
		if (num[mid] > num[start])
		{
			start = mid;
		}
		else if (num[mid] < num[start])
		{
			stop = mid;
		}
	}
	return min(num[start], num[stop]);
}

// ��ȡֱ��ͼ�����ĳ���������
int	Array::largestRectangleArea(vector<int> &height)
{
	vector<int>	s;
	//����߶�Ϊ0��bar
	height.push_back(0);
	unsigned int	sum = 0;
	unsigned int	i = 0;
	while (i	< height.size())
	{
		if (s.empty() || height[i] > height[s.back()])
		{
			s.push_back(i);
			i++;
		}
		else
		{
			int	t = s.back();
			s.pop_back();
			//���ﻹ��Ҫ����stackΪ�յ����
			sum = max(sum, height[t] * (s.empty() ? i : i - s.back() - 1));
		}
	}
	return	sum;
}

// ��ȡ�����е����������
int	Array::maximalRectangle(vector<vector<int>> &matrix)
{
	if (matrix.empty() || matrix[0].empty())
	{
		return 0;
	}
	int	m = matrix.size();
	int	n = matrix[0].size();
	vector<vector<int>>	height(m, vector<int>(n, 0)); // ����m��n�е�ȫ�����
	for (int i = 0; i<m; i++)
	{
		for (int j = 0; j<n; j++)
		{
			int mat = matrix[i][j];
			if (mat == 0)
			{
				height[i][j] = 0;
			}
			else
			{
				height[i][j] = (i == 0) ? 1 : height[i - 1][j] + 1;
			}
		}
	}
	int	maxArea = 0;
	for (int i = 0; i<m; i++)
	{
		maxArea = max(maxArea, largestRectangleArea(height[i]));
	}
	return	maxArea;
}

// �жϻ�����
bool Array::isPalindrome(int x)
{
	if (x<0)
	{
		return	FALSE;
	}
	else if (x == 0)
	{
		return	TRUE;
	}
	else
	{
		int	tmp = x;
		int	y = 0;
		while (x != 0)
		{
			y = y * 10 + x % 10;
			x = x / 10;
		}
		if (y == tmp)
		{
			return	TRUE;
		}
		else
		{
			return	FALSE;
		}
	}
}

// Ѱ����������е�ָ��Ԫ�� O(n^2)
bool Array::searchMatrix(vector<vector<int>> &matrix, int target)
{
	/*	we	set	the	corner	case	as	below:
	1,	if	the	row	number	of	input	matrix	is	0,	we	set	it	false
	2,	if	the	colomun	number	of	input	matrix	is	0,	we	set	it	false*/
	if (matrix.size() == 0) { return	false; }
	if (matrix[0].size() == 0) { return	false; }
	unsigned int	rowNumber = 0;
	unsigned int	colNumber = matrix[0].size() - 1;
	while (rowNumber<matrix.size() && colNumber >= 0)
	{
		if (target<matrix[rowNumber][colNumber])
		{
			--colNumber;
		}
		else if (target>matrix[rowNumber][colNumber])
		{
			++rowNumber;
		}
		else
		{
			return	true;
		}
	}
	return	false;
}

// Ѱ������������ָ��Ԫ�ص�λ��[���ַ�]
int	Array::searchInsert(int A[], int n, int target)
{
	int	low = 0;
	int	high = n - 1;
	while (low <= high)
	{
		int	mid = low + (high - low) / 2;
		if (A[mid] == target)
		{
			return mid;
		}
		else if (A[mid]<target)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return	low;
}

// �׳� 
int Array::factorial(int n)
{
	int result;
	if (n == 1)
	{
		result = 1;
	}
	else
	{
		result = n*factorial(n - 1);
	}
	return result;
}

//  Fibonacci ����
int Array::Fibonacci(int n)
{
	int result;
	int mem_i = 0;
	int mem_i_1 = 1;
	int mem_i_2 = 1;
	if (n<2)
	{
		result = 1;
	}
	for (int i = 2; i<n; i++)
	{
		mem_i = mem_i_1 + mem_i_2;
		mem_i_2 = mem_i_1;
		mem_i_1 = mem_i;
	}
	return result = mem_i;
}

bool Array::isPowerOfTwo(int n)
{
	if (n	<	0)	return	false;
	bool	hasOne = false;
	while (n	>	0)
	{
		if (n & 1)
		{
			if (hasOne)
			{
				return	false;
			}
			else
			{
				hasOne = true;
			}
		}
		n >>= 1;
	}
	return	hasOne;
}
