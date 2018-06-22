#include <cstdio>
#include <cstring>
#include <cstdlib>

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int a, b, c;
	int h, min, sec;
	int temp;
	scanf("%d%d", &a, &b);
	temp = (b - a)%100;//判断是舍还是入
	if (temp < 50) {
		c = (b - a) / 100;
	}
	else {
		c = (b - a) / 100 + 1;
	}
	h = c / 3600;
	min = c % 3600 / 60;
	sec = c % 3600 % 60;
	printf("%02d:%02d:%02d", h, min, sec);
	return 0;
}