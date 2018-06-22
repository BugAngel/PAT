#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int d1, d2;
	scanf("%d%d", &d1, &d2);
	if (d1 == 0) {
		printf("0 0");
	}
	else if(d2!=0){
		printf("%d %d", d1*d2, d2 - 1);
	}
	else {
		printf("0 0");
	}
	
	while (scanf("%d%d", &d1, &d2) != EOF) {
		if (d1 == 0) {
			printf(" 0 0");
		}
		else if(d2!=0){
			printf(" %d %d", d1*d2, d2 - 1);
		}
	}

	return 0;
}

