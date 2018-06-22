#include <cstdio>
#include <cstring>
#include <cstdlib>

void reverse(int s[],int N) {
	int temp;
	for (int i = 0; i < N / 2; i++) {
		temp = s[i];
		s[i] = s[N - i - 1];
		s[N - i - 1] = temp;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int num, N;
	int s[105];
	scanf("%d%d", &num, &N);
        N = N % num;//题目没有说数组长度和右移长度的关系
	for (int i = 0; i < num; i++) {
		scanf("%d", &s[i]);
	}
	reverse(s, num);//全部反转
	reverse(s, N);//左边反转
	reverse(s + N, num - N);//右边反转
	for (int i = 0; i < num - 1; i++) {
		printf("%d ", s[i]);
	}
	printf("%d", s[num-1]);
	return 0;
}


