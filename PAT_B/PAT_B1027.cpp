#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int pre[500] = { 0 };

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int res = 0, i = 1;
	while (res < 1000) {
		res = 2 * i*i - 1;
		pre[i] = res;
		i++;
	}
	i = i - 1;
	pre[i] = 0;

	int n,cur;
	char c;
	scanf("%d %c", &n,&c);
	for (int i = 1; pre[i] != 0; i++) {
		if (n == pre[i]) {
			cur = i;
			break;
		}
		if (n > pre[i] && n < pre[i + 1]) {
			cur = i;
			break;
		}
		if (n > pre[i] && pre[i + 1] == 0) {
			cur = i;
			break;
		}
	}

	/*�����ǣ���������Ǹ���*/
	i = cur;
	while (i > 1) {
		for (int j = 0; j < cur - i; j++) {
			printf(" ");
		}
		for (int j = 0; j < 2 * i - 1; j++) {
			printf("%c", c);
		}
		//for (int j = 0; j < cur - i; j++) {
		//	printf(" ");
		//}
		i--;
		printf("\n");
	}

	/*�����ǣ�����������*/
	i = 1;
	while (i <= cur) {
		for (int j = 0; j < cur - i; j++) {
			printf(" ");
		}
		for (int j = 0; j < 2 * i - 1; j++) {
			printf("%c", c);
		}
		//for (int j = 0; j < cur - i; j++) {
		//	printf(" ");
		//}
		i++;
		printf("\n");
	}

	printf("%d\n", n-pre[cur]);
	return 0;
}
