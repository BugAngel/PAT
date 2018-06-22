#include <cstdio>
#include <cstring>
#include <cstdlib>

long long change(long long a, int Da) {
	int num[20];
	int count = 0,res=0;
	do {
		num[count] = a % 10;
		a /= 10;
		count++;
	} while (a != 0);
	for (int i = 0; i < count; i++) {
		if (num[i] == Da)
			res = res * 10 + Da;
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	long long A, Pa, B, Pb;
	int Da, Db;
	scanf("%lld%d%lld%d", &A, &Da, &B, &Db);
	Pa = change(A, Da);
	Pb = change(B, Db);
	printf("%lld", Pa + Pb);

	return 0;
}
