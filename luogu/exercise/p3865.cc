#include <bits/stdc++.h>
using namespace std;
int n, m;
constexpr int maxn = 1e5 + 10;
int a[maxn], d[maxn][21];
int Logn[maxn + 1];

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

inline void stinit() {
  for (int i = 1; i <= n; i++)
    d[i][0] = read();
  for (int j = 1; j <= 21; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++)
      d[i][j] = max(d[i][j - 1], d[i + (1 << (j - 1))][j - 1]);
  }
}

inline void pre() {
  Logn[1] = 0, Logn[2] = 1;
  for (int i = 3; i < maxn; i++)
    Logn[i] = Logn[i / 2] + 1;
}

inline int query(int l, int r) {
  // int k = 0;
  // while((1<<(k+1)<=r-l+1)) k++;
  int k = Logn[r - l + 1];
  return max(d[l][k], d[r - (1 << k) + 1][k]);
}

int main() {
  // freopen("data.in", "r", stdin);
  n = read(), m = read();
  pre();
  stinit();
  while (m--) {
    int l = read(), r = read();
    printf("%d\n", query(l, r));
  }
  // system("pause");
  return 0;
}
