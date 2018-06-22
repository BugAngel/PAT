#include <cstdio>

using namespace std;

const int N = 110000;

bool p[N] = { false };
int pNum = 0,prime[N];

void searchPrime()
{
	for (int i = 2; i < N; i++)
	{
		if (p[i] == false)
		{
			prime[pNum++] = i;
			for (int j = i + i; j < N; j+=i)
			{
				p[j] = true;
			}
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int m, n;
	scanf("%d%d", &m,&n);

	searchPrime();

	int count = 0;
	for (int i = m-1; i < n-1; i++)
	{
		if (count < 9)
		{
			printf("%d ", prime[i]);
			count++;
		}
		else
		{
			printf("%d\n", prime[i]);
			count=0;
		}
	}
	printf("%d\n", prime[n-1]);
	return 0;
}
