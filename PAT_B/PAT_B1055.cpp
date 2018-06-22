#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

const int maxn = 10010;

struct NODE
{
	char s[10];
	int height;
}stu[maxn];

bool cmp(struct NODE a, struct NODE b)
{
	if (a.height == b.height)
	{
		return strcmp(a.s,b.s)<0;
	}
	else
	{
		return a.height > b.height;
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n,k;
	int num, lastNum;//分别为每排人数和最后一排人数
	vector<struct NODE> result;
	scanf("%d%d", &n, &k);
	
	num = n / k;
	lastNum = n - num * (k - 1);
	for (int i = 0; i < n; i++)
	{
		scanf("%s%d", stu[i].s, &stu[i].height);
	}
	sort(stu, stu + n, cmp);
	for (int i = 0; i < lastNum; i++)
	{
		if (i % 2 == 0)
		{
			result.push_back(stu[i]);
		}
		else
		{
			result.insert(result.begin(), stu[i]);
		}
	}

	for (int i = 0; i < lastNum-1; i++)
	{
		printf("%s ", result[i].s);
	}
	printf("%s\n", result[lastNum - 1].s);
	result.erase(result.begin(), result.end());

	for (int i = 0; i < k - 1; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (j % 2 == 0)
			{
				result.push_back(stu[j+lastNum+i*num]);
			}
			else
			{
				result.insert(result.begin(), stu[j + lastNum + i * num]);
			}
		}

		for (int j = 0; j < num - 1; j++)
		{
			printf("%s ", result[j].s);
		}
		printf("%s\n", result[num - 1].s);
		result.erase(result.begin(), result.end());

	}
	return 0;
}
