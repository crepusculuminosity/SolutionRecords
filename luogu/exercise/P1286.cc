#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q = 1, sum = 0;
  int a[105], b[105], diff[15];
  int vis[15][15];

  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n * (n - 1) / 2; i++)
      scanf("%d", &a[i]);
    sort(a + 1, a + n * (n - 1) / 2 + 1);
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        vis[i][j] = a[q++];
        sum += vis[i][j];
      }
    }

    if (sum % (n - 1))
      printf("Impossible\n");
    else {
      for (int i = 1; i <= n - 2; i++) {
        diff[i] = vis[i][n] - vis[i + 1][n];
        b[i] = (vis[i][i + 1] + diff[i]) / 2;
        b[i + 1] = (vis[i][i + 1] - diff[i]) / 2;
      }
      b[n] = vis[1][n] - b[1];

      for (int i = 1; i <= n; i++) {
        printf("%d ", b[i]);
      }
      printf("\n");
    }
  }
  return 0;
}