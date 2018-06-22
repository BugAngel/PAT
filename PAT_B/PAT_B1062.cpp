#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

const int maxn = 100010;

int gcd(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return gcd(b, a%b);
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n1, m1, n2, m2, k;
	double num1, num2;
	scanf("%d/%d %d/%d %d", &n1, &m1, &n2, &m2, &k);
	num1 = 1.0*n1 / m1;
	num2 = 1.0*n2 / m2;
	if (num1 > num2)
	{
		double t;
		t = num1;
		num1 = num2;
		num2 = t;
	}
	int count = 0;
	for (int i = 1; 1.0*i / k < num2; i++)
	{
		if (1.0*i / k > num1 && 1.0*i / k < num2 && gcd(i, k) == 1)
		{
			if (count == 0)
			{
				printf("%d/%d", i, k);
				count = 1;
			}
			else
			{
				printf(" %d/%d", i, k);
			}
		}
	}
	printf("\n");
	return 0;
}