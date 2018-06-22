#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	char A[110], B[110], ans[110] = { 0 };
	scanf("%s %s", A, B);
	int lenA = strlen(A);
	int lenB = strlen(B);
	int len = lenA > lenB ? lenA : lenB;
	reverse(A, A + lenA);
	reverse(B, B + lenB);
	for (int i = 0; i < len; i++) { //从低位开始
		int numA = i < lenA ? A[i] - '0' : 0;
		int numB = i < lenB ? B[i] - '0' : 0;
		if (i % 2 == 0) {
			int temp = (numB + numA) % 13;
			if (temp == 10) ans[i] = 'J';
			else if (temp == 11) ans[i] = 'Q';
			else if (temp == 12) ans[i] = 'K';
			else ans[i] = temp + '0';//0~9
		}
		else {
			int temp = numB - numA;//差
			if (temp < 0) temp += 10;
			ans[i] = temp + '0';
		}
	}
	reverse(ans, ans + strlen(ans));
	printf("%s", ans);
	return 0;
}