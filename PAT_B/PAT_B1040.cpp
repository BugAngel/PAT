#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>

using namespace std;

char s[100010];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
 
	scanf("%s", s);
	int len = strlen(s);
	int numT = 0;//�ַ������ܹ��ж��ٸ�T
	int res = 0;//���

	for (int i = 0; i < len; i++) { //ͳ���ַ������ж��ٸ�T
		if (s[i] == 'T') {
			numT++;
		}
	}

	int left = 0;//���P�ĸ���
	int right = numT;//�ұ�T�ĸ���
	if (s[0] == 'P') {
		left++;
	}
	else if (s[0] == 'T') {
		right--;
	}
	for (int i = 1; i < len-1; i++) { //��A
		if (s[i] == 'A') {
			res = (res + left * right) % 1000000007;
		}
		else if (s[i] == 'P') {
			left++;
		}
		else {
			right--;
		}
	}
	printf("%d", res);
	return 0;
}
