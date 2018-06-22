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
int n;//元素个数

bool isSame(int A[], int B[])//判断数组A和数组B是否相同
{
  for (int i = 0; i < n; i++)
  {
    if (A[i] != B[i])
      return false;
  }
  return true;
}

void showArray(int A[])//输出数组
{
  for (int i = 0; i < n-1; i++)
  {
    printf("%d ", A[i]);
  }
  printf("%d\n", A[n - 1]);
}

bool insertSort()//插入排序
{
  bool flag = false;//记录是否存在数组中间步骤与changed数组相同
  for(int i=1;i<n;i++)//进行n-1趟排序
  {
    if (i != 1 && isSame(tempOri, changed))
    {
      flag = true;//中间步骤与目标相同，且不是初始序列
    }
    //以下为插入部分
    int temp = tempOri[i], j = i;
    while (j > 0 && tempOri[j - 1] > temp)
    {
      tempOri[j] = tempOri[j - 1];
      j--;
    }
    tempOri[j] = temp;
    if (flag == true)
    {
      return true;//如果flag为true,说明已经达到目标数组，返回true;
    }
  }
  return false;//达不到目标数组，返回false
}

void mergeSort()//归并排序
{
  bool flag = false;//记录是否存在数组中间步骤与changed数组相同
  //以下为归并排序部分
  for (int step = 2; step / 2 <= n; step *= 2)
  {
    if (step != 2 && isSame(tempOri, changed))
    {
      flag = true;//中间步骤与目标相同，且不是初始序列
    }
    for (int i = 0; i < n; i += step)
    {
      sort(tempOri + i, tempOri + min(i + step, n));
    }
    if (flag == true)//已到达目标数组，输出tempOri数组
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
