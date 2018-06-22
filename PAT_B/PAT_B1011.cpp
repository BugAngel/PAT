#include <cstdio>
#include <cstring>
#include <cstdlib>

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int T;
	long long A, B, C;
	int count = 1;
	scanf("%d", &T);
	while (T > 0) {
		scanf("%lld%lld%lld", &A, &B, &C);
		if (A + B > C) {
			printf("Case #%d: true\n", count);
			count++;
		}else {
			printf("Case #%d: false\n", count);
			count++;
		}
		T--;
	}

	return 0;
}
