#pragma once
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
class Array
{
public:
	Array() {}
public:
	template<typename T> //注意，这里没有引号结尾
	inline int length(T& array) { return sizeof(array) / sizeof(array[0]); };
	int	removeElement(int A[], int n, int	elem);
	int	removeDuplicates(int A[], int n);
	int	removeDuplicates_2(int A[], int n);
	vector<int>	plusOne(vector<int>	&digits);
	vector<vector<int>> pascalTriangle(int numRows);
	vector<int> pascalTriangle_onearray(int	rowIndex);
	int *merge(int A[], int B[], int m, int n);
	vector<int>	twoSum(vector<int> &numbers, int target);
	vector<vector<int>>	threeSum(vector<int> &num);
	int	findMin(vector<int>	&num);
	int	largestRectangleArea(vector<int> &height);
	int	maximalRectangle(vector<vector<int>> &matrix);
	bool searchMatrix(vector<vector<int>> &matrix, int target);
	int	searchInsert(int A[], int n, int target);
	bool isPalindrome(int x);
	int factorial(int n);
	int Fibonacci(int n);
	bool isPowerOfTwo(int n);
};

