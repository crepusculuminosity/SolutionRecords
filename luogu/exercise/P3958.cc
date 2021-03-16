#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll maxn = 1010;
ll n, h, r;
bool f;
int vis[maxn];
struct node {
  ll x, y, z;
  bool operator<(const node &x) const { return z < x.z; }
} q[maxn];

ull dis(const node &a, const node &b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) +
         (a.z - b.z) * (a.z - b.z);
}

void dfs(int p) {
  if (q[p].z + r >= h) {
    f = 1;
    return;
  }
  vis[p] = 1;
  for (int i = p + 1; i <= n; i++)
    if (dis(q[p], q[i]) <= (ull)4 * r * r && vis[i] == 0)
      dfs(i);
}

template <typename T> inline void read(T &x) {
  x = 0;
  T f = 1;
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
  x *= f;
}

int main() {
  // freopen("data.in", "r", stdin);
  int _;
  read(_);
  // scanf("%d", &_);
  while (_--) {
    memset(vis, 0, sizeof(vis));
    f = 0;
    // scanf("%lld%lld%lld", &n, &h, &r);
    read(n), read(h), read(r);
    for (int i = 1; i <= n; i++)
      // scanf("%lld%lld%lld", &q[i].x, &q[i].y, &q[i].z);
      read(q[i].x), read(q[i].y), read(q[i].z);
    sort(q + 1, q + 1 + n);
    for (int i = 1; i <= n; i++) {
      if (q[i].z - r <= 0)
        dfs(i);
      if (f == 1)
        break;
    }
    if (f)
      puts("Yes");
    else
      puts("No");
  }
  return 0;
}