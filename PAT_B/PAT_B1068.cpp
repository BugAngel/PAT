#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

const int maxn = 100010;
int image[1005][1005];
int m, n, tol;
int flag[20000000] = { 0 };

bool judge(int row,int col)//true表示是特殊点，false表示不是
{
	if (flag[image[row][col]] > 1)//先检查是不是独一无二
	{
		return false;
	}
	if (row > 0)//上
	{
		if (abs(image[row - 1][col] - image[row][col]) <= tol)
		{
			return false;
		}
	}
	if (row > 0 && col > 0)//左上
	{
		if (abs(image[row - 1][col - 1] - image[row][col]) <= tol)
		{
			return false;
		}
	}
	if (row > 0 && col < m - 1)//右上
	{
		if (abs(image[row - 1][col + 1] - image[row][col]) <= tol)
		{
			return false;
		}
	}
	if ( col > 0)//左
	{
		if (abs(image[row][col - 1] - image[row][col]) <= tol)
		{
			return false;
		}
	}
	if (col < m - 1)//右
	{
		if (abs(image[row][col + 1] - image[row][col]) <= tol)
		{
			return false;
		}
	}
	if (row < n - 1)//下
	{
		if (abs(image[row+1][col] - image[row][col]) <= tol)
		{
			return false;
		}
	}
	if (row < n - 1 && col > 0)//左下
	{
		if (abs(image[row + 1][col-1] - image[row][col]) <= tol)
		{
			return false;
		}
	}
	if (row < n - 1 && col < m - 1)//右下
	{
		if (abs(image[row + 1][col + 1] - image[row][col]) <= tol)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int count = 0;//特殊点个数
	int row, col, pixel;
	scanf("%d%d%d", &m, &n, &tol);//n是行，m是列

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &image[i][j]);
			flag[image[i][j]]++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (judge(i, j))
			{
				if (count == 0)
				{
					count = 1;
					row = i;
					col = j;
					pixel = image[i][j];
				}
				else
				{
					count++;
				}
			}
		}
	}

	if (count == 0)
	{
		printf("Not Exist\n");
	}
	else if (count == 1)
	{
		printf("(%d, %d): %d\n",col+1,row+1,pixel);
	}
	else
	{
		printf("Not Unique\n");
	}
	return 0;
}

