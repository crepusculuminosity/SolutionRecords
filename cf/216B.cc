#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 110;
int fa[maxn * 2], rnk[maxn * 2];

void init() {
  for (int i = 1; i < maxn * 2; i++)
    fa[i] = i;
}
int n, m;
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
int main() {

  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  init();
  cin >> n >> m;
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    if (find(u) == find(v) || find(u + n) == find(v + n))
      ++ans;
    else
      merge(u, v + n), merge(u + n, v);
  }
  cout << ans;
  return 0;
}