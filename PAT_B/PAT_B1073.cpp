#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

//const int maxn = 100010;
map<char, int> charToInt;//a,b,c,d,e���ζ�Ӧ0��1��2��3��4
char intToChar[5] = { 'a','b','c','d','e' };

struct QUESTION
{
	int id;
	int score;//����ֵ
	int num;//ѡ�����
	int trueChoice;//��ȷѡ�����
	bool flag[5] = { false };
}ques[105];

struct XuanXiang
{
	int TiMu;
	int id;//a,b,c,d,e��Ӧ0��1��2��3��4
	int CuoWuShu;
}xuanxiang[500];

bool cmp(struct XuanXiang a, struct XuanXiang b)
{
	if (a.CuoWuShu == b.CuoWuShu && a.TiMu == b.TiMu)
	{
		return a.id < b.id;
	}
	else if (a.CuoWuShu == b.CuoWuShu)
	{
		return a.TiMu < b.TiMu;
	}
	else
	{
		return a.CuoWuShu > b.CuoWuShu;
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, m;//ѧ�����Ͷ�ѡ�����
	charToInt['a'] = 0;
	charToInt['b'] = 1;
	charToInt['c'] = 2;
	charToInt['d'] = 3;
	charToInt['e'] = 4;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		ques[i].id = i + 1;
		scanf("%d%d%d", &ques[i].score, &ques[i].num, &ques[i].trueChoice);//����ֵ ѡ�������ȷѡ�����
		for (int j = 0; j < ques[i].trueChoice; j++)//������ȷѡ��
		{
			char temp;
			scanf(" %c", &temp);
			ques[i].flag[charToInt[temp]] = true;
		}
	}
	getchar();//ȥ��\n

	//��ÿ�����ÿ��ѡ��ͳ�ƴ������
	int xuanxiangCount = 0;
	for (int i = 0; i < n; i++)//��ѭ������ÿ��ѧ��
	{
		double nowScore = 0.0;
		for (int j = 0; j < m; j++)//��ѭ��������ǰѧ������
		{
			int choiceNum;
			int tempDaAn[5] = { 0 };
			bool tiFlag = true;//Ϊfalse����������
			getchar();//ȥ��(
			scanf("%d", &choiceNum);//ѧ��ѡ�����
			
			for (int k = 0; k < 5; k++)//����ȷ�𰸶�����Ϊ1
			{
				if (ques[j].flag[k])
				{
					tempDaAn[k] = 1;
				}
			}
			for (int k = 0; k < choiceNum; k++)
			{
				char temp;
				scanf(" %c", &temp);
				if (ques[j].flag[charToInt[temp]])//ѡ��һ��ѡ��Ͱ���ȷ�������Ǹ�����Ϊ2
				{
					tempDaAn[charToInt[temp]] = 2;
				}
				else//ѡ��һ��ѡ��
				{
					xuanxiangCount = j * 5 + charToInt[temp];
					xuanxiang[xuanxiangCount].TiMu = j + 1;
					xuanxiang[xuanxiangCount].id = charToInt[temp];
					xuanxiang[xuanxiangCount].CuoWuShu ++;
					tiFlag = false;
				}
			}
			for (int k = 0; k < 5; k++)//ûѡ�ϵ�
			{
				if (tempDaAn[k] == 1)
				{
					xuanxiangCount = j * 5 + k;
					xuanxiang[xuanxiangCount].TiMu = j + 1;
					xuanxiang[xuanxiangCount].id = k;
					xuanxiang[xuanxiangCount].CuoWuShu++;
				}
			}
			if (tiFlag && choiceNum== ques[j].trueChoice)//ȫ��
			{
				nowScore = nowScore + 1.0*ques[j].score;
			}
			else if(tiFlag)//��ѡ
			{
				nowScore = nowScore + (1.0*ques[j].score) / 2.0;
			}

			getchar();//ȥ��)
			getchar();//ȥ�� ��\n
		}
		printf("%.1f\n", nowScore);//���ÿ��ѧ���÷�
	}

	sort(xuanxiang, xuanxiang + 500, cmp);
	if (xuanxiang[0].CuoWuShu == 0)
	{
		printf("Too simple\n");
	}
	else
	{
		printf("%d %d-%c\n", xuanxiang[0].CuoWuShu,xuanxiang[0].TiMu,intToChar[xuanxiang[0].id]);//����������ѡ����Ϣ
		for (int i = 1; xuanxiang[i].CuoWuShu == xuanxiang[0].CuoWuShu; i++)
		{
			printf("%d %d-%c\n", xuanxiang[i].CuoWuShu, xuanxiang[i].TiMu, intToChar[xuanxiang[i].id]);//�������
		}
	}
	return 0;
}