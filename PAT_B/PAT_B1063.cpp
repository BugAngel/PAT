#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

const int maxn = 100010;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	double max=-1, now;
	int shiBu, xuBu;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &shiBu, &xuBu);
		now = sqrt(1.0*(shiBu*shiBu + xuBu * xuBu));
		if (now > max)
		{
			max = now;
		}
	}
	printf("%.2f", (int)(100*max+0.5)/100.0);
	return 0;
}
