#include <cstdio>
#include <cstring>
#include <cstdlib>


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int A, B, D;
	int ans[31];
	int count = 0;
	scanf("%d%d%d", &A, &B,&D);
	int sum = A + B;
	do {
		ans[count++] = sum % D;
		sum /= D;
	} while (sum!=0);
	for (int i = count - 1; i >= 0; i--) {
		printf("%d",ans[i]);
	}
	return 0;
}

