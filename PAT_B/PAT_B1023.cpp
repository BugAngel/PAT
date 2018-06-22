#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
 
	int num[10];
	int flag = 0;
	for (int i = 0; i < 10; i++) {
		scanf("%d", &num[i]);
	}
	for (int i = 1; i < 10; i++) {
		if (num[i] != 0) {
			printf("%d", i);
			num[i] -= 1;
			flag = 1;
		}
		if (flag == 1) {
			break;
		}
	}

	for (int i = 0; i < 10; i++) {
		if (num[i] > 0) {
			for (int j = 0; j < num[i]; j++) {
				printf("%d", i);
			}
		}
	}
	return 0;
}
