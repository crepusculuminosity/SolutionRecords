#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 5050;
struct node {
  int x, y;
} q[110];
struct edge {
  int u, v;
  double w;
  bool operator<(const edge &x) const { return w < x.w; }
} es[maxn];
int n, cnt, fa[110], rnk[110];
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
double kruskal() {
  double res = 0.0;
  int d = 0;
  for (int i = 1; i <= cnt; i++)
    if (merge(es[i].u, es[i].v))
      res += es[i].w, ++d;
  if (d == n - 1)
    return res;
  return -1.0;
}
int main() {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _;
  cin >> _;
  while (_--) {
    cin >> n;
    for (int i = 1; i <= n; i++)
      fa[i] = i, rnk[i] = 0;
    for (int i = 1; i <= n; i++)
      cin >> q[i].x >> q[i].y;
    cnt = 0;
    for (int i = 1; i <= n; i++)
      for (int j = i + 1; j <= n; j++) {
        int dis = (q[i].x - q[j].x) * (q[i].x - q[j].x) +
                  (q[i].y - q[j].y) * (q[i].y - q[j].y);
        if (dis >= 100 && dis <= 1000000)
          es[++cnt] = edge{i, j, 100 * sqrt(dis)};
      }
    sort(es + 1, es + 1 + cnt);
    double res = kruskal();
    if (res == -1.0)
      cout << "oh!\n";
    else
      cout << fixed << setprecision(1) << res << '\n';
  }
  return 0;
}
