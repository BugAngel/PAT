#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

const int maxn = 100010;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		double g1;
		int g2;
		cin >> g2;
		int temp, sum = 0, count = 0;
		int max = -1, min = 110;
		for (int j = 0; j < n - 1; j++)
		{
			cin >> temp;
			if (temp >= 0 && temp <= m)
			{
				sum += temp;
				count++;
				if (temp > max)
				{
					max = temp;
				}
				if (temp < min)
				{
					min = temp;
				}
			}
		}
		sum -= min;
		sum -= max;
		g1 = 1.0*sum / (count - 2);
		printf("%d\n", (int)(1.0*(g1 + g2) / 2 + 0.5));
	}
	return 0;
}

