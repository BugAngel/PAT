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

map<string, bool> flag;
string zhuanFa[1005];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int m, n, s;//ת���������н��������һ���н����
	int count = 0;//������

	scanf("%d%d%d", &m, &n, &s);
	for (int i = 0; i < m; i++)
	{
		cin >> zhuanFa[i];
		flag[zhuanFa[i]] = false;
	}
	for (int i = s - 1; i < m; i += n)
	{
		if (flag[zhuanFa[i]] == false)//û�й���
		{
			count++;
			flag[zhuanFa[i]] = true;
			cout << zhuanFa[i] << endl;
		}
		else//�Ѿ��й�����˳��ȡ��һλ
		{
			while (i < m)
			{
				i++;
				if (flag[zhuanFa[i]] == false)
				{
					count++;
					flag[zhuanFa[i]] = true;
					cout << zhuanFa[i] << endl;
					break;
				}
			}
		}
	}
	if (count == 0)
	{
		cout << "Keep going...";
	}
	return 0;
}

