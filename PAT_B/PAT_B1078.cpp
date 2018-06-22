#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

const int maxn = 1010;

char s[maxn];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	char PanDing;
	cin >> PanDing;
	getchar();
	cin.getline(s, maxn);
	if (PanDing == 'C')//需要被压缩
	{		
		for (int i = 0; s[i] != '\0'; i++)
		{
			if (s[i] == s[i + 1])
			{
				int count = 0;
				while (s[i] == s[i + 1])
				{
					count++;
					i++;
				}
				printf("%d%c", count+1, s[i]);
			}
			else
			{
				printf("%c", s[i]);
			}
		}
		printf("\n");
	}
	else//需要解压
	{
		for (int i = 0; s[i] != '\0'; i++)
		{
			if (s[i] >= '0' && s[i] <= '9')
			{
				int sum = 0;//一排数字
				while (s[i] >= '0' && s[i] <= '9')
				{
					sum = 10 * sum + s[i] - '0';
					i++;
				}
				for (int j = 0; j < sum; j++)
				{
					printf("%c", s[i]);
				}
			}
			else
			{
				printf("%c", s[i]);
			}
		}
		printf("\n");
	}
	return 0;
}