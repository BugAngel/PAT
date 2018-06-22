#include <stdio.h>
#include <string.h>

char DiWei[13][5] = { "tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
char GaoWei[12][4] = { "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };

char s[100];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++)
	{
		gets(s);	
		int len = strlen(s);
		if ((s[0] >= '0') && (s[0] <= '9'))//地球数字
		{
			int num;
			if (len == 3)
			{
				num = 100 * (s[0] - '0') + 10 * (s[1] - '0') + s[2] - '0';
			}
			else if (len == 2)
			{
				num = 10 * (s[0] - '0') + s[1] - '0';
			}
			else
			{
				num = s[0] - '0';
			}

			if (num / 13 != 0)//两位数
			{
				if (num % 13 != 0)
				{
					printf("%s %s\n", GaoWei[num / 13 - 1], DiWei[num % 13]);
				}
				else
				{
					printf("%s\n", GaoWei[num / 13 - 1]);
				}
			}
			else
			{
				printf("%s\n", DiWei[num % 13]);
			}		
		}
		else
		{
			if (len > 4)//两个火星文
			{
				char s1[4];
				int GaoNum;
				int DiNum;
				s1[0] = s[0];
				s1[1] = s[1];
				s1[2] = s[2];
				s1[3] = '\0';
				for (int j = 0; j < 12; j++)
				{
					if (strcmp(s1, GaoWei[j]) == 0)
					{
						GaoNum = j + 1;
						break;
					}
				}
				if (len > 7)//低位是0
				{
					printf("%d\n", GaoNum * 13);
				}
				else
				{
					s1[0] = s[4];
					s1[1] = s[5];
					s1[2] = s[6];
					s1[3] = '\0';
					for (int j = 1; j < 13; j++)
					{
						if (strcmp(s1, DiWei[j]) == 0)
						{
							DiNum = j;
							break;
						}
					}
					printf("%d\n", GaoNum * 13 + DiNum);
				}
			}
			else//一个火星文
			{
				if (len == 4)
				{
					printf("0\n");
				}
				else
				{
					int flag = 0;//为1表示低位已经找到
					for (int j = 0; j < 13; j++)
					{
						if (strcmp(s, DiWei[j]) == 0)
						{
							printf("%d\n", j);
							flag = 1;
							break;
						}
					}
					if (flag == 0)
					{
						for (int j = 0; j < 12; j++)
						{
							if (strcmp(s, GaoWei[j]) == 0)
							{
								printf("%d\n", (j+1) * 13);
								break;
							}
						}
					}
				}
			}
		}
	}
	return 0;
}

