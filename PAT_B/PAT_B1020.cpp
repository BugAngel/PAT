#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>

using namespace std;

struct node {
	double store;//���
	double sell;//�ۼ�
	double profit;//����
}cake[1010];

bool cmp( node a,  node b) {
	return a.profit > b.profit;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
 
	int n, d;	
	double maxProfit = 0.0;
	scanf("%d %d", &n, &d);
	double ShengYu = (double)d;
	for (int i = 0; i < n; i++) {
		scanf("%lf", &cake[i].store);//������
	}
	for (int i = 0; i < n; i++) {
		scanf("%lf", &cake[i].sell);//�����ۼ�
		cake[i].profit = cake[i].sell / cake[i].store;//���뵥��
	}
	sort(cake, cake + n, cmp);//����
	
	for (int i = 0; i < n && ShengYu>0.0; i++) {
		if (ShengYu > cake[i].store) {//ʣ�ıȿ���
			maxProfit += cake[i].sell;
			ShengYu -= cake[i].store;
		}
		else {
			maxProfit += (cake[i].profit*ShengYu);
			break;
		}
	}

	printf("%.2f", maxProfit);
	return 0;
}
