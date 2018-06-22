#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

const int maxn = 100010;
bool flag[maxn] = { false };
int couple[maxn];
vector<int>  linShi;
vector<int>  result;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	int temp, temp1, temp2;
	int count = 0;//老婆来了的客人数
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &temp1, &temp2);
		flag[temp1] = true;
		flag[temp2] = true;
		couple[temp1] = temp2;
		couple[temp2] = temp1;
	}

	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &temp);
		if (flag[temp] == true)//有老婆，不确定老婆来没来
		{
			linShi.push_back(temp);
		}
		else
		{
			result.push_back(temp);//没老婆的单身狗
		}
	}

	if (linShi.size() == 1)//只剩一个人，老婆肯定没来
	{
		result.push_back(linShi[0]);
	}
	else if(linShi.size()>1)
	{
		for (unsigned int i = 0; i < linShi.size(); i++)
		{
			bool tempFlag = false;
			for (unsigned int j = 0; j < linShi.size(); j++)
			{
				if (i != j)
				{
					if (couple[linShi[i]] == linShi[j])
					{
						count++;//老婆来了
						tempFlag = true;
						break;
					}
				}
			}
			if (tempFlag==false)
			{
				result.push_back(linShi[i]);
			}
		}
	}

	printf("%d\n", m - count);//总人数减去老婆来了的人数

	sort(result.begin(), result.end());
	if (result.size() == 0)
	{
		//printf("\n");
	}
	else
	{
		for (unsigned int i = 0; i < result.size() - 1; i++)
		{
			printf("%05d ", result[i]);
		}
		printf("%05d\n", result[result.size() - 1]);
	}
	return 0;
}
