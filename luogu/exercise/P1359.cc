#include <cstring>
#include <iostream>
using namespace std;
int a[201][201];
int egde(int u, int v, int x) { a[u][v] = x; }
int main() {
  int n;
  scanf("%d", &n);
  memset(a, 0x3f, sizeof(a));
  for (int i = 1; i <= n; i++) //边的创建
    for (int j = i; j <= n; j++) {
      if (i == j)
        a[i][j] = 0;
      else {
        int x;
        cin >> x;
        egde(i, j, x);
      }
    }
  for (int k = 1; k <= n; k++) // floyd
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) {
        a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
      }
  printf("%d", a[1][n]);
  return 0;
}