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

	int n, d;//���������۲�����ֵ
	double E;//�͵�����ֵ
	int keNengKongZhi = 0, kongZhi = 0;
	scanf("%d%lf%d", &n, &E, &d);
	for (int i = 0; i < n; i++)
	{
		int count = 0;//���ڵ͵�����ֵ����
		int k;//�۲�����
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

