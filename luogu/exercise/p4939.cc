#define lb(x) ((x) & (-x))
#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e7 + 1000;
int n, m;
int tr[maxn];
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

inline void update(int x, int k) {
  while (x <= n) {
    tr[x] += k;
    x += lb(x);
  }
}

inline int query(int x) {
  int res = 0;
  while (x) {
    res += tr[x];
    x -= lb(x);
  }
  return res;
}

int main() {
  n = read(), m = read();
  while (m--) {
    int op = read();
    if (op == 0) {
      int a = read(), b = read();
      update(a, 1);
      update(b + 1, -1);
    } else {
      int x = read();
      printf("%d\n", query(x));
    }
  }
  return 0;
}