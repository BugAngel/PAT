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

int num[maxn];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	double len;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
	}
	sort(num, num + n);
	len = (num[0] + num[1]) / 2.0;
	for (int i = 2; i < n; i++)
	{
		len = (len + num[i]) / 2.0;
	}
	printf("%d\n", (int)len);
	return 0;
}