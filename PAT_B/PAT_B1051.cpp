#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

const int maxn = 10010;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	double R1, P1, R2, P2;
	scanf("%lf%lf%lf%lf", &R1, &P1, &R2, &P2);
	double A, B;
	A = R1 * R2*(cos(P1)*cos(P2) - sin(P1)*sin(P2));
	B = R1 * R2*(cos(P2)*sin(P1) + cos(P1)*sin(P2));

	if ((fabs(A)<0.01)&& (fabs(B)<0.01))
	{
		printf("0\n");
	}
	else if (fabs(A)<0.01 && B>0)
	{
		printf("0.00+%.2fi\n", B);
	}
	else if (fabs(A) < 0.01 && B < 0)
	{
		printf("0.00-%.2fi\n", -B);
	}
	else if (fabs(B)<0.01)
	{
		printf("%.2f+0.00i\n", A);
	}
	 else if (B > 0)
	{
		printf("%.2f+%.2fi\n", A, B);
	}
	else
	{
		printf("%.2f-%.2fi\n", A, -B);
	}
	return 0;
}
