#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

const int maxn = 100010;

char password[100];
char s[100];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	int count = 0;
	scanf("%s", password);
	scanf("%d", &n);
	getchar();

	while (true)
	{		
		cin.getline(s, 100);
		int len = strlen(s);
		if (len == 1 && s[0] == '#')// ‰»ÎΩ· ¯
		{
			break;
		}
		if (strcmp(s, password) == 0)
		{
			printf("Welcome in\n");
			break;
		}
		else
		{
			printf("Wrong password: %s\n",s);
			count++;
			if (count == n)
			{
				printf("Account locked\n");
				break;
			}
		}
	}
	return 0;
}
