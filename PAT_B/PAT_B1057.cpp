#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

const int maxn = 100010;
char s[maxn];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int sum = 0;
	cin.getline(s, maxn);
	for (int i = 0; s[i]!='\0'; i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			sum += s[i] - 'A' + 1;
		}
		else if (s[i] >= 'a' && s[i] <= 'z')
		{
			sum += s[i] - 'a' + 1;
		}
	}

	int num0=0, num1=0;
	while (sum != 0)
	{
		if (sum % 2 == 0)
		{
			num0++;
		}
		else
		{
			num1++;
		}
		sum /= 2;
	}
	printf("%d %d\n", num0, num1);
	return 0;
}
