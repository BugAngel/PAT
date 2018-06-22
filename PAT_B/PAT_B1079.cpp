#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

const int maxn = 2010;

char s[maxn];
char s2[maxn];
char result[maxn];

bool isPalindromic(char result[],int len)
{
	for (int i = 0; i < len / 2; i++)
	{
		if (result[i] != result[len - 1 - i])
		{
			return false;
		}
	}
	return true;
}

void sFanZhuan(char s[],char s2[],int len)//s��ת��Ľ���洢��s2
{
	for (int i = 0; i < (len+1) / 2; i++)
	{
		s2[i] = s[len - 1 - i];
		s2[len - 1 - i] = s[i];
	}
	s2[len] = '\0';
}

void resultFanZhuan(char s[], int len)//result��ת��Ľ���洢��ԭ��
{
	char t;
	for (int i = 0; i < (len + 1) / 2; i++)
	{
		t = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = t;
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	bool flag = false;
	cin >> s;
	if (isPalindromic(s, strlen(s)))
	{
		printf("%s is a palindromic number.\n", s);
		flag = true;
	}
	else
	{
		for (int i = 0; i < 10; i++)//һ��ʮ��
		{
			int C = 0;//��λ
			int len = strlen(s);
			sFanZhuan(s, s2, len);//���s��תǰ��
			for (int j = 0; j < len; j++)
			{
				result[j] = s[j] + s2[j] - '0' + C;
				if (result[j] > '9')
				{
					result[j] -= 10;
					C = 1;
				}
				else
				{
					C = 0;
				}
			}

			if (C == 1)
			{
				len += 1;
				result[len - 1] = '1';
			}
			result[len] = '\0';//ת�ַ���

			resultFanZhuan(result, len);
			printf("%s + %s = %s\n", s, s2, result);
			if (isPalindromic(result, len))
			{
				printf("%s is a palindromic number.\n", result);
				flag = true;
				break;
			}
			for (int j = 0; j < len; j++)
			{
				s[j] = result[j];
			}
			s[len] = '\0';
		}
	}

	if (flag == false)
	{
		printf("Not found in 10 iterations.\n");
	}
	return 0;
}
