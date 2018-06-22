#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 100010;

int origin[maxn];//���������
int leftMax[maxn];//ÿ���±��Ӧ�����������
int rightMin[maxn];//ÿ���±��Ӧ���ұ���С����
int result[maxn];//��������Ԫ����

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	int count = 0;//��¼�ж��ٿ�������Ԫ����
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &origin[i]);
	}

	leftMax[0] = 0;
	for (int i = 1; i < n; i++)
	{
		if (origin[i-1] > leftMax[i-1])
		{
			leftMax[i] = origin[i-1];
		}
		else
		{
			leftMax[i] = leftMax[i - 1];
		}
	}

	rightMin[n - 1] = 1000000010;
	for (int i = n - 2; i >= 0; i--)
	{
		if (origin[i+1] < rightMin[i + 1])
		{
			rightMin[i] = origin[i+1];
		}
		else
		{
			rightMin[i] = rightMin[i + 1];
		}
	}

	for (int i = 0; i < n; i++)
	{
		if ((origin[i] > leftMax[i]) && (origin[i] < rightMin[i]))
		{
			result[count++] = origin[i];
		}
	}
	sort(result, result + count);
	printf("%d\n", count);
	if (count != 0)
	{
		for (int i = 0; i < count - 1; i++)
		{
			printf("%d ", result[i]);
		}
		printf("%d\n", result[count - 1]);
	}
	else
	{
		printf("\n");
	}
	return 0;
}
