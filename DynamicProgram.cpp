#include "DynamicProgram.h"

int	DynamicProgram::maxProfit(vector<int> &prices)
{
	if (prices.size() <= 1)
	{
		return	0;
	}
	int	minP = prices[0];
	int	profit = prices[1] - prices[0];
	for (int i = 2; i < prices.size(); i++)
	{
		minP = min(prices[i - 1], minP);
		profit = max(profit, prices[i] - minP);
	}
	if (profit < 0)
	{
		return	0;
	}
	return	profit;
}


int	DynamicProgram::uniquePaths(int	m, int	n) 
{
	int **dp = new int*[m];
	for (int i = 0; i < m;i++) dp[i] = new int[n];

	//初始化dp，m	x	1情况全为1
	for (int i = 0; i < m; i++) 
	{
		dp[i][0] = 1;
	}
	//初始化dp，1	x	n情况全为1
	for (int j = 0; j < n; j++)
	{
		dp[0][j] = 1;
	}
	for (int i = 1; i < m; i++) 
	{
		for (int j = 1; j < n; j++) 
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	return	dp[m - 1][n - 1];
}
