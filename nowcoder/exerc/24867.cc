#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 5e4 + 10;

struct cow {
  int l, r;
  bool operator<(const cow &x) const { return r < x.r; }
} a[maxn];

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
  // freopen("data.in", "r", stdin);
  int n = read();
  for (int i = 1; i <= n; i++)
    a[i].l = read(), a[i].r = read();
  sort(a + 1, a + 1 + n);
  int ans = 1;
  int now = 1;
  for (int i = 2; i <= n; i++)
    if (a[i].l >= a[now].r)
      now = i, ++ans;
  printf("%d", ans);
  return 0;
}