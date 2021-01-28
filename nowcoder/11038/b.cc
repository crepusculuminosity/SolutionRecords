#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 8e5 + 10;

struct nation {
  int val, num;
  bool operator<(const nation &x) const { return val > x.val; }
} q[MAXN];

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
  int n = read();
  for (int i = 1; i <= n; i++) {
    q[i].val = read(), q[i].num = i;
  }
  int ans = 1;
  sort(q + 1, q + 1 + n);
  for (int i = 1; i <= n - 1; i++) {
    if (q[i].num > q[i + 1].num)
      ans++;
  }
  printf("%d", ans);
  return 0;
}