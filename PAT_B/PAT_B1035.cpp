#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;
const int N = 105;
int origin[N], tempOri[N], changed[N];
int n;//Ԫ�ظ���

bool isSame(int A[], int B[])//�ж�����A������B�Ƿ���ͬ
{
  for (int i = 0; i < n; i++)
  {
    if (A[i] != B[i])
      return false;
  }
  return true;
}

void showArray(int A[])//�������
{
  for (int i = 0; i < n-1; i++)
  {
    printf("%d ", A[i]);
  }
  printf("%d\n", A[n - 1]);
}

bool insertSort()//��������
{
  bool flag = false;//��¼�Ƿ���������м䲽����changed������ͬ
  for(int i=1;i<n;i++)//����n-1������
  {
    if (i != 1 && isSame(tempOri, changed))
    {
      flag = true;//�м䲽����Ŀ����ͬ���Ҳ��ǳ�ʼ����
    }
    //����Ϊ���벿��
    int temp = tempOri[i], j = i;
    while (j > 0 && tempOri[j - 1] > temp)
    {
      tempOri[j] = tempOri[j - 1];
      j--;
    }
    tempOri[j] = temp;
    if (flag == true)
    {
      return true;//���flagΪtrue,˵���Ѿ��ﵽĿ�����飬����true;
    }
  }
  return false;//�ﲻ��Ŀ�����飬����false
}

void mergeSort()//�鲢����
{
  bool flag = false;//��¼�Ƿ���������м䲽����changed������ͬ
  //����Ϊ�鲢���򲿷�
  for (int step = 2; step / 2 <= n; step *= 2)
  {
    if (step != 2 && isSame(tempOri, changed))
    {
      flag = true;//�м䲽����Ŀ����ͬ���Ҳ��ǳ�ʼ����
    }
    for (int i = 0; i < n; i += step)
    {
      sort(tempOri + i, tempOri + min(i + step, n));
    }
    if (flag == true)//�ѵ���Ŀ�����飬���tempOri����
    {
      showArray(tempOri);
      return;
    }
  }
}

int main()
{
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);

  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &origin[i]);
    tempOri[i] = origin[i];
  }
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &changed[i]);
  }
  if (insertSort())
  {
    printf("Insertion Sort\n");
    showArray(tempOri);
  }
  else
  {
    printf("Merge Sort\n");
    for (int i = 0; i < n; i++)
    {
      tempOri[i] = origin[i];
    }
    mergeSort();
  }
  return 0;
}
