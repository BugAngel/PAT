#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

const int maxn = 100005;

map<string, int> ID;
map<int, string> school;

struct NODE
{
	string name;
	double score = 0.0;//实际的总分
	int shuChuScore;//输出的总分
	int rank;//学校排名
	int num = 0;//考生人数
}sch[maxn];

bool cmp(struct NODE a, struct NODE b)
{
	if (a.shuChuScore == b.shuChuScore && a.num == b.num)
	{
		return a.name < b.name;
	}
	if (a.shuChuScore == b.shuChuScore)
	{
		return a.num < b.num;
	}
	return a.shuChuScore > b.shuChuScore;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	int count = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string id, college;
		int score;
		cin >> id >> score >> college;
		for (int j = 0; j < college.length(); j++)
		{
			if (college[j] >= 'A' && college[j] <= 'Z')
			{
				college[j] = college[j] - 'A' + 'a';
			}
		}
		if (ID[college] == 0)//没有列入编号
		{
			sch[count].name = college;
			ID[college] = count;
			school[count] = college;
			count++;
		}
		sch[ID[college]].num++;//考生人数加一
		if (id[0] == 'B')
		{
			sch[ID[college]].score = sch[ID[college]].score + 1.0*score / 1.5;
		}
		else if (id[0] == 'A')
		{
			sch[ID[college]].score = sch[ID[college]].score + 1.0*score;
		}
		else
		{
			sch[ID[college]].score = sch[ID[college]].score + 1.0*score * 1.5;
		}
	}
	for (int i = 1; i < count; i++)
	{
		sch[i].shuChuScore = (int)sch[i].score;
	}
	sort(sch + 1, sch + count, cmp);
	cout << count - 1 << endl;
	sch[1].rank = 1;
	printf("1 %s %d %d\n", sch[1].name.c_str(), sch[1].shuChuScore, sch[1].num);
	for (int i = 2; i < count; i++)
	{
		if (sch[i].shuChuScore == sch[i - 1].shuChuScore)
		{
			sch[i].rank = sch[i - 1].rank;
		}
		else
		{
			sch[i].rank = i;
		}
		printf("%d %s %d %d\n", sch[i].rank,sch[i].name.c_str(), sch[i].shuChuScore, sch[i].num);
	}
	return 0;
}
