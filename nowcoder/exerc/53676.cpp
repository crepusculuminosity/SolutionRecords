#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int sum[1005][1005];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  getchar();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int x = getchar() - '0';
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + x;
    }
    getchar();
  }
  int ans = 0;
  for (int i = k; i <= n; i++) {
    for (int j = k; j <= m; j++) {
      if (sum[i][j] - sum[i - k][j] - sum[i][j - k] + sum[i - k][j - k])
        ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}