#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 100010;

struct NODE
{
	int address;
	int data;
	int next;
	int order;//顺序
	NODE()
	{
		order = maxn;
	}
}node[maxn];

bool cmp(struct NODE a, struct NODE b)
{
	return a.order < b.order;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int head, n, k;
	scanf("%d%d%d", &head, &n, &k);

	for (int i = 0; i < n; i++)
	{
		int address;
		scanf("%d", &address);
		scanf("%d%d", &node[address].data, &node[address].next);
		node[address].address = address;
	}

	//按结点顺序从零开始排队
	int address = head;
	int count = 1;
	for (; address!=-1; count++)
	{
		node[address].order = count;
		address = node[address].next;
	}
	sort(node, node + maxn, cmp);
	count--;//结点数
	int group = count / k;//需要反转的组数
	for (int i = 0; i < group; i++)
	{
		int tempData,tempAddress;
		for (int j = k * i; j < k*i+k/2; j++)
		{
			tempData = node[k*(i + 1) - (j-k*i) -1].data;
			tempAddress= node[k*(i + 1) - (j - k * i) - 1].address;

			node[k*(i + 1) - (j - k * i) - 1].data = node[j].data;
			node[k*(i + 1) - (j - k * i) - 1].address = node[j].address;

			node[j].data = tempData;
			node[j].address = tempAddress;
		}
	}
	for (int i = 0; i < count-1; i++)
	{
		node[i].next = node[i + 1].address;
	}
	for (int i = 0; i < count; i++)
	{
		if (node[i].next != -1)
		{
			printf("%05d %d %05d\n", node[i].address, node[i].data, node[i].next);
		}
		else
		{
			printf("%05d %d -1\n", node[i].address, node[i].data);
		}
		
	}
	return 0;
}

