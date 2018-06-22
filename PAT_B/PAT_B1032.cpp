#include <cstdio>
#include <cstring>
#include <cstdlib>

#define MAXN 100005

int main() {

	int n;
	int School[MAXN];
	int tempID, tempScore;
	int MaxId, MaxScore = -1;

	memset(School,0,sizeof(School));

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &tempID, &tempScore);
		School[tempID] += tempScore;
		if (School[tempID] > MaxScore) {
			MaxId = tempID;
			MaxScore = School[tempID];
		}
	}
	
	printf("%d %d", MaxId, MaxScore);
	return 0;
}

