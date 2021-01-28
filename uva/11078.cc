#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int a[MAXN];
int dp[MAXN];
int n;

inline int read() {
  int x = 0, f = 1; //
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}

int main() {
  // freopen("data.in","r",stdin);
  int t = read();
  while (t--) {
    memset(a, 0, sizeof(a));
    // memset(dp,0,sizeof(dp));
    int n = read();
    for (int i = 0; i < n; i++)
      a[i] = read();
    int max1 = a[0];
    int maxn = a[0] - a[1];
    for (int j = 2; j <= n - 1; j++) {
      max1 = max(max1, a[j - 1]);
      maxn = max(maxn, max1 - a[j]);
    }
    printf("%d\n", maxn);
  }
  return 0;
}