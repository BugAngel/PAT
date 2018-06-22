#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

const int maxn = 100010;

struct NODE
{
	int data;
	int next;
}node[maxn], newNode[maxn];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int head, n, k;//�� 1 �����ĵ�ַ;����ܸ���;������K
	int newHead = -2;//�������ͷ���
	int count = 0;//����һ���ж��ٸ����
	int newCount = 0;//�½���������˶��ٸ����
	scanf("%d%d%d", &head, &n, &k);
	for (int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d", &temp);
		scanf("%d%d", &node[temp].data, &node[temp].next);
	}

	for (int i = head; i != -1; i = node[i].next)
	{
		count++;
	}

	int last;//��ǰ���ǰһ�����ĵ�ַ
	for (int i = head; i != -1; i = node[i].next)//����
	{
		if (node[i].data < 0)
		{
			if (newHead == -2)
			{
				newHead = i;
				newNode[i].data = node[i].data;
				newNode[i].next = node[i].next;
				last = i;//����last
				newCount++;
				if (newCount == count)
				{
					newNode[i].next = -1;
					break;
				}
			}
			else
			{
				newNode[i].data = node[i].data;
				newNode[last].next = i;
				newNode[i].next = node[i].next;
				last = i;//����last
				newCount++;
				if (newCount == count)
				{
					newNode[i].next = -1;
					break;
				}
			}
		}
	}

	for (int i = head; i != -1; i = node[i].next)//[0,K]
	{
		if (node[i].data >= 0 && node[i].data <= k)
		{
			if (newHead == -2)
			{
				newHead = i;
				newNode[i].data = node[i].data;
				newNode[i].next = node[i].next;
				last = i;//����last
				newCount++;
				if (newCount == count)
				{
					newNode[i].next = -1;
					break;
				}
			}
			else
			{
				newNode[i].data = node[i].data;
				newNode[last].next = i;
				newNode[i].next = node[i].next;
				last = i;//����last
				newCount++;
				if (newCount == count)
				{
					newNode[i].next = -1;
					break;
				}
			}
		}
	}

	for (int i = head; i != -1; i = node[i].next)//>k
	{
		if (node[i].data > k)
		{
			if (newHead == -2)
			{
				newHead = i;
				newNode[i].data = node[i].data;
				newNode[i].next = node[i].next;
				last = i;//����last
				newCount++;
				if (newCount == count)
				{
					newNode[i].next = -1;
					break;
				}
			}
			else
			{
				newNode[i].data = node[i].data;
				newNode[last].next = i;
				newNode[i].next = node[i].next;
				last = i;//����last
				newCount++;
				if (newCount == count)
				{
					newNode[i].next = -1;
					break;
				}
			}
		}
	}

	int i;
	for (i = newHead; newNode[i].next != -1; i = newNode[i].next)
	{
		printf("%05d %d %05d\n", i, newNode[i].data, newNode[i].next);
	}
	printf("%05d %d -1\n", i, newNode[i].data);
	return 0;
}

