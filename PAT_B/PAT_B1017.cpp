#include <stdio.h>
#include <string.h>

char s[1010];
int A[1010];//被除数
int B;//除数
int Q[1010];//商
int R=0;//余数

void stringToInt(int len)
{
	for (int i = 0; i < len; i++)
	{
		A[i] = s[i] - '0';
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%s%d", s,&B);
	int len = strlen(s);
	stringToInt(len);

	int BeiChuShu;
	for (int i = 0; i < len; i++)
	{
		BeiChuShu = 10 * R + A[i];
		Q[i] = BeiChuShu / B;
		R= BeiChuShu % B;
	}

	if (len == 1 && A[0] < B)
	{
		printf("0 %d\n", A[0]);
	}
	else
	{
		if (Q[0] != 0)
		{
			printf("%d", Q[0]);
		}
		for (int i = 1; i < len; i++)
		{
			printf("%d", Q[i]);
		}
		printf(" %d\n", R);
	}
	return 0;
}
