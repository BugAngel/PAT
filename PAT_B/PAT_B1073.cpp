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
map<char, int> charToInt;//a,b,c,d,e依次对应0、1、2、3、4
char intToChar[5] = { 'a','b','c','d','e' };

struct QUESTION
{
	int id;
	int score;//满分值
	int num;//选项个数
	int trueChoice;//正确选项个数
	bool flag[5] = { false };
}ques[105];

struct XuanXiang
{
	int TiMu;
	int id;//a,b,c,d,e对应0、1、2、3、4
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

	int n, m;//学生数和多选题个数
	charToInt['a'] = 0;
	charToInt['b'] = 1;
	charToInt['c'] = 2;
	charToInt['d'] = 3;
	charToInt['e'] = 4;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		ques[i].id = i + 1;
		scanf("%d%d%d", &ques[i].score, &ques[i].num, &ques[i].trueChoice);//满分值 选项个数正确选项个数
		for (int j = 0; j < ques[i].trueChoice; j++)//所有正确选项
		{
			char temp;
			scanf(" %c", &temp);
			ques[i].flag[charToInt[temp]] = true;
		}
	}
	getchar();//去掉\n

	//对每个题的每个选项统计错误次数
	int xuanxiangCount = 0;
	for (int i = 0; i < n; i++)//此循环遍历每个学生
	{
		double nowScore = 0.0;
		for (int j = 0; j < m; j++)//此循环遍历当前学生的题
		{
			int choiceNum;
			int tempDaAn[5] = { 0 };
			bool tiFlag = true;//为false则这道题错了
			getchar();//去掉(
			scanf("%d", &choiceNum);//学生选题个数
			
			for (int k = 0; k < 5; k++)//把正确答案都设置为1
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
				if (ques[j].flag[charToInt[temp]])//选对一个选项就把正确答案里面那个设置为2
				{
					tempDaAn[charToInt[temp]] = 2;
				}
				else//选错一个选项
				{
					xuanxiangCount = j * 5 + charToInt[temp];
					xuanxiang[xuanxiangCount].TiMu = j + 1;
					xuanxiang[xuanxiangCount].id = charToInt[temp];
					xuanxiang[xuanxiangCount].CuoWuShu ++;
					tiFlag = false;
				}
			}
			for (int k = 0; k < 5; k++)//没选上的
			{
				if (tempDaAn[k] == 1)
				{
					xuanxiangCount = j * 5 + k;
					xuanxiang[xuanxiangCount].TiMu = j + 1;
					xuanxiang[xuanxiangCount].id = k;
					xuanxiang[xuanxiangCount].CuoWuShu++;
				}
			}
			if (tiFlag && choiceNum== ques[j].trueChoice)//全对
			{
				nowScore = nowScore + 1.0*ques[j].score;
			}
			else if(tiFlag)//少选
			{
				nowScore = nowScore + (1.0*ques[j].score) / 2.0;
			}

			getchar();//去掉)
			getchar();//去掉 或\n
		}
		printf("%.1f\n", nowScore);//输出每个学生得分
	}

	sort(xuanxiang, xuanxiang + 500, cmp);
	if (xuanxiang[0].CuoWuShu == 0)
	{
		printf("Too simple\n");
	}
	else
	{
		printf("%d %d-%c\n", xuanxiang[0].CuoWuShu,xuanxiang[0].TiMu,intToChar[xuanxiang[0].id]);//输出错的最多的选项信息
		for (int i = 1; xuanxiang[i].CuoWuShu == xuanxiang[0].CuoWuShu; i++)
		{
			printf("%d %d-%c\n", xuanxiang[i].CuoWuShu, xuanxiang[i].TiMu, intToChar[xuanxiang[i].id]);//输出并列
		}
	}
	return 0;
}