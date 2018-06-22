#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	char s[105] = {'\0'};
	int a[105];
	scanf("%s", s);
	char num[10][10] = { "ling\0","yi\0" ,"er\0","san\0","si\0","wu\0","liu\0","qi\0","ba\0","jiu\0"};
	int sum = 0;
	
	for (int i = 0; s[i] != '\0'; i++) {
		sum += (s[i] - '0');
	}
	int i = 0;
	do {
		a[i++] = sum % 10;
		sum /= 10;
	} while (sum != 0);
	i = i - 1;
	for (; i > 0; i--) {
		printf("%s ", num[a[i]]);
	}
	printf("%s", num[a[i]]);
	return 0;
}

