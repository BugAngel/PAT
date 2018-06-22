#include <cstdio>
#include <cstring>
#include <cstdlib>

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int N;
	scanf("%d", &N);
	int JiaHe = 0, YiHe = 0;//甲喝的，乙喝的
	while (N > 0) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);//甲喊 甲划 乙喊 乙划
		if (b == d) {//同赢同输下一局
			//用continue会导致最后N--没法运行
		}
		else if (a + c == b) {//甲猜中
			YiHe++;//乙喝
		}
		else if (a + c == d) {//乙猜中
			JiaHe++;//甲喝
		}
		N--;
	}
	printf("%d %d", JiaHe, YiHe);
	return 0;
}

