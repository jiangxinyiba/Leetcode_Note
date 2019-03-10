#include "Array.h"
# define FALSE 0;
# define TRUE 1;

// 返回数组长度
//template<typename T> //注意，这里没有引号结尾
//int Solution::length(T& array)
//{
//	return sizeof(array)/sizeof(array[0]);
//}

// 去除重复元素
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

// 去除有序数组中的重复元素
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

// 去除有序数组中重复元素，但是允许最多两次重复的元素
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
		{// 相同则判断num，num<2表示重复的只有两个；超过2个，则去除[num>2,不保留]
			num++;
			if (num<2)
			{//如果num小于2，表示此时有一个重复量但是仍保留，
				A[++j] = A[i];
			}
		}
		else
		{// 不同则按照上面的逻辑，j向后进一位，添上Ai
			A[++j] = A[i];
			num = 0;
		}
	}
	return j + 1;
}

// vector数组的进位加法[从最后一位加1，满十则前位加1]
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

// 帕斯卡三角形
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

// 帕斯卡三角形[一维数组]
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

// 合并有序数组A和B
int *Array::merge(int A[], int B[], int m, int n)
{
	int	i = m + n - 1;
	int	j = m - 1;
	int	k = n - 1;
	while (i >= 0)
	{// 从向量尾部倒过来添加
		if (j >= 0 && k >= 0)
		{// 两个都没排完时
			if (A[j]>B[k])
			{// 添加大的元素到最后
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
		{// 若B排完，A还有剩余，依次添加到A中
			A[i] = A[j];
			j--;
		}
		else if (k >= 0)
		{// 若A排完，B还有剩余，依次添加到A中
			A[i] = B[k];
			k--;
		}
		i--;
	}
	return A;
}

// 求数组中两个数值的序号，两个数值求和等于指定值
vector<int>	Array::twoSum(vector<int> &numbers, int target)
{
	//边角问题，我们要考虑边角问题的处理
	vector<int>	ret;
	if (numbers.size() <= 1)
	{
		return	ret;
	}
	//新建一个map<key,value>	模式的来存储numbers里面的元素和index，
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
				continue;					//如果是同一个数字，我们就pass，是不会取这个值的
			}
			if (index < i)
			{
				ret.push_back(index + 1);		//这里+1是因为题目说明白了要non-zero	based	index
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

// 列出数组中三个数值求和等于0的所有情况
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
				{//若第j-1个和第j个相同则跳过
					++j;
				}
				while (j<k && num[k] == num[k + 1])
				{//若第k个和第k+1个相同则跳过
					--k;
				}
			}
			else if (num[i] + num[j] + num[k]<0)
			{// 和过小，则j+1	
				++j;
			}
			else
			{// 和过大，则k-1
				--k;
			}
		}
		//this	while	loop	also	is	used	to	skip	the	duplication	solution
		while (i<num.size() - 1 && num[i] == num[i + 1])
		{//若第i个和第i+1个相同则跳过
			++i;
		}
	}
	return	ret;
}
// 选择有序数组中的最小值
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

// 求取直方图中最大的长方形区域
int	Array::largestRectangleArea(vector<int> &height)
{
	vector<int>	s;
	//插入高度为0的bar
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
			//这里还需要考虑stack为空的情况
			sum = max(sum, height[t] * (s.empty() ? i : i - s.back() - 1));
		}
	}
	return	sum;
}

// 求取矩阵中的最大矩形面积
int	Array::maximalRectangle(vector<vector<int>> &matrix)
{
	if (matrix.empty() || matrix[0].empty())
	{
		return 0;
	}
	int	m = matrix.size();
	int	n = matrix[0].size();
	vector<vector<int>>	height(m, vector<int>(n, 0)); // 生成m行n列的全零矩阵
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

// 判断回文数
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

// 寻找有序矩阵中的指定元素 O(n^2)
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

// 寻找有序数组中指定元素的位置[二分法]
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

// 阶乘 
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

//  Fibonacci 数列
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
