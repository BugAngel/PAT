#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, temp, k;
	int hash[101] = { 0 };
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		hash[temp]++;
	}
	scanf("%d", &k);
	scanf("%d", &temp);
	printf("%d", hash[temp]);
	for (int i = 0; i < k-1; i++) {
		scanf("%d", &temp);
		printf(" %d", hash[temp]);
	}
	return 0;
}

