#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int n;
	scanf("%d", &n);

	int BaiWei;
	BaiWei = n / 100;
	for (int i = 0; i < BaiWei; i++) {
		printf("B");
	}

	int ShiWei;
	ShiWei = n % 100 / 10;
	for (int i = 0; i < ShiWei; i++) {
		printf("S");
	}

	int GeWei;
	GeWei = n % 10;
	for (int i = 1; i <= GeWei; i++) {
		printf("%d", i);
	}
	return 0;
}

