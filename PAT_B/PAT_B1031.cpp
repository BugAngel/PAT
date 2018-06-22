#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int n;
	int count = 0;
	char s[20];
	int a[17];
	int share[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };//ШЈжи
	char res[11] = { '1','0', 'X', '9', '8', '7', '6', '5', '4', '3', '2' };
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s",s);
		int sum = 0;
		for (int j = 0; j < 17; j++) {
			a[j] = s[j] - '0';
			sum += a[j] * share[j];
		}
		int b = sum % 11;
		if (s[17] != res[b]) {
			count++;
			printf("%s\n", s);
		}
	}
	if (count == 0) {
		printf("All passed\n");
	}
	return 0;
}
