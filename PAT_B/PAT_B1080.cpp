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

map<string, int> id;//学号转id
map<int, string> XueHao;//id转学号

struct NODE
{
	int id;
	int Gp = -1;
	int Gmid = -1;
	int Gfinal = -1;
	int G;//总分
}stu[30010];

bool cmp(struct NODE a, struct NODE b)
{
	if (a.G == b.G)
	{
		return XueHao[a.id]<XueHao[b.id];
	}
	return a.G > b.G;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int p, m, n;
	string temp;
	int score;
	int count = 1;//从1开始编号
	cin >> p >> m >> n;
	for (int i = 0; i < p; i++)
	{
		cin >> temp >> score;
		if (score >= 200)
		{
			if (id[temp] == 0)//还没有被编号
			{
				id[temp] = count;
				XueHao[count] = temp;
				stu[count].Gp = score;
				stu[count].id = count;
				count++;
			}
			else
			{
				stu[id[temp]].Gp = score;
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		cin >> temp >> score;
		if (id[temp] != 0)//必须要有编号，编程不能少于200
		{
			stu[id[temp]].Gmid = score;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cin >> temp >> score;
		if (id[temp] != 0)//必须要有编号，编程不能少于200
		{
			stu[id[temp]].Gfinal = score;
		}
	}
	for (int i = 0; i < count; i++)
	{
		if (stu[i].Gmid > stu[i].Gfinal)
		{
			if (stu[i].Gfinal != -1)
			{
				stu[i].G = (int)(stu[i].Gmid*0.4 + stu[i].Gfinal*0.6 + 0.5);
			}
			else
			{
				stu[i].G = (int)(stu[i].Gmid*0.4 + 0.5);
			}
		}
		else
		{
			stu[i].G = stu[i].Gfinal;
		}
	}
	sort(stu, stu + count, cmp);

	for (int i = 0; i < count; i++)
	{
		if (stu[i].G >= 60)
		{
			printf("%s %d %d %d %d\n", XueHao[stu[i].id].c_str(), stu[i].Gp, stu[i].Gmid, stu[i].Gfinal, stu[i].G);
		}
		else
		{
			break;
		}
	}
	return 0;
}
