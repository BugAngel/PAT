#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

const int maxn = 10005;

struct NODE
{
	int id;
	int x;
	int y;
	double len;
}stu[maxn];

bool cmp(struct NODE a, struct NODE b)
{
	return a.len < b.len;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> stu[i].id >> stu[i].x >> stu[i].y;
		stu[i].len = sqrt(1.0*stu[i].x*stu[i].x + 1.0*stu[i].y*stu[i].y);
	}
	sort(stu, stu + n, cmp);
	printf("%04d %04d\n",stu[0].id, stu[n - 1].id);
	return 0;
}