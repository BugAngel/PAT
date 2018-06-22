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

bool cmp(int a, int b) {
	return a > b;
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	int ShuRu[310];
	int valid[310] = { 0 };
	bool flag[3030] = { false };
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &ShuRu[i]);
	}
	for (int i = 0; i < n; i++) {
		int temp = ShuRu[i];
		do {
			if (temp % 2 == 1) {
				temp = (3 * temp + 1) / 2;
			}
			else {
				temp /= 2;
			}
			if (flag[temp] == true) {
				break;
			}
			flag[temp] = true;
		} while (temp != 1);
	}
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (flag[ShuRu[i]] == false) {
			valid[count++] = ShuRu[i];
		}
	}
	//count--;
	sort(valid, valid + count, cmp);

	printf("%d", valid[0]);
	for (int i = 1; i < count; i++) {
		printf(" %d", valid[i]);
	}

	return 0;
}
