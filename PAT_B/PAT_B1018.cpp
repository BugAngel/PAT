#include <cstdio>
#include <cstring>
#include <cstdlib>

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);	
	char Jia, Yi;
	int ScoreJia[3] = { 0 }, ScoreYi[3] = { 0 };//甲乙胜平负的次数
	int GestureJia[3] = { 0 }, GestureYi[3] = { 0 };//甲乙每个手势获胜的次数,依次为布，锤子，剪刀，这样字典序由小到大排列

	for (int i = 0; i < n; i++) {
		getchar();//去掉\n
		scanf("%c %c", &Jia, &Yi);
		if (Jia == 'C'&&Yi == 'J') {//甲锤子，乙剪刀
			ScoreJia[0]++;//甲胜
			ScoreYi[2]++;//乙负
			GestureJia[1]++;
		}
		else if(Jia == 'C'&&Yi == 'B') { //甲锤子，乙布
			ScoreJia[2]++;//甲负
			ScoreYi[0]++;//乙胜
			GestureYi[0]++;
		}
		else if (Jia == 'J'&&Yi == 'B') {//甲剪刀，乙布
			ScoreJia[0]++;//甲胜
			ScoreYi[2]++;//乙负
			GestureJia[2]++;
		}
		else if (Jia == 'J'&&Yi == 'C') {//甲剪刀，乙锤子
			ScoreJia[2]++;//甲负
			ScoreYi[0]++;//乙胜
			GestureYi[1]++;
		}
		else if (Jia == 'B'&&Yi == 'J') {//甲布，乙剪刀
			ScoreJia[2]++;//甲负
			ScoreYi[0]++;//乙胜
			GestureYi[2]++;
		}
		else if (Jia == 'B'&&Yi == 'C') {//甲布，乙锤子
			ScoreJia[0]++;//甲胜
			ScoreYi[2]++;//乙负
			GestureJia[0]++;
		}
		else { //平局
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
