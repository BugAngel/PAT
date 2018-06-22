#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

const int maxn = 100010;
int num[maxn];
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	int e = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
	}
	sort(num, num + n, cmp);
	for (int i = 0; i < n; i++)
	{
		if (num[i] > i + 1)
		{
			e = i + 1;
		}
	}
	printf("%d\n", e);
	return 0;
}

