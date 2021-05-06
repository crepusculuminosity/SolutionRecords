#include <bits/stdc++.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>
#define lb(x) ((x) & (-x))
using namespace std;
constexpr int maxn = 1e6 + 10;
using ll = long long;
vector<int> G[maxn];
int a[maxn * 2][2];
int vis[maxn], val[maxn];
int cnt, n, m, k;
ll tr[maxn * 2];
int rec[maxn][2];
char *p;

template <typename T, typename... Ts> inline void read(T &x, Ts &...y) {
  x = 0;
  T f = 1;
  char ch = *p++;
  while (ch < '0' || ch > '9') {
    if (ch == '-')
      f = -1;
  }
  while (ch >= '0' && ch <= '9')
    x = x * 10 + ch - 48, ch = *p++;
  x *= f;
  if constexpr ((bool)sizeof...(y))
    read(y...);
}

void dfs(int x) {
  vis[x] = 1;
  a[++cnt][0] = x;
  a[cnt][1] = val[x];
  rec[x][0] = cnt;
  for (auto v : G[x]) {
    if (!vis[v])
      dfs(v);
  }
  a[++cnt][0] = x;
  rec[x][1] = cnt;
  a[cnt][1] = val[x];
}

void bitinit() {
  for (int i = 1; i <= 2 * n; i++) {
    tr[i] += a[i][1];
    int j = i + lb(i);
    if (j <= 2 * n)
      tr[j] += tr[i];
  }
}

void update(int x, int k) {
  int s = rec[x][0], t = rec[x][1];
  while (t <= 2 * n) {
    tr[t] += k;
    t += lb(t);
  }
  while (s <= 2 * n) {
    tr[s] += k;
    s += lb(s);
  }
}

ll query(ll x) {
  int l = rec[x][0], r = rec[x][1];
  ll r1 = 0, r2 = 0;
  --l;
  while (l) {
    r1 += tr[l];
    l -= lb(l);
  }
  while (r) {
    r2 += tr[r];
    r -= lb(r);
  }
  return r2 - r1;
}

int main() {
  p = (char *)mmap(NULL, lseek(0, 0, SEEK_END), PROT_READ, MAP_PRIVATE, 0, 0);
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  // cin >> n >> m >> k;
  read(n, m, k);
  for (int i = 1; i <= n; i++)
    // cin >> val[i];
    read(val[i]);
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    // cin >> u >> v;
    read(u, v);
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  dfs(k);
  bitinit();
  while (m--) {
    int o;
    // cin >> o;
    read(o);
    if (o == 1) {
      int a, b;
      // cin >> a >> b;
      read(a, b);
      update(a, b);
    } else {
      int a;
      // cin >> a;
      read(a);
      cout << query(a) / 2 << '\n';
    }
  }
  return 0;
}