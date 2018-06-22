#include <cstdio>
#include <cstring>
#include <cstdlib>

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);	
	char Jia, Yi;
	int ScoreJia[3] = { 0 }, ScoreYi[3] = { 0 };//����ʤƽ���Ĵ���
	int GestureJia[3] = { 0 }, GestureYi[3] = { 0 };//����ÿ�����ƻ�ʤ�Ĵ���,����Ϊ�������ӣ������������ֵ�����С��������

	for (int i = 0; i < n; i++) {
		getchar();//ȥ��\n
		scanf("%c %c", &Jia, &Yi);
		if (Jia == 'C'&&Yi == 'J') {//�״��ӣ��Ҽ���
			ScoreJia[0]++;//��ʤ
			ScoreYi[2]++;//�Ҹ�
			GestureJia[1]++;
		}
		else if(Jia == 'C'&&Yi == 'B') { //�״��ӣ��Ҳ�
			ScoreJia[2]++;//�׸�
			ScoreYi[0]++;//��ʤ
			GestureYi[0]++;
		}
		else if (Jia == 'J'&&Yi == 'B') {//�׼������Ҳ�
			ScoreJia[0]++;//��ʤ
			ScoreYi[2]++;//�Ҹ�
			GestureJia[2]++;
		}
		else if (Jia == 'J'&&Yi == 'C') {//�׼������Ҵ���
			ScoreJia[2]++;//�׸�
			ScoreYi[0]++;//��ʤ
			GestureYi[1]++;
		}
		else if (Jia == 'B'&&Yi == 'J') {//�ײ����Ҽ���
			ScoreJia[2]++;//�׸�
			ScoreYi[0]++;//��ʤ
			GestureYi[2]++;
		}
		else if (Jia == 'B'&&Yi == 'C') {//�ײ����Ҵ���
			ScoreJia[0]++;//��ʤ
			ScoreYi[2]++;//�Ҹ�
			GestureJia[0]++;
		}
		else { //ƽ��
			ScoreJia[1]++;
			ScoreYi[1]++;
		}
	}
	printf("%d %d %d\n", ScoreJia[0], ScoreJia[1], ScoreJia[2]);
	printf("%d %d %d\n", ScoreYi[0], ScoreYi[1], ScoreYi[2]);

	if ((GestureJia[2] > GestureJia[1]) && (GestureJia[2] > GestureJia[0])) {
		printf("J ");
	}
	else if ((GestureJia[1] > GestureJia[0]) && (GestureJia[1] >= GestureJia[2])) {
		printf("C ");
	}
	else {
		printf("B ");
	}

	if ((GestureYi[2] > GestureYi[1]) && (GestureYi[2] > GestureYi[0])) {
		printf("J");
	}
	else if ((GestureYi[1] > GestureYi[0]) && (GestureYi[1] >= GestureYi[2])) {
		printf("C");
	}
	else {
		printf("B");
	}
	return 0;
}
