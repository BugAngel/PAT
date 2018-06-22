#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	char s[1005] = { '\0' };
	int num[10] = { 0 };
	scanf("%s", s);
	for (int i = 0; s[i] != '\0'; i++) {
		num[s[i] - '0']++;
	}

	for (int i = 0; i < 10; i++) {
		if (num[i] != 0) {
			printf("%d:%d\n", i,num[i]);
		}
		
	}
	return 0;
}

