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

int num[maxn];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int T, K;//ϵͳ�ڳ�ʼ״̬�����͸���ҵĳ��������Լ���Ҫ�������Ϸ����
	scanf("%d%d", &T, &K);
	for (int i = 0; i < K; i++)
	{
		int n1, b, t, n2;
		scanf("%d%d%d%d", &n1, &b, &t, &n2);
		if (t > T)
		{
			printf("Not enough tokens.  Total = %d.\n",T);
		}
		else
		{
			if ((b == 0 && n2 < n1) || (b == 1 && n2 > n1))//��С��ʤ��Ĵ��ʤ
			{
				T += t;
				printf("Win %d!  Total = %d.\n", t, T);
			}
			else
			{
				T -= t;
				printf("Lose %d.  Total = %d.\n", t, T);
			}
		}
		if (T == 0)
		{
			printf("Game Over.\n");
			break;
		}
	}
	return 0;
}
