#include <cstdio>
#include <cstring>
#include <cstdlib>

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	char s[85];
	char res[85][85];

	int  j = 0, k = 0, len;
	gets(s);//����ԭʼ�ַ���
	len = strlen(s);
	for (int i = 0; i <= len; i++) {
		if (s[i] != ' ') { 
			res[k][j] = s[i];
			j++;
		}else { //���ʽ���
			res[k][j] = '\0';
			k++;
			j = 0;
		}
	}
	//ѭ��������k���ü�һ����Ϊ����Ǹ�\0û����k��һ
	//while (scanf("%s", res[i++])!=EOF);
	for (; k > 0; k--)
		printf("%s ", res[k]);
	printf("%s", res[k]);

	return 0;
}
