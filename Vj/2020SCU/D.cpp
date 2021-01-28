#include <bits/stdc++.h>
using namespace std;
int a[100005], dp[100005];
int m;

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

int temp1, temp2;
int lis() {
  int i, j, temp;
  temp1 = 1;
  for (i = 1; i <= m; i++) {
    dp[i] = 1;
    for (j = 1; j < i; j++) {
      if (a[j] <= a[i] && dp[j] + 1 > dp[i]) {
        dp[i] = dp[j] + 1;
      }
    }
    if (dp[i] > temp1) {
      temp1 = dp[i];
    }
  }
  return temp;
}

int main() {
  int q = read();
  while (q--) {
    m = read();
    for (int i = 1; i <= m; i++)
      a[i] = read();
    int ans = lis();
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= m; i++)
      a[i] = -a[i];
    ans = max(ans, lis());
    if (ans + 1 < m)
      printf("NO\n");
    else
      printf("YES\n");
  }
  return 0;
}