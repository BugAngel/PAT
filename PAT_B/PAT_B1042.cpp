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

	char s[1005];
	int hash[26] = { 0 };
	gets(s);
	int len = strlen(s);
	for (int i = 0; i < len; i++) {
		if (isalpha(s[i])) {
			hash[tolower(s[i]) - 'a']++;
		}
	}
	int max = hash[0], cur = 0;
	for (int i = 1; i < 26; i++) {
		if (hash[i] > max) {
			max = hash[i];
			cur = i;
		}
	}
	printf("%c %d", cur + 'a', max);
	return 0;
}
