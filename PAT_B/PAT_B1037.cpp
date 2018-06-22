#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int price, pay;
	int temp1, temp2, temp3;
	scanf("%d.%d.%d", &temp1, &temp2, &temp3);
	price = 29 * (17 * temp1 + temp2) + temp3;
	scanf("%d.%d.%d", &temp1, &temp2, &temp3);
	pay = 29 * (17 * temp1 + temp2) + temp3;
	int res = pay - price;

	if (res < 0) {
		printf("-");
		res = -res;
	}
	temp1 = res / (17 * 29);
	temp2 = res % (17 * 29) / 29;
	temp3= res % (17 * 29) % 29;
	printf("%d.%d.%d", temp1, temp2, temp3);
	return 0;
}
