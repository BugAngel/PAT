#include <cstdio>
#include <cstring>
#include <cstdlib>

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int N;
	scanf("%d", &N);
	int JiaHe = 0, YiHe = 0;//�׺ȵģ��Һȵ�
	while (N > 0) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);//�׺� �׻� �Һ� �һ�
		if (b == d) {//ͬӮͬ����һ��
			//��continue�ᵼ�����N--û������
		}
		else if (a + c == b) {//�ײ���
			YiHe++;//�Һ�
		}
		else if (a + c == d) {//�Ҳ���
			JiaHe++;//�׺�
		}
		N--;
	}
	printf("%d %d", JiaHe, YiHe);
	return 0;
}

