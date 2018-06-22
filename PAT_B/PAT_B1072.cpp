#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

const int maxn = 10010;

bool flag[maxn] = { false };

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, m;//学生人数和需要被查缴的物品种类数
	scanf("%d%d", &n, &m);
	int stuSum = 0, thingSum = 0;
	for (int i = 0; i < m; i++)
	{
		int temp;
		scanf("%d", &temp);
		flag[temp] = true;
	}
	for (int i = 0; i < n; i++)
	{
		char temp[25];
		int k;
		bool stuFlag = false;
		scanf("%s%d", temp, &k);
		for (int j = 0; j < k; j++)
		{
			int id;
			scanf("%d", &id);
			if (flag[id])
			{
				thingSum++;
				if (stuFlag == false)
				{
					printf("%s: %04d", temp, id);
					stuSum++;
					stuFlag = true;
				}
				else
				{
					printf(" %04d", id);
				}
			}
		}
		if (stuFlag == true)
		{
			printf("\n");
		}
	}
	printf("%d %d", stuSum, thingSum);
	return 0;
}
