#include <cstdio>
#include <cstring>
#include <cstdlib>

#define MAXN 100005

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int N;
	char C;
	scanf("%d %c", &N, &C);
	for (int i = 0; i < N; i++) {
		printf("%c", C);
	}
	printf("\n");
	int M;
	if (N % 2) {
		M = (N + 1) / 2;
	}
	else {
		M = N / 2;
	}
	for (int i = 0; i < M - 2; i++) {
		printf("%c", C);
		for (int j = 0; j < N - 2; j++)
			printf(" ");
		printf("%c", C);
		printf("\n");
	}
	for (int i = 0; i < N; i++) {
		printf("%c", C);
	}
	return 0;
}
