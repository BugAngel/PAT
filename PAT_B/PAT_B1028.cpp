#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct node {
	char name[20];
	int year;
	int month;
	int day;
}person[100010];

bool JudgeLegal(int year, int month, int day) { //判断是否合理
	if (year > 1814 && year<2014) {
		return true;
	}
	else if (year == 1814 && month > 9) {
		return true;
	}
	else if (year == 1814 && month == 9 && day >= 6) {
		return true;
	}
	else if (year == 2014 && month < 9) {
		return true;
	}
	else if (year == 2014 && month == 9 && day <= 6) {
		return true;
	}
	else {
		return false;
	}
}

bool JudgeElder(struct node a,int* num,int i) { //判断是不是岁数最大
	if (a.year < person[*num].year) {
		*num = i;
		return true;
	}
	else if (a.year == person[*num].year && a.month < person[*num].month) {
		*num = i;
		return true;
	}
	else if (a.year == person[*num].year && a.month == person[*num].month && a.day < person[*num].day) {
		*num = i;
		return true;
	}
	else {
		return false;
	}
}

bool JudgeSmaller(struct node a, int* num,int i) { //判断是不是岁数最小
	if (a.year > person[*num].year) {
		*num = i;
		return true;
	}
	else if (a.year == person[*num].year && a.month > person[*num].month) {
		*num = i;
		return true;
	}
	else if (a.year == person[*num].year && a.month == person[*num].month && a.day > person[*num].day) {
		*num = i;
		return true;
	}
	else {
		return false;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int n;
	int count = 0;
	int ElderPerson=10010,SmallerPerson=10009;
	person[ElderPerson].year = 2014;
	person[ElderPerson].month = 9;
	person[ElderPerson].day = 6;
	person[SmallerPerson].year = 1814;
	person[SmallerPerson].month = 9;
	person[SmallerPerson].day = 6;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s %d/%d/%d", person[i].name, &person[i].year, &person[i].month, &person[i].day);
		if (JudgeLegal(person[i].year, person[i].month, person[i].day) == true) { //如果合理
			count++;
			JudgeElder(person[i], &ElderPerson,i);
			JudgeSmaller(person[i], &SmallerPerson,i);
		}
	}
	if (count == 0) {
		printf("0");
	}
	else {
		printf("%d %s %s", count, person[ElderPerson].name, person[SmallerPerson].name);
	}
	
	return 0;
}
