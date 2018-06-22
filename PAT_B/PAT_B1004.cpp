#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct Node {
	char name[20];
	char id[20];
	int score;
}stu[1005];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int n,max=-1,min=101;
	int maxID, minID;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s%s%d", stu[i].name, stu[i].id, &stu[i].score);
		if (stu[i].score > max) {
			max = stu[i].score;
			maxID = i;
		}
		if (stu[i].score < min) {
			min = stu[i].score;
			minID = i;
		}
	}
	printf("%s %s\n", stu[maxID].name, stu[maxID].id);
	printf("%s %s", stu[minID].name, stu[minID].id);

	return 0;
}
