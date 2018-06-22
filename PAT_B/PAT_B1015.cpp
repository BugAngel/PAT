#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>

using namespace std;

struct node {
	char s[10];
	int DeFen;
	int CaiFen;
	int score;//总分
	int flag;//flag==1才德全尽;flag==2才分不到但德分到线;flag==3德才分均低于H，但是德分不低于才分;其余flag==4
}stu[100010];

bool cmp(node a, node b) {
	if (a.flag != b.flag) {
		return a.flag < b.flag;
	}
	else if (a.score != b.score) {
		return a.score > b.score;
	}
	else if (a.DeFen != b.DeFen) {
		return a.DeFen > b.DeFen;
	}
	else {
		return strcmp(a.s, b.s) < 0;
	}


}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
 
	int n;//考生总数
	int L;//最低分数线
	int H;//最高分数线
	int sum = 0;
	scanf("%d %d %d", &n, &L, &H);

	for (int i = 0; i < n; i++) {
		char temp[10];
		int tempDe, tempCai;
		scanf("%s %d %d", temp, &tempDe, &tempCai);
		if (tempDe >= L && tempCai >= L) {
			if (tempDe >= H &&tempCai >= H) {
				stu[sum].flag = 1;
			}
			else if (tempDe >= H &&tempCai < H ) {
				stu[sum].flag = 2;
			}
			else if (tempDe < H &&tempCai < H &&tempDe >= tempCai) {
				stu[sum].flag = 3;
			}
			else
			{
				stu[sum].flag = 4;
			}

			stu[sum].CaiFen = tempCai;
			stu[sum].DeFen = tempDe;
			stu[sum].score = tempCai + tempDe;
			strcpy(stu[sum].s, temp);
			sum++;

		}

	}

	sort(stu, stu + sum, cmp);

	printf("%d\n", sum);
	for (int i = 0; i < sum; i++) {
		printf("%s %d %d\n", stu[i].s, stu[i].DeFen, stu[i].CaiFen);
	}
	return 0;
}

