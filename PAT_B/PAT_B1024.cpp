#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	char str[10010];
	scanf("%s", str);
	int len = strlen(str);
	if (str[0] == '-') printf("-");

	int pos = 0;//pos存放字符串中E的位置
	while (str[pos] != 'E') {
		pos++;
	}

	int exp = 0;//exp中存放指数（先不考虑正负）
	for (int i = pos + 2; i < len; i++) {
		exp = exp * 10 + (str[i] - '0');
	}
	if (exp == 0) {//特判指数为0情况
		for (int i = 1; i < pos; i++) {
			printf("%c", str[i]);
		}
	}

	if (str[pos + 1] == '-') { //如果指数为负
		printf("0.");
		for (int i = 0; i < exp - 1; i++) {//输出(exp-1)个0
			printf("0");
		}
		printf("%c", str[1]);//输出除了小数点以外的数字
		for (int i = 3; i < pos; i++) {
			printf("%c", str[i]);
		}
	}
	else {
		for (int i = 1; i < pos; i++) {//输出小数点移动后的数
			if (str[i] == '.') continue;//略过小数点
			printf("%c", str[i]);//输出当前数位
			if (i == exp + 2 && pos - 3 != exp) {//小数点加在位置exp+2上
				//原小数点和E之间的数字个数(pos-3)不能等于小数点右移位数exp
				printf(".");
			}
		}
		//如果指数exp较大，输出多余的0
		for (int i = 0; i < exp-(pos-3); i++) {
			printf("0");
		}
	}
	return 0;
}