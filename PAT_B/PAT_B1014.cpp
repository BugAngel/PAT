#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	char week[7][4] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
	char s1[65], s2[65];
	int flag = 0;
	scanf("%s", s1);
	scanf("%s", s2);
	for (int i = 0; i < 65; i++) {
		if (flag == 1) {
			if ((s1[i] >= 'A' && s1[i] <= 'N' && s2[i] >= 'A' && s2[i] <= 'N') && s1[i] == s2[i]) {
				printf("%02d:", s1[i] - 'A' + 10);
				break;
			}
			if (s1[i] >= '0' && s1[i] <= '9' && s2[i] >= '0' && s2[i] <= '9' && s1[i] == s2[i]) {
				printf("%02d:", s1[i] - '0');
				break;
			}
		}
		if (flag == 0) {
			if (s1[i] >= 'A' && s1[i] <= 'G' && s2[i] >= 'A' && s2[i] <= 'G' && s1[i] == s2[i]) {
				printf("%s ", week[s1[i] - 'A']);
				flag = 1;
			}
		}

	}

	scanf("%s", s1);
	scanf("%s", s2);
	for (int i = 0; i < 65; i++) {
		if (s1[i] == s2[i] && isalpha(s1[i]) && isalpha(s2[i])) {
			printf("%02d", i);
			break;
		}
	}
	return 0;
}
