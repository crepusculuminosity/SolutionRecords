#include <bits/stdc++.h>
using namespace std;
int n, p = 1, a[1050][1050];
void di(int x, int l, int q) // x为正方形边长，l、q分别为递归正方形的横纵坐标
{
  if (x == 2) //递归边界
  {
    a[l][q] = 0;
    return;
  }
  for (int i = l; i <= l + x / 2 - 1; i++)
    for (int j = q; j <= q + x / 2 - 1; j++)
      a[i][j] = 0; //将左上方的正方形清零
  di(x / 2, l + x / 2, q);
  di(x / 2, l + x / 2, q + x / 2);
  di(x / 2, l, q + x / 2); //此处是递归剩余的三个正方形
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    p *= 2; //计算正方形的边长
  for (int i = 1; i <= p; i++)
    for (int j = 1; j <= p; j++)
      a[i][j] = 1; //将a数组先赋值为1
  di(p, 1, 1);     //开始递归
  for (int i = 1; i <= p; i++) {
    for (int j = 1; j <= p - 1; j++)
      cout << a[i][j] << " ";
    cout << a[i][p] << endl; //输出，此处可以避免输出行尾空格
  }
  return 0;
}
