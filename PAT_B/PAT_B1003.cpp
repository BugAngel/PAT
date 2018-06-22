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
const int N = 1000010;


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		char s[105];
		scanf("%s", s);
		int len = strlen(s);
		int countP = 0, countA = 0, countT = 0;//����P��A��T��Ŀ
		int countLeftA = 0;//����P����ж���A
		int countMiddleA = 0;//����P��T�м��ж���A
		int countRightA = 0;//����T�ұ��ж���A
		int flag = 1;
		for (int j = 0; j < len; j++)
		{
			if (s[j] == 'P' && (countT == 0))
			{
				countP++;
			}
			else if (s[j] == 'A')
			{
				countA++;
			}
			else if(s[j] == 'T' && (countP ==1))
			{
				countT++;
			}
			else//�ж�����1
			{
				printf("NO\n");
				flag = 0;
				break;
			}
			if (countP == 0 && s[j] == 'A')
			{
				countLeftA++;
			}
			else if(countP == 1&& countT==0 && s[j] == 'A')
			{
				countMiddleA++;
			}
			else if(countT==1 && s[j] == 'A')
			{
				countRightA++;
			}

			if (countP > 1 || countT > 1)
			{
				printf("NO\n");
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			if (countP == 0 || countT == 0 ||countA==0)
			{
				printf("NO\n");
			}
			else if ((countRightA - countLeftA * (countMiddleA - 1)) == countLeftA)
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}
	}
	return 0;

}
