#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

const int maxn = 10010;

char s[105];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	int countNum=0;
	double sum=0.0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", s);
		int len = strlen(s);
		int countXiaoShuDian = 0;//小数点个数
		int countFuHao = 0;//负号个数
		int jingDu = 0;
		bool flag = true;//为true表示字符串是一个数
		for (int j = 0; j < len; j++)
		{
			if (s[j]>='0' && s[j]<='9')
			{

			}
			else if (s[j] == '.')
			{
				countXiaoShuDian++;
				if (countXiaoShuDian > 1)//小数点个数多了
				{
					printf("ERROR: %s is not a legal number\n", s);
					flag = false;
					break;
				}
				if (len - j - 1 > 2)//小数点后面位数多了
				{
					printf("ERROR: %s is not a legal number\n", s);
					flag = false;
					break;
				}
			}
			else if (s[j] == '-')
			{
				countFuHao++;
				if (countFuHao > 1)//负号个数多了
				{
					printf("ERROR: %s is not a legal number\n", s);
					flag = false;
					break;
				}
			}
			else
			{
				printf("ERROR: %s is not a legal number\n", s);
				flag = false;
				break;
			}
		}
		if (flag)
		{
			double num = atof(s);
			if (num >= -1000 && num <= 1000)
			{
				countNum++;
				sum += num;
			}
			else
			{
				printf("ERROR: %s is not a legal number\n", s);
			}
		}
	}
	if (countNum > 1)
	{
		printf("The average of %d numbers is %.2f\n", countNum, sum / countNum);
	}
	else if (countNum == 1)
	{
		printf("The average of 1 number is %.2f\n", sum / countNum);
	}
	else
	{
		printf("The average of 0 numbers is Undefined\n");
	}
	return 0;
}
