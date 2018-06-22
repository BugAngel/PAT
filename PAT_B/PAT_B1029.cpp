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

	char s1[85], s2[85];
	bool ShuChu[128] = { false };
	scanf("%s", s1);
	scanf("%s", s2);
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	for (int i = 0; i < len1; i++) {
		int flag = 0;//flag=0表示该字节在实际输出中没有出现
		for (int j = 0; j < len2; j++) {
			if (s1[i] == s2[j]) {
				flag = 1;
				continue;
			}
			else if (tolower(s1[i]) == tolower(s2[j])) {
				flag = 1;
				continue;
			}
		}
		char res = toupper(s1[i]);
		if (flag == 0 && ShuChu[res] == false) {
			ShuChu[res] = true;
			printf("%c", res);
		}
	}
	return 0;
}
