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

	int pos = 0;//pos����ַ�����E��λ��
	while (str[pos] != 'E') {
		pos++;
	}

	int exp = 0;//exp�д��ָ�����Ȳ�����������
	for (int i = pos + 2; i < len; i++) {
		exp = exp * 10 + (str[i] - '0');
	}
	if (exp == 0) {//����ָ��Ϊ0���
		for (int i = 1; i < pos; i++) {
			printf("%c", str[i]);
		}
	}

	if (str[pos + 1] == '-') { //���ָ��Ϊ��
		printf("0.");
		for (int i = 0; i < exp - 1; i++) {//���(exp-1)��0
			printf("0");
		}
		printf("%c", str[1]);//�������С�������������
		for (int i = 3; i < pos; i++) {
			printf("%c", str[i]);
		}
	}
	else {
		for (int i = 1; i < pos; i++) {//���С�����ƶ������
			if (str[i] == '.') continue;//�Թ�С����
			printf("%c", str[i]);//�����ǰ��λ
			if (i == exp + 2 && pos - 3 != exp) {//С�������λ��exp+2��
				//ԭС�����E֮������ָ���(pos-3)���ܵ���С��������λ��exp
				printf(".");
			}
		}
		//���ָ��exp�ϴ���������0
		for (int i = 0; i < exp-(pos-3); i++) {
			printf("0");
		}
	}
	return 0;
}