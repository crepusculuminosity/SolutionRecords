#include <bits/stdc++.h>
using namespace std;
int f[30010];
int v[30], w[30];
int n, m;

inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9')
    ch = getchar();
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}

int main() {
  freopen("data.in", "r", stdin);
  // cin>>n>>m;
  n = read(), m = read();
  for (int i = 1; i <= m; i++)
    w[i] = read(), v[i] = read();

  /*for(int i=1;i<=m;i++) {
    for(int j=1;j<=n;j++) {
      dp[i][j]=dp[i - 1][j];
      if(j>=w[i]) dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]]+w[i]*v[i]);
    }
  }*/

  for (int i = 1; i <= m; i++) {
    for (int j = n; j >= w[i]; j--) {
      f[j] = max(f[j], f[j - w[i]] + v[i] * w[i]);
    }
  }
  printf("%d", f[n]);
  return 0;
}