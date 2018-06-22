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

	int n;
	int hash[1005] = { 0 };
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int group, member, grade;
		scanf("%d-%d %d", &group, &member, &grade);
		hash[group] += grade;
	}
	int max = hash[0], cur = 0;
	for (int i = 1; i < 1005; i++) {
		if (hash[i] > max) {
			max = hash[i];
			cur = i;
		}
	}
	printf("%d %d", cur, max);
	return 0;
}

