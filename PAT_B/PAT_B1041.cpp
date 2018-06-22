#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct Node {
	char id[20];
	int test;
	int exam;
}stu[1005];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s%d%d", stu[i].id, &stu[i].test, &stu[i].exam);
	}

	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		if (i != 0) {
			printf("\n");
		}
		int temp;
		scanf("%d", &temp);
		for (int i = 0; i < n; i++) {
			if (temp == stu[i].test) {
				printf("%s %d", stu[i].id, stu[i].exam);
			}
		}
	}
	return 0;
}

