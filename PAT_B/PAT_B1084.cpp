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
char s[45][100010];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	char d;
	int n;
	cin >> d >> n;
	s[0][0] = d;
	s[0][1] = '\0';
	for (int i = 1; i < n; i++)
	{		
		int cur = 0;
		for (int j = 0; j < strlen(s[i - 1]); j++)
		{
			int count = 1;
			while (s[i-1][j] == s[i-1][j + 1])
			{
				count++;
				j++;
			}
			s[i][cur++] = s[i - 1][j];
			if (count >= 10000)
			{
				s[i][cur++] = count / 10000 + '0';
				s[i][cur++] = count / 1000 % 10 + '0';
				s[i][cur++] = count / 100 % 10 + '0';
				s[i][cur++] = count / 10 % 10 + '0';
				s[i][cur++] = count % 10 + '0';
			}
			else if (count >= 1000)
			{
				s[i][cur++] = count / 1000 + '0';
				s[i][cur++] = count / 100 % 10 + '0';
				s[i][cur++] = count / 10 % 10 + '0';
				s[i][cur++] = count % 10 + '0';
			}
			else if (count >= 100)
			{
				s[i][cur++] = count / 100 + '0';
				s[i][cur++] = count /10 % 10 + '0';
				s[i][cur++] = count % 10 + '0';
			}
			else if (count >= 10)
			{
				s[i][cur++] = count/10 + '0';
				s[i][cur++] = count%10 + '0';
			}
			else
			{
				s[i][cur++] = count+'0';
			}
		}
		s[i][cur] = '\0';
	}
	printf("%s\n", s[n - 1]);
	return 0;
}
