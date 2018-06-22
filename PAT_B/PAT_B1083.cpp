#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

const int maxn = 10005;

bool chaZhiFlag[maxn] = { false };
int chaZhi[maxn] = { 0 };

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int num;
		cin >> num;
		if (num > i)
		{
			chaZhiFlag[num - i] = true;
			chaZhi[num - i]++;
		}
		else
		{
			chaZhiFlag[i-num] = true;
			chaZhi[i-num]++;
		}
	}
	for (int i = maxn - 1; i >= 0; i--)
	{
		if (chaZhiFlag[i] && chaZhi[i]>=2)
		{
			cout << i << " " << chaZhi[i] << endl;
		}
	}
	return 0;
}
