#include <cstdio>
#include <cstring>
#include <cstdlib>

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int res[5] = { 0 };
	int n;
	int num[1005];
	int flag = -1;//�������A2ʱ�ķ���
	int count = 0;
	int countA2 = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
		if (num[i] % 10 == 0) { //����A1
			res[0] += num[i];
		}
		else if (num[i] % 5 == 1) { //����A2
			res[1] += -1 * flag*num[i];
			flag = -flag;
			countA2++; //res[1]������0
		}
		else if (num[i] % 5 == 2) { //����A3
			res[2]++;
		}
		else if (num[i] % 5 == 3) { //������������������ƽ������Ҫ������
			res[3] += num[i];
			count++;
		}
		else if(num[i] % 5 == 4) { //����A5 ����ֱ��else,�������ܱ�5�������������
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
