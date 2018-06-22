#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;
const int N = 10010;

//0是高位，3是低位
int BeiJianShu[4];//存储被减数
int JianShu[4];//存储减数

int beiJianShu;
int jianShu;
int result;

bool cmp(int a,int b)
{
	return a > b;
}

void TiQu(int n)//由输入数字产生被减数和减数
{
	int temp[4];
	temp[0] = n / 1000;
	temp[1] = n % 1000 / 100;
	temp[2] = n % 100 / 10;
	temp[3] = n % 10;

	sort(temp, temp + 4);//由小到大
	for (int i = 0; i < 4; i++)
	{
		JianShu[i] = temp[i];
	}
	sort(temp, temp + 4, cmp);//由大到小
	for (int i = 0; i < 4; i++)
	{
		BeiJianShu[i] = temp[i];
	}
	beiJianShu = BeiJianShu[0] * 1000 + BeiJianShu[1] * 100 + BeiJianShu[2] * 10 + BeiJianShu[3];
	jianShu = JianShu[0] * 1000 + JianShu[1] * 100 + JianShu[2] * 10 + JianShu[3];
	result = beiJianShu - jianShu;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &result);

	while (true)
	{
		TiQu(result);
		if (result == 0)
		{
			printf("%04d - %04d = 0000\n", beiJianShu, beiJianShu);
			return 0;
		}
		else if (result == 6174)
		{
			printf("%04d - %04d = 6174\n", beiJianShu, jianShu);
			return 0;
		}
		else
		{
			printf("%04d - %04d = %04d\n", beiJianShu, jianShu, result);
		}
	}
}
