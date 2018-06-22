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

char s[10010];
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%s", s);
	int len = strlen(s);
	int hash[6] = { 0 };
	for (int i = 0; i < len; i++) {
		if (s[i] == 'P') {
			hash[0]++;
		}
		else if (s[i] == 'A') {
			hash[1]++;
		}
		else if (s[i] == 'T') {
			hash[2]++;
		}
		else if (s[i] == 'e') {
			hash[3]++;
		}
		else if (s[i] == 's') {
			hash[4]++;
		}
		else if (s[i] == 't') {
			hash[5]++;
		}
	}
	for (int i = 0; i < len; i++) {
		bool flag = false;
		if (hash[0] > 0) {
			hash[0]--;
			flag = true;
			printf("P");
		}
		if (hash[1] > 0) {
			hash[1]--;
			flag = true;
			printf("A");
		}
		if (hash[2] > 0) {
			hash[2]--;
			flag = true;
			printf("T");
		}
		if (hash[3] > 0) {
			hash[3]--;
			flag = true;
			printf("e");
		}
		if (hash[4] > 0) {
			hash[4]--;
			flag = true;
			printf("s");
		}
		if (hash[5] > 0) {
			hash[5]--;
			flag = true;
			printf("t");
		}
		if (flag == false) {
			break;
		}
	}
	return 0;
}
