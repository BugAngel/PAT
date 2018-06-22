#include <cstdio>

using namespace std;
struct nums
{
	long long FenZi;
	long long FenMu;
}num1, num2, Jia, Jian, Cheng, Chu;

long long Factor(long long a, long long b)//求最大公约数
{
	long long t;
	while (b != 0)
	{
		t = a % b;
		a = b;
		b = t;
	}
	return a;
}

void print(long long FenZi, long long FenMu)
{
	if (FenMu == 0)
	{
		printf("Inf");
	}
	else if (FenZi == 0)//检查是不是开始就是0
	{
		printf("0");
	}
	else
	{
		bool FuShuFlag = false;//false表示不是负数

		if (FenZi < 0 && FenMu < 0)
		{
			FenZi = -FenZi;
			FenMu = -FenMu;
		}
		else if (FenZi < 0)
		{
			printf("(-");
			FenZi = -FenZi;
			FuShuFlag = true;
		}
		else if (FenMu < 0)
		{
			printf("(-");
			FenMu = -FenMu;
			FuShuFlag = true;
		}

		//简化
		long long factor = Factor(FenZi, FenMu);
		FenZi /= factor;
		FenMu /= factor;

		if (FenZi >= FenMu)
		{
			long long GeWei = FenZi / FenMu;
			FenZi -= GeWei * FenMu;
			if (FenZi != 0)//检查换成带分数之后是不是0
			{
				printf("%lld %lld/%lld", GeWei, FenZi, FenMu);				
			}
			else
			{
				printf("%lld", GeWei);
			}
		}
		else
		{
			printf("%lld/%lld", FenZi, FenMu);
		}
		if (FuShuFlag)
		{
			printf(")");
		}
	}

}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%lld/%lld%lld/%lld", &num1.FenZi, &num1.FenMu, &num2.FenZi, &num2.FenMu);

	Jia.FenZi = num1.FenZi*num2.FenMu + num2.FenZi*num1.FenMu;
	Jia.FenMu = num1.FenMu*num2.FenMu;

	Jian.FenZi = num1.FenZi*num2.FenMu - num2.FenZi*num1.FenMu;
	Jian.FenMu = Jia.FenMu;

	Cheng.FenZi = num1.FenZi*num2.FenZi;
	Cheng.FenMu = Jia.FenMu;

	Chu.FenZi = num1.FenZi*num2.FenMu;
	Chu.FenMu = num2.FenZi*num1.FenMu;

	//加法
	print(num1.FenZi, num1.FenMu);
	printf(" + ");
	print(num2.FenZi, num2.FenMu);
	printf(" = ");
	print(Jia.FenZi, Jia.FenMu);
	printf("\n");

	//减法
	print(num1.FenZi, num1.FenMu);
	printf(" - ");
	print(num2.FenZi, num2.FenMu);
	printf(" = ");
	print(Jian.FenZi, Jian.FenMu);
	printf("\n");

	//乘法
	print(num1.FenZi, num1.FenMu);
	printf(" * ");
	print(num2.FenZi, num2.FenMu);
	printf(" = ");
	print(Cheng.FenZi, Cheng.FenMu);
	printf("\n");

	//除法
	print(num1.FenZi, num1.FenMu);
	printf(" / ");
	print(num2.FenZi, num2.FenMu);
	printf(" = ");
	print(Chu.FenZi, Chu.FenMu);
	printf("\n");
	return 0;
}
