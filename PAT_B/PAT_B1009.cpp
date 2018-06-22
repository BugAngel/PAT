#include <cstdio>
#include <cstring>
#include <cstdlib>

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	char s[85];
	char res[85][85];

	int  j = 0, k = 0, len;
	gets(s);//输入原始字符串
	len = strlen(s);
	for (int i = 0; i <= len; i++) {
		if (s[i] != ' ') { 
			res[k][j] = s[i];
			j++;
		}else { //单词结束
			res[k][j] = '\0';
			k++;
			j = 0;
		}
	}
	//循环结束后k不用减一，因为最后那个\0没有让k加一
	//while (scanf("%s", res[i++])!=EOF);
	for (; k > 0; k--)
		printf("%s ", res[k]);
	printf("%s", res[k]);

	return 0;
}
