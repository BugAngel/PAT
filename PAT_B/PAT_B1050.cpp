#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

const int maxn = 10010;

int N;
int m, n;
int origin[maxn];
//int JuZhen[maxn][maxn];
bool flag[maxn][5010] = { false };

bool cmp(int a, int b)
{
	return a > b;
}

void move(int &X, int &Y, int FangXiang)
{
	switch (FangXiang)
	{
	case 0://上
		Y--;
		break;
	case 1://下
		Y++;
		break;
	case 2://左
		X--;
		break;
	case 3://右
		X++;
		break;
	}
}

void judgeDirection(int X, int Y, int& FangXiang)
{
	switch (FangXiang)
	{
	case 0://上
		if ((flag[Y - 1][X] == false) && (X + 1 < n) && flag[Y][X + 1] == true)
		{
			FangXiang = 3;
		}
		break;
	case 1://下
		if ((flag[Y + 1][X] == false) && (X - 1 >= 0) && flag[Y][X - 1] == true)
		{
			FangXiang = 2;
		}
		break;
	case 2://左
		if ((flag[Y][X - 1] == false) && (Y - 1 >= 0) && flag[Y - 1][X] == true)
		{
			FangXiang = 0;
		}
		break;
	case 3://右
		if ((flag[Y][X + 1] == false) && (Y + 1 < m) && flag[Y + 1][X] == true)
		{
			FangXiang = 1;
		}
		break;
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &origin[i]);
	}
	sort(origin, origin + N, cmp);
	for (int i = 1; i <= (int)sqrt(N); i++)
	{
		if (N%i == 0)
		{
			m = N / i;
			n = i;
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			flag[i][j] = true;
		}
	}

	int X = 0, Y = 0, FangXiang = 3;//螺旋矩阵上下左右方向依次对应0123，左上角开始先往右;
	vector<vector<int>> JuZhen(m);
	for (int i = 0; i < m; i++)
	{
		JuZhen[i].resize(n);
	}
		
	for (int i = 0; i < N; i++)
	{
		JuZhen[Y][X] = origin[i];
		flag[Y][X] = false;
		judgeDirection(X, Y, FangXiang);
		move(X, Y, FangXiang);
	}

	int count = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n-1; j++)
		{
			printf("%d ", JuZhen[i][j]);
		}
		printf("%d\n", JuZhen[i][n-1]);
	}
	return 0;
}

