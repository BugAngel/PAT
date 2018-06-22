#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

//const int maxn = 100010;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	string n, num1, num2;//进制表与两个数
	string result;//结果反着来
	int C = 0, len;//进位与最短字符串长度
	cin >> n >> num1 >> num2;
	int len0 = n.length();
	int len1 = num1.length();
	int len2 = num2.length();
	if (len1 > len2)
	{
		len = len2;
		result.resize(len1);
	}
	else
	{
		len = len1;
		result.resize(len2);
	}
	reverse(n.begin(), n.end());
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	for (int i = 0; i < len; i++)
	{
		int jinZhi;
		int sum;//两位相加的和
		jinZhi = n[i] - '0';
		sum = num1[i] + num2[i] + C - '0' - '0';
		if (jinZhi == 0)
		{
			jinZhi = 10;
		}
		if (sum >= jinZhi)
		{
			C = 1;
			sum -= jinZhi;
		}
		else
		{
			C = 0;
		}
		result[i]= sum + '0';
	}

	if (len1 > len2)
	{
		for (int i = len2; i < len1; i++)
		{
			int jinZhi;
			int sum;//两位相加的和
			jinZhi = n[i] - '0';
			sum = num1[i] + C - '0';
			if (jinZhi == 0)
			{
				jinZhi = 10;
			}
			if (sum >= jinZhi)
			{
				C = 1;
				sum -= jinZhi;
			}
			else
			{
				C = 0;
			}
			result[i] = sum + '0';
		}
		if (C)
		{
			result.resize(len1 + 1);
			result[len1] = '1';
		}
	}
	else
	{
		for (int i = len1; i < len2; i++)
		{
			int jinZhi;
			int sum;//两位相加的和
			jinZhi = n[i] - '0';
			sum = num2[i] + C - '0';
			if (jinZhi == 0)
			{
				jinZhi = 10;
			}
			if (sum >= jinZhi)
			{
				C = 1;
				sum -= jinZhi;
			}
			else
			{
				C = 0;
			}
			result[i] = sum + '0';
		}
		if (C)
		{
			result.resize(len2 + 1);
			result[len2] = '1';
		}
	}
	reverse(result.begin(), result.end());
	int count = 0;//开头0的个数
	while (result[count] == '0')
	{
		count++;
	}
	if (result[0] == '0')
	{
		result.erase(0, count);//从0号位开始删，删count个
	}
	
	if (result.length() != 0)
	{
		cout << result << endl;
	}
	else
	{
		cout << '0' << endl;
	}
	return 0;
}
