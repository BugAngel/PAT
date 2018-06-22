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

	char s1[1005], s2[1005];
	int hash[62] = { 0 };//0~9对应0~9,a~z对应10~35,A~Z对应36~61
	scanf("%s", s1);
	scanf("%s", s2);

	int len1 = strlen(s1);
	int len2 = strlen(s2);

	for (int i = 0; i < len1; i++) {
		if ('0' <= s1[i] && s1[i] <= '9') {
			hash[s1[i]-'0']++;
		}
		else if ('a' <= s1[i] && s1[i] <= 'z') {
			hash[s1[i] - 'a' + 10]++;
		}
		else if ('A' <= s1[i] && s1[i] <= 'Z') {
			hash[s1[i] - 'A' + 36]++;
		}
	}

	bool flag = true;//默认够用
	for (int i = 0; i < len2; i++) {
		if ('0' <= s2[i] && s2[i] <= '9') {
			hash[s2[i]-'0']--;
			if (hash[s2[i]-'0'] < 0) {
				flag = false;
			}
		}
		else if ('a' <= s2[i] && s2[i] <= 'z') {
			hash[s2[i] - 'a' + 10]--;
			if (hash[s2[i] - 'a' + 10] < 0) {
				flag = false;
			}
		}
		else if ('A' <= s2[i] && s2[i] <= 'Z') {
			hash[s2[i] - 'A' + 36]--;
			if (hash[s2[i] - 'A' + 36] < 0) {
				flag = false;
			}
		}
	}
	int sum = 0;
	if (flag == true) {
		printf("Yes ");
		for (int i = 0; i < 62; i++) {
			sum += hash[i];
		}
		printf("%d", sum);
	}
	else {
		printf("No ");
		for (int i = 0; i < 62; i++) {
			if (hash[i] < 0) {
				sum += hash[i];
			}			
		}
		printf("%d", -sum);
	}
	return 0;
}
