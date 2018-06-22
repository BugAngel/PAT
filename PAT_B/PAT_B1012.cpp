#include <cstdio>
#include <cstring>
#include <cstdlib>

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int res[5] = { 0 };
	int n;
	int num[1005];
	int flag = -1;//处理计算A2时的符号
	int count = 0;
	int countA2 = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
		if (num[i] % 10 == 0) { //计算A1
			res[0] += num[i];
		}
		else if (num[i] % 5 == 1) { //计算A2
			res[1] += -1 * flag*num[i];
			flag = -flag;
			countA2++; //res[1]可能是0
		}
		else if (num[i] % 5 == 2) { //计算A3
			res[2]++;
		}
		else if (num[i] % 5 == 3) { //计算总数，算完了求平均数需要再另算
			res[3] += num[i];
			count++;
		}
		else if(num[i] % 5 == 4) { //计算A5 不能直接else,否则会把能被5除的奇数算进来
			if (num[i] > res[4]) {
				res[4] = num[i];
			}
		}
	}

	if (res[0] == 0) {
		printf("N ");
	}
	else {
		printf("%d ", res[0]);
	}

	if (countA2 == 0) {
		printf("N ");
	}
	else {
		printf("%d ", res[1]);
	}

	if (res[2] == 0) {
		printf("N ");
	}
	else {
		printf("%d ", res[2]);
	}

	if (res[3] == 0) {
		printf("N ");
	}
	else {
		printf("%.1f ", (double)res[3] / count);
	}

	if (res[4] == 0) {
		printf("N");
	}
	else {
		printf("%d", res[4]);
	}

	return 0;
}
