#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

const int maxn = 10010;

char hand[15][30], eye[15][30], mouth[15][30];
char s[maxn];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int count = 0; //计算几个符号集
	//int temp=0;//遍历字符串
	int numHand, numEye, numMouth;//各个符号集符号的个数
	cin.getline(s,maxn);
	int len = strlen(s);
	for (int i = 0; i<len; i++)
	{
		if (s[i] == '[')
		{
			i++;
			int j;
			for (j = 0; s[i] != ']'; i++,j++)
			{
				hand[count][j] = s[i];
			}
			hand[count][j] = '\0';
			count++;
		}
	}
	numHand = count;

	count = 0;
	cin.getline(s, maxn);
	len = strlen(s);
	for (int i = 0; i<len; i++)
	{
		if (s[i] == '[')
		{
			i++;
			int j;
			for (j = 0; s[i] != ']'; i++, j++)
			{
				eye[count][j] = s[i];
			}
			eye[count][j] = '\0';
			count++;
		}
	}
	numEye = count;

	count = 0;
	cin.getline(s, maxn);
	len = strlen(s);
	for (int i = 0; i<len; i++)
	{
		if (s[i] == '[')
		{
			i++;
			int j;
			for (j = 0; s[i] != ']'; i++, j++)
			{
				mouth[count][j] = s[i];
			}
			mouth[count][j] = '\0';
			count++;
		}
	}
	numMouth = count;

	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
	{
		int num[5];
		scanf("%d%d%d%d%d", &num[0], &num[1], &num[2], &num[3], &num[4]);

		if (num[0] <= numHand &&num[1] <= numEye &&num[2] <= numMouth &&num[3] <= numEye &&num[4] <= numHand
			&& num[0] >0 && num[1] >0 && num[2] >0 && num[3] >0 && num[4] >0)
		{
			printf("%s(%s%s%s)%s\n", hand[num[0] - 1], eye[num[1] - 1], mouth[num[2] - 1], eye[num[3] - 1], hand[num[4] - 1]);
		}
		else
		{
			printf("Are you kidding me? @\\/@\n");
		}
	}
	return 0;
}
