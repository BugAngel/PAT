#include <cstdio>

using namespace std;

const int N = 100010;
bool p[N] = {false};
int prime[N],pNum=0;

void searchPrime(int n)
{
	for (int i = 2; i <= n; i++)
	{
		if (p[i] == false)
		{
			prime[pNum++] = i;
			for (int j = i + i; j <= n; j += i)
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

	int n;
	int count = 0;
	scanf("%d", &n);
	searchPrime(n);
	for (int i = 1; i < pNum; i++)
	{
		if (prime[i] - prime[i - 1] == 2)
		{
			count++;
		}
	}
	printf("%d\n", count);
	return 0;
}

