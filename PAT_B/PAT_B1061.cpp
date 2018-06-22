#include <cstdio>
#include <cstring>
#include <cstdlib>

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, m;//n是学生数,m是判断题数量
	int DaAn[105],score[105],stu[105];

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &score[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &DaAn[i]);
	}

	while (n) {
		int res=0;//输出的学生得分
		for (int i = 0; i < m; i++) {
			scanf("%d", &stu[i]);
			if (stu[i] == DaAn[i]) {
				res += score[i];
			}
		}
		if (n == 1) {
			printf("%d", res);
		}
		else {
			printf("%d\n", res);
		}
		n--;
	}
	return 0;
}

