#include <bits/stdc++.h>
using namespace std;
#define lb(x) ((x) & (-x))
int n, h;
constexpr int maxn = 3e4 + 10;
int vis[maxn], ans;
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

struct quest {
  int b, e, t;
  bool operator<(const quest &x) const {
    if (e == x.e)
      return b < x.b;
    return e < x.e;
  }
} q[5010];

int main() {
  n = read(), h = read();
  for (int i = 1; i <= h; i++)
    q[i].b = read(), q[i].e = read(), q[i].t = read();
  sort(q + 1, q + 1 + h);

  for (int i = 1; i <= h; i++) {
    int num = query(q[i].e) - query(q[i].b - 1);
    if (num >= q[i].t)
      continue;
    for (int j = q[i].e; j >= q[i].b; j--) {
      if (vis[j] == 0) {
        vis[j] = 1, ans++, num++;
        update(j, 1);
        if (num == q[i].t)
          break;
      }
    }
  }
  printf("%d", ans);
  return 0;
}