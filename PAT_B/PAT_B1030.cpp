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

const int  maxn = 100010;
int str[maxn];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n,p;
	scanf("%d %d", &n, &p);
	for (int i = 0; i < n; i++) {
		scanf("%d", &str[i]);
	}
	sort(str, str + n);

	int ans = 1;
	for (int i = 0; i < n; i++) {
		int j = upper_bound(str + i + 1, str + n, (long long)str[i] * p) - str;
		ans = max(ans, j - i);
	}
	printf("%d\n", ans);
	return 0;
}
