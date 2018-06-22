#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

const int maxn = 10010;


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, d;//总套数，观察期阈值
	double E;//低电量阈值
	int keNengKongZhi = 0, kongZhi = 0;
	scanf("%d%lf%d", &n, &E, &d);
	for (int i = 0; i < n; i++)
	{
		int count = 0;//低于低电量阈值天数
		int k;//观察天数
		scanf("%d", &k);
		for (int j = 0; j < k; j++)
		{
			double e;
			scanf("%lf", &e);
			if (e < E)
			{
				count++;
			}
		}
		if (count > k / 2 && k>d)
		{			
			kongZhi++;
		}
		else if (count > k / 2)
		{
			keNengKongZhi++;
		}
	}
	printf("%.1f%% %.1f%%\n", 100.0*keNengKongZhi / n, 100.0*kongZhi / n);
	return 0;
}

