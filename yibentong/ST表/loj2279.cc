#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 5e4 + 10;
int st[maxn][20], n, m;
int Logn[maxn];

struct year {
  int y, v;
} q[maxn];

inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}

int _find(int year) {
  int l = 1, r = n + 1;
  while (r - l > 1) {
    int mid = (r + l) / 2;
    if (q[mid].y > year)
      r = mid;
    else
      l = mid;
  }
  if (q[l].y == year)
    return l;
  return -1;
}

inline void stinit() {
  for (int i = 1; i <= n; i++)
    q[i].y = read(), q[i].v = read(), st[i][0] = q[i].v;
  for (int j = 1; j <= 19; j++)
    for (int i = 1; i + (1 << j) - 1 <= n; i++)
      st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}

inline int query(int l, int r) {
  int k = 0;
  while (1 << (k + 1) <= r - l + 1)
    k++;
  return max(st[l][k], st[r - (1 << k) + 1][k]);
}

int main() {
  freopen("1.in", "r", stdin);
  n = read();
  stinit();
  int m = read();
  while (m--) {
    int f = 1;
    int y = read(), x = read();
    int a = _find(y), b = _find(x);
    if (a == -1 || b == -1)
      f = 0;
    else {
      int maxx = query(a + 1, b);
      if (q[b].v > q[a].v || maxx != q[b].v)
        f = -1;
      else if ((b - a) != (x - y))
        f = 0;
    }
    if (f == 1)
      printf("true");
    else if (f == 0)
      printf("maybe");
    else
      printf("false");
    puts("");
  }
  return 0;
}