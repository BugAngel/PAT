#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

const int maxn = 100010;

int image[510][510];

int main()
{
//	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int m, n, a, b, k;
	scanf("%d%d%d%d%d", &m, &n, &a, &b, &k);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &image[i][j]);
			if (image[i][j] >= a && image[i][j] <= b)
			{
				image[i][j] = k;
			}
			if (j == 0)
			{
				printf("%03d", image[i][j]);
			}
			else
			{
				printf(" %03d", image[i][j]);
			}
		}
		printf("\n");
	}

	return 0;
}
