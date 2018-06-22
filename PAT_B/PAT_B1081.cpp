#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

const int maxn = 2010;
char temp[105];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	getchar();
	for (int i = 0; i < n; i++)
	{
		bool numFlag = false, wordFlag = false, luanFlag = false;
		cin.getline(temp,105);
		int len = strlen(temp);
		if (len < 6)
		{
			cout << "Your password is tai duan le.\n";
			continue;
		}
		for (int j = 0; j < len; j++)
		{
			if (temp[j] >= '0' && temp[j] <= '9')
			{
				numFlag = true;
			}
			else if((temp[j] >= 'a' && temp[j] <= 'z')|| (temp[j] >= 'A' && temp[j] <= 'Z'))
			{
				wordFlag = true;
			}
			else if (temp[j] == '.')
			{

			}
			else
			{
				cout << "Your password is tai luan le.\n";
				luanFlag = true;
				break;
			}
		}
		if (luanFlag == false)
		{
			if (numFlag == false)
			{
				cout << "Your password needs shu zi.\n";
			}
			else if (wordFlag == false)
			{
				cout << "Your password needs zi mu.\n";
			}
			else
			{
				cout << "Your password is wan mei.\n";
			}
		}
	}
	return 0;
}
