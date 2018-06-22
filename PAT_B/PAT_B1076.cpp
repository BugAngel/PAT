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
map<char, int> charToInt;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	char s[8];
	charToInt['A'] = 1;
	charToInt['B'] = 2;
	charToInt['C'] = 3;
	charToInt['D'] = 4;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		getchar();
		scanf("%c-%c %c-%c %c-%c %c-%c", &s[0], &s[1], &s[2], &s[3], &s[4], &s[5], &s[6], &s[7]);
		if (s[1] == 'T')
		{
			printf("%d", charToInt[s[0]]);
		}
		else if (s[3] == 'T')
		{
			printf("%d", charToInt[s[2]]);
		}
		else if (s[5] == 'T')
		{
			printf("%d", charToInt[s[4]]);
		}
		else if (s[7] == 'T')
		{
			printf("%d", charToInt[s[6]]);
		}
	}
	printf("\n");
	return 0;
}
