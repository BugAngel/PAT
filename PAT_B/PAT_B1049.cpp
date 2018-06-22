#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;
const int N = 100010;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	double sum = 0.0;
	double num;
	for (int i = 1; i <= n; i++)
	{
		scanf("%lf", &num);
		sum += num * i*(n + 1 - i);
	}
	printf("%.2f\n", sum);
	return 0;
}
