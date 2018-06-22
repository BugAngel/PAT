#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

const int maxn = 10010;

struct NODE
{
	int rank;//排名
	int flag = 0;//0表示没有这个信息，1表示有信息，2表示查询过一次
}stu[maxn];

int pNum = 0, prime[maxn];
bool p[maxn] = { false };

void findPrime()
{
	for (int i = 2; i < maxn; i++)
	{
		if (p[i] == false)
		{
			prime[pNum++] = i;
			for (int j = i + i; j < maxn; j+=i)
			{
				p[j] = true;
			}
		}
	}
}

bool isPrime(int a)
{
	for (int i = 0; i < pNum; i++)
	{
		if (a == prime[i])
		{
			return true;
		}
	}
	return false;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	int temp;
	findPrime();
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		stu[temp].rank = i + 1;
		stu[temp].flag = 1;
	}

	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
	{
		scanf("%d", &temp);
		if (stu[temp].flag == 0)
		{
			printf("%04d: Are you kidding?\n", temp);
		}
		else if (stu[temp].flag == 2)
		{
			printf("%04d: Checked\n", temp);
		}
		else
		{
			if (stu[temp].rank == 1)
			{
				printf("%04d: Mystery Award\n", temp);
			}
			else if (isPrime(stu[temp].rank))
			{
				printf("%04d: Minion\n", temp);
			}
			else
			{
				printf("%04d: Chocolate\n", temp);
			}
			stu[temp].flag = 2;
		}
	}
	return 0;
}
