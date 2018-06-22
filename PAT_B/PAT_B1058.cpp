#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

const int maxn = 100010;
struct QUESTION
{
	int id;
	int score;//满分值
	int num;//选项个数
	int trueChoice;//正确选项个数
	int numMistake=0;
	char s[10];//所有正确选项
}ques[105];

bool cmp(struct QUESTION a, struct QUESTION b)
{
	if(a.numMistake==b.numMistake)
	{
		return a.id < b.id;
	}
	else
	{
		return a.numMistake > b.numMistake;
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		ques[i].id = i + 1;
		scanf("%d%d%d", &ques[i].score, &ques[i].num, &ques[i].trueChoice);
		for (int j = 0; j < ques[i].trueChoice; j++)
		{
			scanf(" %c", &ques[i].s[j]);
		}
	}
	getchar();//去掉\n
	for (int i = 0; i < n; i++)//此循环遍历每个学生
	{
		int nowScore=0;
		for (int j = 0; j < m; j++)//此循环遍历当前学生的题
		{
			int choiceNum;
			getchar();//去掉(
			scanf("%d", &choiceNum);
			if (choiceNum == ques[j].trueChoice)
			{
				char temp;
				bool flag = true;
				for (int k = 0; k < choiceNum; k++)
				{
					scanf(" %c", &temp);
					if (ques[j].s[k] != temp)
					{
						if (flag)
						{
							ques[j].numMistake++;
						}					
						flag = false;
					}
				}
				if (flag)
				{
					nowScore+= ques[j].score;
				}
			}
			else
			{
				for (int k = 0; k < choiceNum; k++)//虽然不对，但还是要把需要输入的输入了
				{
					getchar();//去掉空格
					getchar();//去掉字符
				}
				ques[j].numMistake++;
			}
			getchar();//去掉)
			getchar();//去掉 或\n
		}
		printf("%d\n", nowScore);
	}
	sort(ques, ques + m, cmp);
	if (ques[0].numMistake == 0)
	{
		printf("Too simple\n");
	}
	else
	{
		printf("%d", ques[0].numMistake);//输出错题个数
		for (int i = 0; ques[i].numMistake == ques[0].numMistake; i++)
		{
			printf(" %d", ques[i].id);//输出错题编号
		}
		printf("\n");
	}
	return 0;
}