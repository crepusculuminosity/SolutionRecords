#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
struct edge {
  int u, v, w;
  bool operator<(const edge &x) const { return w < x.w; }
} es[200010];
int n, m;
int cnt, tot;
int fa[5010], rnk[5010];
int find(int x) {
  if (x == fa[x])
    return x;
  return fa[x] = find(fa[x]);
}
bool merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y)
    return 0;
  if (rnk[x] < rnk[y])
    fa[x] = y;
  else {
    fa[y] = x;
    if (rnk[x] == rnk[y])
      ++rnk[x];
  }
  return 1;
}

int mapping(string &str) {
  if (mp.count(str))
    return mp[str];
  else
    return mp[str] = ++cnt;
}

int main() {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  while (cin >> n >> m) {
    cnt = tot = 0;
    mp.clear();
    for (int i = 1; i <= n; i++)
      fa[i] = i, rnk[i] = 0;
    string str;
    cin >> str;
    for (int i = 1; i <= m; i++) {
      string a, b;
      int c;
      cin >> a >> b >> c;
      if (mapping(a) == mapping(b))
        continue;
      es[++tot] = edge{mapping(a), mapping(b), c};
    }
    sort(es + 1, es + 1 + tot);
    long long ans = 0;
    int num = 0;
    for (int i = 1; i <= tot; i++)
      if (merge(es[i].u, es[i].v))
        ans += 1LL * es[i].w, ++num;
    if (num == n - 1)
      cout << ans << '\n';
    else
      cout << "No!\n";
  }

  return 0;
}