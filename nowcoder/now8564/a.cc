#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
int a[MAXN];
int m, n;
typedef long long ll;

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

struct Base {
  int d, v;
  bool operator<(const Base a) const { return v > a.v; }
} base[MAXN];

ll ans;

int main() {
  n = read();
  m = read();
  for (int i = 1; i <= n; i++)
    a[i] = read();
  for (int i = 1; i <= m; i++)
    base[i].d = read();
  for (int i = 1; i <= m; i++)
    base[i].v = read();

  // sort(a+1,a+n+1,cmp);
  sort(base + 1, base + m + 1);
  int mx = 0, p = 1;
  for (int i = 1; i <= n; i++) {
    while (a[i] > base[p].d && p <= m) {
      mx = max(base[p].v, mx);
      p++;
    }
    ans += mx;
  }
  cout << ans << endl;

  return 0;
}
