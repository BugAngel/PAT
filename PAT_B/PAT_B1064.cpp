#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

const int maxn = 100010;
bool flag[40] = { false };

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	char s[10];
	int sum;//各位数字和
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		sum = 0;
		scanf("%s", s);
		for (int j = 0; s[j] != '\0'; j++)
		{
			sum += s[j] - '0';
		}
		flag[sum] = true;
	}

	int count = 0;
	for (int i = 0; i < 40; i++)
	{
		if (flag[i] == true)
		{
			count++;
		}
	}
	printf("%d\n", count);

	count = 0;
	for (int i = 0; i < 40; i++)
	{
		if (flag[i] == true)
		{
			if (count == 0)
			{
				printf("%d", i);
				count = 1;
			}
			else
			{
				printf(" %d", i);
			}
		}
	}
	printf("\n");
	return 0;
}

